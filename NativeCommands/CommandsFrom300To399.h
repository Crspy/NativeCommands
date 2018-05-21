#pragma once
#include "CStaticScript.h"

namespace Natives
{
    //@opcode0137
    bool IS_CAR_MODEL(CVehicle* pVehicle,int modelindex);

    //@opcode 014B
    //@Alarm_chances are The chances of the cars alarm going off ( 0 - 255 )
    //@DoorLock_chances are The chance of the car door being locked ( 0 - 255 )
    //@delayStart , delayEnd  are Time in ms
    //@color ids depends on the carcols.dat
    //@return CCarGenerator index/handle in CTheCarGenerators::CarGeneratorArray
    int CREATE_CAR_GENERATOR(CVector& posn, float Heading, int modelindex, short color1_ID, short color2_ID,
        bool bForceSpawn, unsigned char Alarm_chances, unsigned char DoorLock_chances, int delayStart, int delayEnd);

    //@opcode 014C
    //@num_generations  
    // 0 :       Car will never spawn
    // 1-100 :   Car will spawn that number of times.
    // 101 :     Car will always spawn.
    void SWITCH_CAR_GENERATOR(int CarGenIndex, short num_generations);

    //@opcode 014E
    //@direction Up or Down
    //@id from 0 - 30
    //don't use the same id for another counter or timer
    void DISPLAY_ONSCREEN_TIMER(int id, eOnScreenTimer direction);

    //@opcode 014F
    //@id from 0 - 30
    void CLEAR_ONSCREEN_TIMER(int id);

    //@opcode 0150
    //@id from 0 - 30
    //don't use the same id for another counter or timer
    void DISPLAY_ONSCREEN_COUNTER(int id, eCounterDisplay countertype);

    //@opcode 0151
    //@id from 0 - 30
    void CLEAR_ONSCREEN_COUNTER(int id);

    //@opcode 0154
    bool IS_CHAR_IN_ZONE(CPed* pPed, char* zoneName);

    //@opcode 0158
    void POINT_CAMERA_AT_CAR(CVehicle* pVehicle,eCamMode camMode,eSwitchType switchType);

    //@opcode 0159
    void POINT_CAMERA_AT_CHAR(CPed* pPed, eCamMode camMode, eSwitchType switchType);

    //@opcode 015A
    void RESTORE_CAMERA();

    //@opcode 015B
    void SHAKE_PAD(int padID, short duration, unsigned char intensity);

    //@opcode 015D
    void SET_TIME_SCALE();

    //@opcode 015F
    void SET_FIXED_CAMERA_POSITION();

    //@opcode 0160
    void POINT_CAMERA_AT_POINT();

    //@opcode 0161
    int ADD_BLIP_FOR_CAR_OLD();

    //@opcode 0164
    void REMOVE_BLIP();

    //@opcode 0165
    void CHANGE_BLIP_COLOUR();

    //@opcode 0167
    int ADD_BLIP_FOR_COORD_OLD();

    //@opcode 0168
    void CHANGE_BLIP_SCALE();

    //@opcode 0169
    void SET_FADING_COLOUR();

    //@opcode 016A
    void DO_FADE();

    //@opcode 016B
    bool GET_FADING_STATUS();

    //@opcode 016C
    void ADD_HOSPITAL_RESTART();

    //@opcode 016D
    void ADD_POLICE_RESTART();

    //@opcode 016E
    void OVERRIDE_NEXT_RESTART();

    //@opcode 016F
    void DRAW_SHADOW();

    //@opcode 0172
    float GET_CHAR_HEADING();

    //@opcode 0173
    void SET_CHAR_HEADING();

    //@opcode 0174
    float GET_CAR_HEADING();

    //@opcode 0175
    void SET_CAR_HEADING();

    //@opcode 0176
    float GET_OBJECT_HEADING();

    //@opcode 0177
    void SET_OBJECT_HEADING();

    //@opcode 0179
    bool IS_CHAR_TOUCHING_OBJECT();

    //@opcode 017B
    void SET_CHAR_AMMO();

    //@opcode 0180
    void DECLARE_MISSION_FLAG();

    //@opcode 0184
    bool IS_CHAR_HEALTH_GREATER();

    //@opcode 0185
    bool IS_CAR_HEALTH_GREATER();

    //@opcode 0186
    int ADD_BLIP_FOR_CAR();

    //@opcode 0187
    int ADD_BLIP_FOR_CHAR();

    //@opcode 0188
    int ADD_BLIP_FOR_OBJECT();

    //@opcode 018A
    int ADD_BLIP_FOR_COORD();

    //@opcode 018B
    void CHANGE_BLIP_DISPLAY();

    //@opcode 018C
    void ADD_ONE_OFF_SOUND();

    //@opcode 018D
    int ADD_CONTINUOUS_SOUND();

    //@opcode 018E
    void REMOVE_SOUND();

    //@opcode 018F
    bool IS_CAR_STUCK_ON_ROOF();


}

