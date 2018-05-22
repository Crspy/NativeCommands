#include "CommandsFrom1400To1499.h"

namespace Natives
{
    bool IS_PLAYER_IN_INFO_ZONE(char zoneName[8])
    {
        char temp;
        int count(0);
        int zonename[2]{0, 0};
        CVector* playerposn{&FindPlayerPed(-1)->GetPosition()};

        do
        {
            temp = zoneName[count];
            *(reinterpret_cast<BYTE *>(&zonename[0]) + count++) = temp; // filling zonename array with the recieved zoneName[8] chars.
        }
        while (temp);

        return CTheZones::FindZone(playerposn, zonename[0], zonename[1], ZONE_TYPE_NAVI);
    }
}
