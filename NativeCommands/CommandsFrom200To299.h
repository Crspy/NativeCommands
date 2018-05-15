#pragma once
#include "CStaticScript.h"

namespace Natives
{
    //00D7
    void LAUNCH_MISSION(unsigned int MissionLabel_LocalOffset);
    //00D8
    void MISSION_HAS_FINISHED();
    //00D9
    CVehicle* GET_CAR_CHAR_IS_IN(CPed* pPed);
    //00DB
    bool IS_CHAR_IN_CAR(CPed* pPed, CVehicle* pVehicle);
    //00DD
    bool IS_CHAR_IN_MODEL(CPed*  pPed, int modelindex);
    //00DF
    bool IS_CHAR_IN_ANY_CAR(CPed*  pPed);
    //00E1
    bool IS_BUTTON_PRESSED(unsigned short playerid, eButtonID buttonID);
    //00E2
    short GET_PAD_STATE(unsigned short playerid, eButtonID buttonID);
    //00EC
    bool LOCATE_CHAR_ANY_MEANS_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere);
    //00ED
    bool LOCATE_CHAR_ON_FOOT_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere);
    //00EE
    bool LOCATE_CHAR_IN_CAR_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere);
    //00EF
    bool LOCATE_STOPPED_CHAR_ANY_MEANS_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere);
    //00F0
    bool LOCATE_STOPPED_CHAR_ON_FOOT_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere);
    //00F1
    bool LOCATE_STOPPED_CHAR_IN_CAR_2D(CPed* pPed, CVector2D& posn, CVector2D& radius, bool bSphere);
    //00F2
    bool LOCATE_CHAR_ANY_MEANS_CHAR_2D(CPed* pPed, CPed* pTargetPed, CVector2D& radius, bool bSphere);
    //00F3
    bool LOCATE_CHAR_ON_FOOT_CHAR_2D(CPed* pPed, CPed* pTargetPed, CVector2D& radius, bool bSphere);
    //00F4
    bool LOCATE_CHAR_IN_CAR_CHAR_2D(CPed* pPed, CPed* pTargetPed, CVector2D& radius, bool bSphere);
    //00FE
    bool LOCATE_CHAR_ANY_MEANS_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere);
    //00FF
    bool LOCATE_CHAR_ON_FOOT_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere);
    //0100
    bool LOCATE_CHAR_IN_CAR_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere);
    //0101
    bool LOCATE_STOPPED_CHAR_ANY_MEANS_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere);
    //0102
    bool LOCATE_STOPPED_CHAR_ON_FOOT_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere);
    //0103
    bool LOCATE_STOPPED_CHAR_IN_CAR_3D(CPed* pPed, CVector& posn, CVector& radius, bool bSphere);
    //0104
    bool LOCATE_CHAR_ANY_MEANS_CHAR_3D(CPed* pPed, CPed* pTargetPed, CVector& radius, bool bSphere);
    //0105
    bool LOCATE_CHAR_ON_FOOT_CHAR_3D(CPed* pPed, CPed* pTargetPed, CVector& radius, bool bSphere);
    //0106
    bool LOCATE_CHAR_IN_CAR_CHAR_3D(CPed* pPed, CPed* pTargetPed, CVector& radius, bool bSphere);
    //0107 , 029B
    CObject* CREATE_OBJECT(int modelIndex, CVector& posn,eObjectType objectType,bool bNoOffset);
    //0108
    void DELETE_OBJECT(CObject* pObject);
    //0109
    void ADD_SCORE(int playerid, int amount);
    //010A
    bool IS_SCORE_GREATER(int playerid, int amount);
    //010B
    int GET_PLAYER_SCORE(int playerid);
    //010D , 010E
    void ALTER_WANTED_LEVEL(int playerid,int wantedLevel, bool bNoDrop);
    //010F
    bool IS_WANTED_LEVEL_GREATER(int playerid, int wantedlevel);
    //0110
    void CLEAR_WANTED_LEVEL(int playerid);
    //0111
    //void SET_DEATHARREST_STATE(bool bState);
    //0112
    //bool HAS_DEATHARREST_BEEN_EXECUTED();
    //0114
    void ADD_AMMO_TO_CHAR(CPed* pPed, eWeaponType weapontype, int ammo);
    //0117
    bool IS_PLAYER_DEAD(int playerid);
    //0118
    bool IS_CHAR_DEAD(CPed* pPed);
    //0119
    bool IS_CAR_DEAD(CVehicle* pVehicle);
    //0122
    bool IS_PLAYER_PRESSING_HORN(int playerid);
    //0129
    CPed* CREATE_CHAR_IN_CAR(CVehicle* pVehicle, ePedType pedtype, int modelindex, bool scriptEntity);
}