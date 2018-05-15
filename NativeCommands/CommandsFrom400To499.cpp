#include "CommandsFrom400To499.h"


namespace Natives
{
    
    CPed* CREATE_CHAR_AS_PASSENGER(CVehicle* pVehicle, ePedType pedtype, int modelindex, int seat, bool scriptEntity)
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

        pPed->m_nCreatedBy = scriptEntity ? 2 : 1;
        pPed->m_nPedFlags.bKnockedOffBike = false;
        if (pVehicle->m_nFlags.bIsBus) pPed->m_nPedFlags.bRenderPedInCar = false;

        signed int targDoor(0);
        if (seat >= 0)
        {
            targDoor = CCarEnterExit::ComputeTargetDoorToEnterAsPassenger(*pVehicle, seat);
        }
        CTaskSimpleCarSetPedInAsPassenger TaskSimpleCarSetPedInAsPassenger(pVehicle, targDoor, nullptr);
        TaskSimpleCarSetPedInAsPassenger.m_bWarpingInToCar = true;
        TaskSimpleCarSetPedInAsPassenger.ProcessPed(pPed);
        CWorld::Add(pPed);
        return pPed;
    }
}