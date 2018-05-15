#pragma once
#include "CStaticScript.h"


namespace Natives
{
    //0003
    void SHAKE_CAM(float strength); // between 0.0f - 0.2f

    //0053
    CPlayerPed* CREATE_PLAYER(int playerid, CVector& posn, bool scriptEntity);
}
