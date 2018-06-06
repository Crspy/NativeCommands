#include "CommandsFrom0To99.h"


namespace Natives
{
    void SHAKE_CAM(float strength)
    {
        CGeneral::CamShakeNoPos(&TheCamera, strength);
    }


    CPlayerPed* CREATE_PLAYER(int playerid, CVector& posn, bool scriptEntity)
    {
        if (CStreaming::ms_aInfoForModel[0].m_nLoadState != 1)
        {
            CStreaming::RequestSpecialModel(0, "player", 26);
            CStreaming::LoadAllRequestedModels(true);
        }
        CPlayerPed::SetupPlayerPed(playerid);
        CPlayerPed* playerped = CWorld::Players[playerid].m_pPed;
        playerped->m_nCreatedBy = scriptEntity ? 2 : 1;

        CPlayerPed::DeactivatePlayerPed(playerid);
        posn.z += playerped->GetDistanceFromCentreOfMassToBaseOfModel();
        playerped->SetPosn(posn);
        CTheScripts::ClearSpaceForMissionEntity(posn, playerped);
        CPlayerPed::ReactivatePlayerPed(playerid);
        playerped->m_pIntelligence->m_TaskMgr.SetTask(new CTaskSimplePlayerOnFoot(), 4, false);
        //playerped->m_pIntelligence->m_TaskMgr.SetTask(operator_new<CTaskSimplePlayerOnFoot>(), 4, false);
        return playerped;
    }
}

/*
CPlayerPed* CreatePlayerPed(int playerid, CVector& posn)
{
    if (CStreaming::ms_aInfoForModel[0].m_nLoadState != 1)
    {
        CStreaming::RequestSpecialModel(0, "player", 26);
        CStreaming::LoadAllRequestedModels(true);
    }

    CPlayerPed* player = operator_new<CPlayerPed>(playerid, 0);

    CWorld::Players[playerid].m_pPed = player; // set the playerped ptr

    if (playerid == 1)
        player->m_nPedType = 1;

    player->SetOrientation(0.0f, 0.0f, 0.0f);
    CWorld::Add(player);
    player->m_nWeaponAccuracy = 100;
    CWorld::Players[playerid].m_nPlayerState = PLAYERSTATE_PLAYING;
    player->m_nCreatedBy = 2;
    CPlayerPed::DeactivatePlayerPed(playerid);
    posn.z += player->GetDistanceFromCentreOfMassToBaseOfModel();
    player->SetPosn(posn);
    CTheScripts::ClearSpaceForMissionEntity(posn, player);
    CPlayerPed::ReactivatePlayerPed(playerid);
    player->m_pIntelligence->m_TaskMgr.SetTask(new CTaskSimplePlayerOnFoot(), 4, false);
    //playerped->m_pIntelligence->m_TaskMgr.SetTask(operator_new<CTaskSimplePlayerOnFoot>(), 4, false);
    return player;
}
*/