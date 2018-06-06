#pragma once
#include "CTheZones.h"
#include "common.h"
#include "CGeneral.h"
#include "CPlayerPed.h"
#include "CEmergencyPed.h"
#include "CTaskSimple.h"
#include "CWorld.h"
#include "CPopulation.h"
#include "CStreaming.h"
#include "CCivilianPed.h"
#include "CTaskSimpleStandStill.h"
#include "CCarEnterExit.h"
#include "CTaskSimpleCarSetPedInAsDriver.h"
#include "CTaskSimpleCarSetPedInAsPassenger.h"
#include "CCarCtrl.h"
#include "CTimer.h"
#include "CPed.h"
#include "CVehicle.h"
#include "CCopPed.h"
#include "CRunningScript.h"
#include "CTheScripts.h"
#include "CTaskSimplePlayerOnFoot.h"
#include "CCheat.h"
#include "CCamera.h"
#include "C3dMarkers.h"
#include "CCheckpoints.h"
#include "CVector2D.h"
#include "CMessages.h"
#include "CMenuManager.h"
#include "CClock.h"
#include "CModelInfo.h"
#include "CTheCarGenerators.h"
#include "extensions/ScriptCommands.h"
#include "CUserDisplay.h"
#include "CRadar.h"

using namespace plugin;

enum eOnScreenTimer
{
    TIMER_UP,
    TIMER_DOWN
};

enum eCounterDisplay
{
    COUNTER_DISPLAY_NUMBER,
    COUNTER_DISPLAY_BAR
};

enum eLocateCommand
{
    LOCATE_ANY_MEANS,
    LOCATE_ON_FOOT,
    LOCATE_IN_CAR
};

class CStaticScript
{
public:
    static CRunningScript script;

    template <eLocateCommand type, bool IS_3D, bool bStopped>
    static bool LocateCharCommand(CPed* pPed, CVector& posn, CVector& radius, bool bSphere)
    {
        const float min_posn_x = posn.x - radius.x;
        const float min_posn_y = posn.y - radius.y;
        const float max_posn_x = posn.x + radius.x;
        const float max_posn_y = posn.y + radius.y;

        if (bSphere)
        {
            if (IS_3D)
                CTheScripts::HighlightImportantArea(0, min_posn_x, min_posn_y, max_posn_x, max_posn_y, posn.z);
            else
                CTheScripts::HighlightImportantArea(0, min_posn_x, min_posn_y, max_posn_x, max_posn_y, -100.0f);
        }

        if (CTheScripts::DbgFlag)
        {
            CTheScripts::DrawDebugCube(min_posn_x, min_posn_y, max_posn_x, max_posn_y);
        }

        if (bStopped)
        {
            if (!CTheScripts::IsPedStopped(pPed))
                return false;
        }

        CVector* PedPosn = nullptr;
        if (type == LOCATE_ANY_MEANS)
        {
            CVehicle* PedVeh = pPed->m_pVehicle;
            if (pPed->m_nPedFlags.bInVehicle && PedVeh)
                PedPosn = &PedVeh->GetPosition();
            else
                PedPosn = &pPed->GetPosition();
        }

        else if (type == LOCATE_ON_FOOT)
        {
            if (pPed->m_nPedFlags.bInVehicle) return false;
            PedPosn = &pPed->GetPosition();
        }

        else if (type == LOCATE_IN_CAR)
        {
            if (!pPed->m_nPedFlags.bInVehicle) return false;

            CVehicle* PedVeh = pPed->m_pVehicle;
            if (PedVeh)
                PedPosn = &PedVeh->GetPosition();
            else
                PedPosn = &pPed->GetPosition();
        }


        if (IS_3D)
        {
            if (!(min_posn_x < PedPosn->x)
                && !(min_posn_x == PedPosn->x)
                || max_posn_x < PedPosn->x
                || min_posn_y > PedPosn->y
                || max_posn_y < PedPosn->y
                || (posn.z - radius.z) > PedPosn->z
                || (radius.z + posn.z) < PedPosn->z)
                return false;
        }
        else
        {
            if (!(min_posn_x < PedPosn->x)
                && !(min_posn_x == PedPosn->x)
                || max_posn_x < PedPosn->x
                || min_posn_y > PedPosn->y
                || max_posn_y < PedPosn->y)
                return false;
        }
        return true;
    }

    template <eLocateCommand type, bool IS_3D>
    static bool LocateCharCharCommand(CPed* pPed, CPed* pPed2, CVector& radius, bool bSphere)
    {
        CVector* targPedPosn;
        CVehicle* targPedVeh = pPed2->m_pVehicle;
        if (pPed->m_nPedFlags.bInVehicle && targPedVeh)
            targPedPosn = &targPedVeh->GetPosition();
        else
            targPedPosn = &pPed2->GetPosition();
    
        const float min_targPedposn_x = targPedPosn->x - radius.x;
        const float min_targPedposn_y = targPedPosn->y - radius.y;
        const float max_targPedposn_x = targPedPosn->x + radius.x;
        const float max_targPedposn_y = targPedPosn->y + radius.y;
    
        if (bSphere)
        {
            if (IS_3D)
                CTheScripts::HighlightImportantArea(0, min_targPedposn_x, min_targPedposn_y,
                                                    max_targPedposn_x, max_targPedposn_y, targPedPosn->z);
            else
                CTheScripts::HighlightImportantArea(0, min_targPedposn_x, min_targPedposn_y,
                                                    max_targPedposn_x, max_targPedposn_y, -100.0f);
        }
    
        if (CTheScripts::DbgFlag)
            CTheScripts::DrawDebugCube(min_targPedposn_x, min_targPedposn_y, max_targPedposn_x, max_targPedposn_y);
    
        CVector* PedPosn = nullptr;
        if (type == LOCATE_ANY_MEANS)
        {
            CVehicle* PedVeh = pPed->m_pVehicle;
            if (pPed->m_nPedFlags.bInVehicle && PedVeh)
                PedPosn = &PedVeh->GetPosition();
            else
                PedPosn = &pPed->GetPosition();
        }
    
        else if (type == LOCATE_ON_FOOT)
        {
            if (pPed->m_nPedFlags.bInVehicle) return false;
            PedPosn = &pPed->GetPosition();
        }
    
        else if (type == LOCATE_IN_CAR)
        {
            if (!pPed->m_nPedFlags.bInVehicle) return false;
    
            CVehicle* PedVeh = pPed->m_pVehicle;
            if (PedVeh)
                PedPosn = &PedVeh->GetPosition();
            else
                PedPosn = &pPed->GetPosition();
        }
    
        if (IS_3D)
        {
            if (PedPosn->x < min_targPedposn_x
                || max_targPedposn_x < PedPosn->x
                || min_targPedposn_y > PedPosn->y
                || max_targPedposn_y < PedPosn->y
                || (targPedPosn->z - radius.z) > PedPosn->z
                || (targPedPosn->z + radius.z) < PedPosn->z)
                return false;
        }
        else
        {
            if (PedPosn->x < min_targPedposn_x
                || max_targPedposn_x < PedPosn->x
                || min_targPedposn_y > PedPosn->y
                || max_targPedposn_y < PedPosn->y)
                return false;
        }
    
        return true;
    }
};
