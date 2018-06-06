#include "CStaticScript.h"

CRunningScript CStaticScript::script = []() -> CRunningScript
{
    memset(&script, 0, sizeof(CRunningScript));
    script.Init();
    strcpy(script.m_szName, "natives");
    script.m_bIsMission = false;
    script.m_bUseMissionCleanup = false;
    return script;
}();
