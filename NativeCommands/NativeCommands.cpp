#include "NativeCommands.h"

namespace Natives
{
    void ACTIVATE_CHEAT(int CheatIndex)
    {
        void (*cheatfunc)();

        cheatfunc = CCheat::m_aCheatFunctions[CheatIndex];
        if (cheatfunc)
        {
            cheatfunc();
        }
        else
        {
            CCheat::m_aCheatsActive[CheatIndex] = CCheat::m_aCheatsActive[CheatIndex] == 0;
        }
    }
}
