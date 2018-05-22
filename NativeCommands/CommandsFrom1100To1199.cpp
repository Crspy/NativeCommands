#include "CommandsFrom1100To1199.h"


namespace Natives
{
    bool HAS_MODEL_LOADED(int modelid)
    {
        return CStreaming::ms_aInfoForModel[modelid].m_nLoadState == LOADSTATE_LOADED;
    }
}
