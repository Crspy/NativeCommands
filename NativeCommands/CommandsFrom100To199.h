#pragma once
#include "CStaticScript.h"

namespace Natives
{
    //009A
    CPed* CREATE_CHAR(ePedType pedtype, int modelindex, CVector& posn, bool scriptEntity);
    //009B
    void DELETE_CHAR(CPed* pPed);
    //00A0
    CVector& GET_CHAR_COORDINATES(CPed* pPed);
    // 00A1 , 08C7 , 0972 , 09BC
    void SET_CHAR_COORDINATES(CPed* pPed, CVector& posn, bool bWarpGang, bool bNoOffset);
    //00A3
    bool IS_CHAR_IN_AREA_2D(CPed* pPed, CVector2D& fromPos, CVector2D& toPos, bool bSphere);
    //00A4
    bool IS_CHAR_IN_AREA_3D(CPed* pPed, CVector& fromPos, CVector& toPos, bool bSphere);
    //00A5
    CVehicle* CREATE_CAR(int modelid, CVector& posn, bool scriptEntity);
    //00A6
    void DELETE_CAR(CVehicle* pVehicle);
    //00A7
    void CAR_GOTO_COORDINATES(CVehicle* pVehicle, CVector& posn);
    //00A8
    void CAR_WANDER_RANDOMLY(CVehicle* pVehicle);
    //00A9
    void CAR_SET_IDLE(CVehicle* pVehicle);
    //00AA
    CVector& GET_CAR_COORDINATES(CVehicle* pVehicle);
    //00AB , 088C
    void SET_CAR_COORDINATES(CVehicle* pVehicle, CVector& posn, bool bNoOffset);
    //00AD
    void SET_CAR_CRUISE_SPEED(CVehicle* pVehicle, float speed);
    //00AE
    void SET_CAR_DRIVING_STYLE(CVehicle* pVehicle, eCarDrivingStyle drivingstyle);
    //00AF
    void SET_CAR_MISSION(CVehicle* pVehicle, eCarMission CarMission);
    //00B0
    bool IS_CAR_IN_AREA_2D(CVehicle* pVehicle, CVector2D& fromPos, CVector2D& toPos, bool bSphere);
    //00B1
    bool IS_CAR_IN_AREA_3D(CVehicle* pVehicle, CVector& fromPos, CVector& toPos, bool bSphere);
    //00BA
    void PRINT_BIG(char* message, unsigned int time, eMessageStyle style);
    //00BB
    void PRINT(char* message, unsigned int time, unsigned short flag = 1);
    //00BC
    void PRINT_NOW(char* message, unsigned int time, unsigned short flag = 1);
    //00BE
    void CLEAR_PRINTS();
    //00BF
    void GET_TIME_OF_DAY(unsigned char& Ret_Hours, unsigned char& Ret_Minutes);
    //00C0
    void SET_TIME_OF_DAY(unsigned char Hours, unsigned char Minutes);
    //00C1
    unsigned short GET_MINUTES_TO_TIME_OF_DAY(unsigned char Hours, unsigned char Minutes);
    //00C2
    bool IS_POINT_ON_SCREEN(CVector& posn, float radius);
    //00C3
    void DEBUG_ON();
    //00C4
    void DEBUG_OFF();
}
