#include "CommandsFrom200To299.h"


namespace Natives
{
    void LAUNCH_MISSION(unsigned int MissionLabel_LocalOffset)
    {
        CTheScripts::StartNewScript(
            reinterpret_cast<unsigned char*>(&CTheScripts::ScriptSpace[MissionLabel_LocalOffset]));
    }


    void MISSION_HAS_FINISHED()
    {
        //if (!this->m_bUseMissionCleanup)
        //{
        //    return;
        //}
        CTheScripts::MissionCleanUp.Process();
    }


    CVehicle* GET_CAR_CHAR_IS_IN(CPed* pPed)
    {
        if (pPed->m_nPedFlags.bInVehicle)
            return pPed->m_pVehicle;

        return nullptr;
    }


    bool IS_CHAR_IN_CAR(CPed* pPed, CVehicle* pVehicle)
    {
        return pPed->m_nPedFlags.bInVehicle && pPed->m_pVehicle == pVehicle;
    }


    bool IS_CHAR_IN_MODEL(CPed* pPed, int modelindex)
    {
        CVehicle* vehicle = pPed->m_pVehicle;
        if (pPed->m_nPedFlags.bInVehicle && vehicle)
        {
            if (vehicle->m_nModelIndex == modelindex) return true;
        }
        return false;
    }


    bool IS_CHAR_IN_ANY_CAR(CPed* pPed)
    {
        return pPed->m_nPedFlags.bInVehicle && pPed->m_pVehicle;
    }


    bool IS_BUTTON_PRESSED(unsigned short playerid, eButtonID buttonID)
    {
        return plugin::CallMethodAndReturnDynGlobal<short, CRunningScript *, unsigned short, unsigned short>
            (gaddrof(CRunningScript::GetPadState), nullptr, playerid, buttonID) && !CPad::GetPad(0)->JustOutOfFrontEnd;
    }


    short GET_PAD_STATE(unsigned short playerid, eButtonID buttonID)
    {
        return plugin::CallMethodAndReturnDynGlobal<short, CRunningScript *, unsigned short, unsigned short>
            (gaddrof(CRunningScript::GetPadState), nullptr, playerid, buttonID);
    }

