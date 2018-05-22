#include "CommandsFrom300To399.h"


namespace Natives
{
    bool IS_CAR_MODEL(CVehicle* pVehicle, int modelindex)
    {
        return pVehicle->m_nModelIndex == modelindex;
    }

    int CREATE_CAR_GENERATOR(CVector& posn, float Heading, int modelindex, short color1_ID, short color2_ID,
                             bool bForceSpawn, unsigned char Alarm_chances, unsigned char DoorLock_chances,
                             int delayStart, int delayEnd)
    {
        return CTheCarGenerators::CreateCarGenerator(posn.x, posn.y, posn.z, Heading, modelindex,
                                                     color1_ID, color2_ID, bForceSpawn, Alarm_chances, DoorLock_chances,
                                                     delayStart, delayEnd, 0, true);
    }

    void SWITCH_CAR_GENERATOR(int CarGenIndex, short num_generations)
    {
        CCarGenerator* cargen = &CTheCarGenerators::CarGeneratorArray[CarGenIndex];
        if (num_generations)
        {
            cargen->SwitchOn();

            if (num_generations <= 100) cargen->m_nGenerateCount = num_generations;
        }
        else
        {
            cargen->SwitchOff();
        }
    }

    void DISPLAY_ONSCREEN_TIMER(int id, eOnScreenTimer direction)
    {
        if (direction)
        {
            CUserDisplay::OnscnTimer.AddClock((unsigned int)&CStaticScript::script.m_aLocalVars[id].iParam, nullptr,
                                              direction);
        }
        else
        {
            CUserDisplay::OnscnTimer.AddClock((unsigned int)&CStaticScript::script.m_aLocalVars[id].iParam, nullptr,
                                              direction);
        }
    }

    void CLEAR_ONSCREEN_TIMER(int id)
    {
        CUserDisplay::OnscnTimer.ClearClock((unsigned int)&CStaticScript::script.m_aLocalVars[id].iParam);
    }

    void DISPLAY_ONSCREEN_COUNTER(int id, eCounterDisplay countertype)
    {
        CUserDisplay::OnscnTimer.AddCounter((unsigned int)&CStaticScript::script.m_aLocalVars[id].iParam, countertype,
                                            nullptr, 0);
    }

    void CLEAR_ONSCREEN_COUNTER(int id)
    {
        CUserDisplay::OnscnTimer.ClearClock((unsigned int)&CStaticScript::script.m_aLocalVars[id].iParam);
    }

    bool IS_CHAR_IN_ZONE(CPed* pPed, char* zoneName)
    {
        int ZoneName[2] = {0, 0};
        int v11;
        int v10 = 0;
        do
        {
            v11 = zoneName[v10];
            *((char *)&ZoneName + v10++) = v11; // move zoneName contents to ZoneName
        }
        while (v11);
        CVehicle* vehicle = pPed->m_pVehicle;
        CVector* posn;
        if (pPed->m_nPedFlags.bInVehicle && vehicle)
            posn = &vehicle->GetPosition();

        else
            posn = &pPed->GetPosition();

        return CTheZones::FindZone(posn, ZoneName[0], ZoneName[1], ZONE_TYPE_NAVI);
    }

    void POINT_CAMERA_AT_CAR(CVehicle* pVehicle, eCamMode camMode, eSwitchType switchType)
    {
        if (pVehicle) TheCamera.TakeControl(pVehicle, camMode, switchType, 1);
    }

    void POINT_CAMERA_AT_CHAR(CPed* pPed, eCamMode camMode, eSwitchType switchType)
    {
        if (pPed->IsPlayer())
            TheCamera.TakeControl(nullptr, camMode, switchType, 1);
        else
            TheCamera.TakeControl(pPed, camMode, switchType, 1);
    }

    void RESTORE_CAMERA()
    {
        TheCamera.Restore();
    }

    void SHAKE_PAD(int padID, short duration, unsigned char intensity)
    {
        CPad::GetPad(padID)->StartShake(duration, intensity, 0);
    }
}
