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
#include "extensions\ScriptCommands.h"
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
    template<eLocateCommand type, bool IS_3D, bool bStopped>
    static bool LocateCharCommand(CPed* pPed, CVector& posn, CVector& radius, bool bSphere);
    template<eLocateCommand type, bool IS_3D>
    static bool LocateCharCharCommand(CPed* pPed, CPed* pPed2, CVector& radius, bool bSphere);
};