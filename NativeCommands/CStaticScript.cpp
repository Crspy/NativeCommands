#include "CStaticScript.h"

CRunningScript CStaticScript::script = []()
{
    memset(&script, 0, sizeof(CRunningScript));
    script.Init();
    strcpy(script.m_szName, "natives");
    script.m_bIsMission = false;
    script.m_bUseMissionCleanup = false;
    return script;
}();

template <eLocateCommand type, bool IS_3D, bool bStopped>
bool CStaticScript::LocateCharCommand(CPed* pPed, CVector& posn, CVector& radius, bool bSphere)
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
bool CStaticScript::LocateCharCharCommand(CPed* pPed, CPed* pPed2, CVector& radius, bool bSphere)
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
