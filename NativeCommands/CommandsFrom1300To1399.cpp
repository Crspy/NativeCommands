#include "CommandsFrom1300To1399.h"


namespace Natives
{
    bool HAS_CHAR_BEEN_DAMAGED_BY_CHAR(CPed* ped, CPed* byPed)
    {
        bool result = false;

        if (!ped || !byPed || !ped->m_pLastEntityDamage) return false;

        if (ped->m_pLastEntityDamage == static_cast<CEntity*>(byPed)) result = true;

        if (!byPed->m_nPedFlags.bInVehicle) return result;

        if (ped->m_pLastEntityDamage == static_cast<CEntity*>(byPed->m_pVehicle)) result = true;

        return result;
    }


    void MAKE_HELI_COME_CRASHING_DOWN(CHeli* heli)
    {
        if (!(heli->m_autoPilot.m_nCarMission == MISSION_39)
            && !(heli->m_autoPilot.m_nCarMission == MISSION_3A))
        {
            heli->m_autoPilot.m_nCarMission = MISSION_3A;
        }
    }
}