    bool LOCATE_CHAR_ANY_MEANS_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_ANY_MEANS, false, false>(
            pPed, reinterpret_cast<CVector&>(posn), reinterpret_cast<CVector&>(radius), bSphere);
    }

    bool LOCATE_CHAR_ON_FOOT_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_ON_FOOT, false, false>(
            pPed, reinterpret_cast<CVector&>(posn), reinterpret_cast<CVector&>(radius), bSphere);
    }

    bool LOCATE_CHAR_IN_CAR_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_IN_CAR, false, false>(
            pPed, reinterpret_cast<CVector&>(posn), reinterpret_cast<CVector&>(radius), bSphere);
    }

    bool LOCATE_STOPPED_CHAR_ANY_MEANS_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_ANY_MEANS, false, true>(
            pPed, reinterpret_cast<CVector&>(posn), reinterpret_cast<CVector&>(radius), bSphere);
    }

    bool LOCATE_STOPPED_CHAR_ON_FOOT_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_ON_FOOT, false, true>(
            pPed, reinterpret_cast<CVector&>(posn), reinterpret_cast<CVector&>(radius), bSphere);
    }

    bool LOCATE_STOPPED_CHAR_IN_CAR_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_IN_CAR, false, true>(
            pPed, reinterpret_cast<CVector&>(posn), reinterpret_cast<CVector&>(radius), bSphere);
    }

    bool LOCATE_CHAR_ANY_MEANS_CHAR_2D(CPed* pPed, CPed* pTargetPed, CVector2D& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCharCommand<LOCATE_ANY_MEANS, false>(
            pPed, pTargetPed, reinterpret_cast<CVector&>(radius), bSphere);
    }

    bool LOCATE_CHAR_ON_FOOT_CHAR_2D(CPed* pPed, CPed* pTargetPed, CVector2D& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCharCommand<LOCATE_ON_FOOT, false>(pPed, pTargetPed, reinterpret_cast<CVector&>(radius), bSphere);
    }

    bool LOCATE_CHAR_IN_CAR_CHAR_2D(CPed* pPed, CPed* pTargetPed, CVector2D& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCharCommand<LOCATE_IN_CAR, false>(pPed, pTargetPed, reinterpret_cast<CVector&>(radius), bSphere);
    }

    bool LOCATE_CHAR_ANY_MEANS_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_ANY_MEANS, true, false>(pPed, posn, radius, bSphere);
    }

    bool LOCATE_CHAR_ON_FOOT_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_ON_FOOT, true, false>(pPed, posn, radius, bSphere);
    }

    bool LOCATE_CHAR_IN_CAR_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_IN_CAR, true, false>(pPed, posn, radius, bSphere);
    }


    bool LOCATE_STOPPED_CHAR_ANY_MEANS_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_ANY_MEANS, true, true>(pPed, posn, radius, bSphere);
    }

    bool LOCATE_STOPPED_CHAR_ON_FOOT_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_ON_FOOT, true, true>(pPed, posn, radius, bSphere);
    }

    bool LOCATE_STOPPED_CHAR_IN_CAR_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCommand<LOCATE_IN_CAR, true, true>(pPed, posn, radius, bSphere);
    }

    bool LOCATE_CHAR_ANY_MEANS_CHAR_3D(CPed* pPed, CPed* pTargetPed, CVector& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCharCommand<LOCATE_ANY_MEANS, true>(pPed, pTargetPed, radius, bSphere);
    }

    bool LOCATE_CHAR_ON_FOOT_CHAR_3D(CPed* pPed, CPed* pTargetPed, CVector& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCharCommand<LOCATE_ON_FOOT, true>(pPed, pTargetPed, radius, bSphere);
    }

    bool LOCATE_CHAR_IN_CAR_CHAR_3D(CPed* pPed, CPed* pTargetPed, CVector& radius, bool bSphere)
    {
        return CStaticScript::LocateCharCharCommand<LOCATE_IN_CAR, true>(pPed, pTargetPed, radius, bSphere);
    }

    CObject* CREATE_OBJECT(int modelIndex, CVector& posn, eObjectType objectType, bool bNoOffset)
    {
        if (modelIndex < 0)
            modelIndex = CTheScripts::UsedObjectArray[-modelIndex].dwModelIndex;

        CBaseModelInfo* modelinfo = CModelInfo::ms_modelInfoPtrs[modelIndex];
        modelinfo->m_nAlpha = 255;
        CObject* object = CObject::Create(modelIndex);
        object->m_nObjectType = objectType;
        if (!bNoOffset)
            posn.z += object->GetDistanceFromCentreOfMassToBaseOfModel();
        object->SetPosn(posn);
        object->SetOrientation(0.0f, 0.0f, 0.0f);
        RwObject* rwobject = object->m_pRwObject;
        if (rwobject)
        {
            CMatrixLink* matrixlink = object->m_matrix;
            RwMatrixTag* matrixtag = reinterpret_cast<RwMatrixTag *>(static_cast<char *>(rwobject->parent) + 16);
            if (matrixlink)
            {
                matrixlink->UpdateRW(matrixtag);
            }
            else
            {
                object->m_placement.UpdateRwMatrix(matrixtag);
            }
        }

        object->UpdateRwFrame();
        if (modelinfo->AsLodAtomicModelInfoPtr())
            object->SetupBigBuilding();

        CWorld::Add(object);
        return object;
    }

    void DELETE_OBJECT(CObject* pObject)
    {
        if (!pObject) return;
        CWorld::Remove(pObject);
        CWorld::RemoveReferencesToDeletedObject(pObject);
        //((void(__thiscall *)(CEntity *, char))GetVMT(pVehicle, 0))(pVehicle, 1); // virtual dtor
        operator_delete<CObject>(pObject);
    }

    void ADD_SCORE(int playerid, int amount)
    {
        CWorld::Players[playerid].m_nMoney += amount;
    }

    bool IS_SCORE_GREATER(int playerid, int amount)
    {
        return CWorld::Players[playerid].m_nMoney > amount;
    }

    int GET_PLAYER_SCORE(int playerid)
    {
        return CWorld::Players[playerid].m_nMoney;
    }

    void ALTER_WANTED_LEVEL(int playerid, int wantedLevel, bool bNoDrop)
    {
        if (bNoDrop)
            CWorld::Players[playerid].m_pPed->SetWantedLevelNoDrop(wantedLevel);
        else
            CWorld::Players[playerid].m_pPed->SetWantedLevel(wantedLevel);
    }

    bool IS_WANTED_LEVEL_GREATER(int playerid, unsigned int wantedlevel)
    {
        return FindPlayerWanted(playerid)->m_nWantedLevel > wantedlevel;
    }

    void CLEAR_WANTED_LEVEL(int playerid)
    {
        CWorld::Players[playerid].m_pPed->SetWantedLevel(0);
    }

    void ADD_AMMO_TO_CHAR(CPed* pPed, eWeaponType weapontype, int ammo)
    {
        pPed->GrantAmmo(weapontype, ammo);
    }

    bool IS_PLAYER_DEAD(int playerid)
    {
        return CWorld::Players[playerid].m_nPlayerState == PLAYERSTATE_HASDIED;
    }

    bool IS_CHAR_DEAD(CPed* pPed)
    {
        if (!pPed) return true;

        ePedState pedstate = pPed->m_nPedState;
        return pedstate == PEDSTATE_DEAD || pedstate == PEDSTATE_DIE || pedstate == PEDSTATE_DIE_BY_STEALTH;
    }

    bool IS_CAR_DEAD(CVehicle* pVehicle)
    {
        if (!pVehicle) return true;

        if (pVehicle->m_nStatus != STATUS_WRECKED)
            return pVehicle->m_nFlags.bIsDrowning;

        return true;
    }

    bool IS_PLAYER_PRESSING_HORN(int playerid)
    {
        if (CWorld::Players[playerid].m_pPed->m_nPedState != PEDSTATE_DRIVING) return false;
        return CPad::GetPad(playerid)->GetHorn();
    }

    CPed* CREATE_CHAR_IN_CAR(CVehicle* pVehicle, ePedType pedtype, int modelindex, bool scriptEntity)
    {
        CPed* pPed;

        plugin::CallMethodDynGlobal<CRunningScript *, ePedType, int *>
            (gaddrof(CRunningScript::GetCorrectPedModelIndexForEmergencyServiceType), nullptr, pedtype, &modelindex);

        if (pedtype == PED_TYPE_COP)
        {
            pPed = new CCopPed(static_cast<eCopType>(modelindex));
            //pPed = operator_new<CCopPed, int>(modelindex);
        }
        else if (pedtype == PED_TYPE_MEDIC || pedtype == PED_TYPE_FIREMAN)
        {
            pPed = new CEmergencyPed(pedtype, modelindex);
            //pPed = operator_new<CEmergencyPed, ePedType,int>(pedtype, modelindex);
        }
        else
        {
            pPed = new CCivilianPed(pedtype, modelindex);
            //pPed = operator_new<CCivilianPed, ePedType,int>(pedtype, modelindex);
        }

        pPed->m_nCreatedBy = scriptEntity ? 2 : 1;
        pPed->m_nPedFlags.bKnockedOffBike = false;
        CTaskSimpleCarSetPedInAsDriver TaskSimpleCarSetPedInAsDriver(pVehicle, nullptr);
        TaskSimpleCarSetPedInAsDriver.m_bWarpingInToCar = true;
        TaskSimpleCarSetPedInAsDriver.ProcessPed(pPed);
        CWorld::Add(pPed);
        return pPed;
    }
}
