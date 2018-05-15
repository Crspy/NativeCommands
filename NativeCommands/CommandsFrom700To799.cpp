#include "CommandsFrom700To799.h"


namespace Natives
{
    
    bool IS_CURRENT_CHAR_WEAPON(CPed* pPed, eWeaponType weapontype)
    {
        return ((weapontype == 56 && pPed->m_aWeapons[pPed->m_nActiveWeaponSlot].IsTypeMelee())
            || pPed->m_aWeapons[pPed->m_nActiveWeaponSlot].m_nType == weapontype);
    }
}