#include "CommandsFrom100To199.h"

namespace Natives
{
    
    CPed* CREATE_CHAR(ePedType pedtype, int modelindex, CVector& posn, bool scriptEntity)
    {
        CPed *pPed;

        plugin::CallMethodDynGlobal<CRunningScript *, ePedType, int *>
            (gaddrof(CRunningScript::GetCorrectPedModelIndexForEmergencyServiceType), nullptr, pedtype, &modelindex);


        if (pedtype == PED_TYPE_COP)
        {
            pPed = new CCopPed((eCopType)modelindex);
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

        if (scriptEntity)
        {
            pPed->m_nCreatedBy = 2;
            ++CPopulation::ms_nTotalMissionPeds;
        }
        else
            pPed->m_nCreatedBy = 1;

        pPed->m_nPedFlags.bKnockedOffBike = false;

        if (pPed)
        {
            pPed->SetPosn(posn);
            pPed->SetOrientation(0.0f, 0.0f, 0.0f);
            CWorld::Add(pPed);
            pPed->PositionAnyPedOutOfCollision();
            pPed->m_pIntelligence->m_TaskMgr.SetTask(new CTaskSimpleStandStill(999999, true, false, 8.0f), 4, false);
            //pPed->m_pIntelligence->m_TaskMgr.SetTask(operator_new<CTaskSimpleStandStill,int,bool,bool,float>(999999, true, false, 8.0f), 4, false);
        }
        return pPed;
    }

    
    void DELETE_CHAR(CPed* pPed)
    {
        CTheScripts::RemoveThisPed(pPed);
    }

    
    CVector& GET_CHAR_COORDINATES(CPed* pPed)
    {
        CVector* posn;
        CVehicle* vehicle = pPed->m_pVehicle;
        if (pPed->m_nPedFlags.bInVehicle && vehicle)
        {
            posn = &vehicle->GetPosition();

        }
        else
        {
            posn = &pPed->GetPosition();
        }
        return *posn;
    }


    
    void SET_CHAR_COORDINATES(CPed* pPed, CVector& posn, bool bWarpGang, bool bNoOffset)
    {
        plugin::CallMethodDynGlobal<CRunningScript *, CPed *, float, float, float, bool, bool>
            (gaddrof(CRunningScript::SetCharCoordinates), nullptr, pPed, posn.x, posn.y, posn.z, bWarpGang, !bNoOffset);
    }

    
    bool IS_CHAR_IN_AREA_2D(CPed* pPed, CVector2D& fromPos, CVector2D& toPos, bool bSphere)
    {
        CVehicle* vehicle = pPed->m_pVehicle;
        if (pPed->m_nPedFlags.bInVehicle && vehicle)
        {
            return vehicle->IsWithinArea(fromPos.x, fromPos.y, toPos.x, toPos.y);
        }
        else
        {
            return pPed->IsWithinArea(fromPos.x, fromPos.y, toPos.x, toPos.y);
        }
        if (bSphere)
            CTheScripts::HighlightImportantArea(0, fromPos.x, fromPos.y, toPos.x, toPos.y, -100.0f);
    }

    
    bool IS_CHAR_IN_AREA_3D(CPed* pPed, CVector& fromPos, CVector& toPos, bool bSphere)
    {
        CVehicle* vehicle = pPed->m_pVehicle;
        if (pPed->m_nPedFlags.bInVehicle && vehicle)
        {
            return vehicle->IsWithinArea(fromPos.x, fromPos.y, fromPos.z, toPos.x, toPos.y, toPos.z);
        }
        else
        {
            return pPed->IsWithinArea(fromPos.x, fromPos.y, fromPos.z, toPos.x, toPos.y, toPos.z);
        }
        if (bSphere)
        {
            float sphereZ = (fromPos.z + toPos.z) * 0.5f;
            CTheScripts::HighlightImportantArea(0, fromPos.x, fromPos.y, toPos.x, toPos.y, sphereZ);
        }
    }

    
    CVehicle* CREATE_CAR(int modelid, CVector& posn, bool scriptEntity)
    {
        CVehicle* vehicle = CCarCtrl::CreateCarForScript(modelid, posn, 0);
        vehicle->m_nCreatedBy = scriptEntity ? 2 : 1;
        return vehicle;
    }

    
    void DELETE_CAR(CVehicle* pVehicle)
    {
        if (!pVehicle) return;
        CWorld::Remove(pVehicle);
        CWorld::RemoveReferencesToDeletedObject(pVehicle);
        //((void(__thiscall *)(CEntity *, char))GetVMT(pVehicle, 0))(pVehicle, 1); // virtual dtor
        operator_delete<CVehicle>(pVehicle);
    }

    
    void CAR_GOTO_COORDINATES(CVehicle* pVehicle, CVector& posn)
    {
        posn.z += pVehicle->GetDistanceFromCentreOfMassToBaseOfModel();

        bool bSuccess = CCarCtrl::JoinCarWithRoadSystemGotoCoors(pVehicle, posn, false, false) ? false : true;

        eCarMission CarMission = pVehicle->m_autoPilot.m_nCarMission;

        if (bSuccess)
        {
            if (CarMission != eCarMission::MISSION_39 && CarMission != eCarMission::MISSION_3A)
                CarMission = eCarMission::MISSION_GOTOCOORDS;
        }
        else if (CarMission != eCarMission::MISSION_39 && CarMission != eCarMission::MISSION_3A)
        {
            CarMission = eCarMission::MISSION_GOTOCOORDS_STRAIGHT;
        }
        //pVehicle->m_nType = (pVehicle->m_nType & 7) | 0x18;
        pVehicle->m_nStatus = eEntityStatus::STATUS_PHYSICS;
        // pVehicle->SetEngineState(1);
        if (pVehicle->m_nFlags.bEngineBroken)
        {
            pVehicle->m_nFlags.bEngineOn = false;
        }
        else
        {
            pVehicle->m_nFlags.bEngineOn = true;
        }


        if (pVehicle->m_autoPilot.m_nCruiseSpeed < 1)
        {
            pVehicle->m_autoPilot.m_nCruiseSpeed = 1;
        }

        pVehicle->m_autoPilot.m_nTimeToStartMission = CTimer::m_snTimeInMilliseconds;
    }

    
    void CAR_WANDER_RANDOMLY(CVehicle* pVehicle)
    {
        CCarCtrl::JoinCarWithRoadSystem(pVehicle);
        eCarMission CarMission = pVehicle->m_autoPilot.m_nCarMission;
        if (CarMission != eCarMission::MISSION_39 && CarMission != eCarMission::MISSION_3A)
            CarMission = eCarMission::MISSION_CRUISE;

        // pVehicle->SetEngineState(1);
        if (pVehicle->m_nFlags.bEngineBroken)
        {
            pVehicle->m_nFlags.bEngineOn = false;
        }
        else
        {
            pVehicle->m_nFlags.bEngineOn = true;
        }
        if (pVehicle->m_autoPilot.m_nCruiseSpeed < 1)
        {
            pVehicle->m_autoPilot.m_nCruiseSpeed = 1;
        }

        pVehicle->m_autoPilot.m_nTimeToStartMission = CTimer::m_snTimeInMilliseconds;
    }

    
    void CAR_SET_IDLE(CVehicle* pVehicle)
    {
        eCarMission CarMission = pVehicle->m_autoPilot.m_nCarMission;
        if (CarMission != eCarMission::MISSION_39 && CarMission != eCarMission::MISSION_3A)
            CarMission = eCarMission::MISSION_NONE;
    }

    
    CVector& GET_CAR_COORDINATES(CVehicle* pVehicle)
    {
        CVector* posn;
        posn = &pVehicle->GetPosition();

        return *posn;
    }

    
    void SET_CAR_COORDINATES(CVehicle* pVehicle, CVector& posn, bool bNoOffset)
    {
        CCarCtrl::SetCoordsOfScriptCar(pVehicle, posn.x, posn.y, posn.z, 0, !bNoOffset);
    }

    
    void SET_CAR_CRUISE_SPEED(CVehicle* pVehicle, float speed)
    {
        float transmMaxCruise = pVehicle->m_pHandlingData->m_transmissionData.field_5C * 60.0f;
        if (speed >= transmMaxCruise)
        {
            speed = transmMaxCruise;
        }
        pVehicle->m_autoPilot.m_nCruiseSpeed = speed;
    }

    
    void SET_CAR_DRIVING_STYLE(CVehicle* pVehicle, eCarDrivingStyle drivingstyle)
    {
        pVehicle->m_autoPilot.m_nCarDrivingStyle = drivingstyle;
    }

    
    void SET_CAR_MISSION(CVehicle* pVehicle, eCarMission CarMission)
    {
        eCarMission currentMission = pVehicle->m_autoPilot.m_nCarMission;
        if (currentMission != eCarMission::MISSION_39 && currentMission != eCarMission::MISSION_3A)
            currentMission = CarMission;

        pVehicle->m_autoPilot.m_nTimeToStartMission = CTimer::m_snTimeInMilliseconds;
        // pVehicle->SetEngineState(1);
        if (pVehicle->m_nFlags.bEngineBroken)
        {
            pVehicle->m_nFlags.bEngineOn = false;
        }
        else
        {
            pVehicle->m_nFlags.bEngineOn = true;
        }
    }

    
    bool IS_CAR_IN_AREA_2D(CVehicle* pVehicle, CVector2D& fromPos, CVector2D& toPos, bool bSphere)
    {     
        if (bSphere)
            CTheScripts::HighlightImportantArea(0, fromPos.x, fromPos.y, toPos.x, toPos.y, -100.0f);
        return pVehicle->IsWithinArea(fromPos.x, fromPos.y, toPos.x, toPos.y);
    }

    
    bool IS_CAR_IN_AREA_3D(CVehicle* pVehicle, CVector& fromPos, CVector& toPos, bool bSphere)
    {        
        if (bSphere)
        {
            float sphereZ = (fromPos.z + toPos.z) * 0.5f;
            CTheScripts::HighlightImportantArea(0, fromPos.x, fromPos.y, toPos.x, toPos.y, sphereZ);
        }
        return pVehicle->IsWithinArea(fromPos.x, fromPos.y, fromPos.z, toPos.x, toPos.y, toPos.z);
    }

    
    void PRINT_BIG(char* message,unsigned int time,eMessageStyle style)
    {
        CMessages::AddBigMessage(message, time, style);
    }

    
    void PRINT(char* message, unsigned int time, unsigned short flag)
    {
        if (message && message[0] == '~' && message[1] == 'z' && message[2] == '~' && !FrontEndMenuManager.m_bShowSubtitles)
        {
            CTheScripts::bAddNextMessageToPreviousBriefs = true;
        }
        else
        {
            CMessages::AddMessage(message, time, flag, CTheScripts::bAddNextMessageToPreviousBriefs);
        }
    }

    
    void PRINT_NOW(char* message, unsigned int time, unsigned short flag)
    {
        if (!message || message[0] != '~' || message[1] != 'z' || message[2] != '~' || FrontEndMenuManager.m_bShowSubtitles)
        {
            CMessages::AddMessageJumpQ(message, time, flag, CTheScripts::bAddNextMessageToPreviousBriefs);
        }
        CTheScripts::bAddNextMessageToPreviousBriefs = true;
    }

    
    void CLEAR_PRINTS()
    {
        CMessages::ClearMessages(false);
    }

    void GET_TIME_OF_DAY(unsigned char& Ret_Hours,unsigned char& Ret_Minutes)
    {
        Ret_Hours = CClock::ms_nGameClockHours;
        Ret_Minutes = CClock::ms_nGameClockMinutes;
    }

    
    void SET_TIME_OF_DAY(unsigned char Hours, unsigned char Minutes)
    {
        CClock::SetGameClock(Hours, Minutes,0);
    }
    
    unsigned short GET_MINUTES_TO_TIME_OF_DAY(unsigned char Hours, unsigned char Minutes)
    {
        return CClock::GetGameClockMinutesUntil(Hours, Minutes);
    }

    bool IS_POINT_ON_SCREEN(CVector& posn, float radius)
    {
        return ((bool(__thiscall *)(CCamera*,CVector *, float))0x420D40)(&TheCamera,&posn, radius); // CCamera__isSphereVisible()
        
    }

    void DEBUG_ON()
    {
        CTheScripts::DbgFlag = true;
    }
    void DEBUG_OFF()
    {
        CTheScripts::DbgFlag = false;
    }



}
