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
        CPed* playerped = CWorld::Players[playerid].m_pPed;
        playerped->m_nCreatedBy = scriptEntity ? 2 : 1;

        CPlayerPed::DeactivatePlayerPed(playerid);
        posn.z += playerped->GetDistanceFromCentreOfMassToBaseOfModel();
        playerped->SetPosn(posn);
        CTheScripts::ClearSpaceForMissionEntity(posn, playerped);
        CPlayerPed::ReactivatePlayerPed(playerid);
        playerped->m_pIntelligence->m_TaskMgr.SetTask(new CTaskSimplePlayerOnFoot(), 4, false);
        //playerped->m_pIntelligence->m_TaskMgr.SetTask(operator_new<CTaskSimplePlayerOnFoot>(), 4, false);
        return static_cast<CPlayerPed*>(playerped);
    }
}