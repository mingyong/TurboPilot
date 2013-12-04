/**
 ******************************************************************************
 * @file       uobj_Attitude.h
 * @author     王乐辉<wanglehui8357@163.com> Copyright (C) 2013.
 * @brief      declaration of the Attitude Export Data Type. This file has been
 *             automatically generated by the GearCoder.
 *             $(DESCRIPTION)
 * @note       This is an automatically generated file.
 *             !!!DO NOT modify manually!!!.
 ******************************************************************************
**/

#ifndef _UOBJ_ATTITUDE_H_
#define _UOBJ_ATTITUDE_H_

#include "datatype.h"
#include "statuscode.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Export data type constants
#define UOBJ_ATTITUDE_ID           1
#define UOBJ_ATTITUDE_INSTCNT      1
#define UOBJ_ATTITUDE_MEMBERCNT    8
#define UOBJ_ATTITUDE_NAME         "Attitude"

// data type define
typedef struct {
    FP32 CurRoll;             /*!< , Units: deg*/
    FP32 CurPitch;            /*!< , Units: deg*/
    FP32 CurYaw;              /*!< , Units: deg*/
    FP32 CurHeading;          /*!< , Units: deg*/
    FP32 HeadingDot;          /*!< , Units: deg/s*/
    FP32 CurRollDot;          /*!< , Units: deg*/
    FP32 CurPitchDot;         /*!< , Units: deg*/
    FP32 CurYawDot;           /*!< , Units: deg*/

} UObj_Attitude;

// Generic interface functions
extern void Attitude_Init(void);

// Utility for get or set member value
extern TP_STATUS Attitude_Get_CurRoll(FP32 *valPtr);
extern TP_STATUS Attitude_Get_CurPitch(FP32 *valPtr);
extern TP_STATUS Attitude_Get_CurYaw(FP32 *valPtr);
extern TP_STATUS Attitude_Get_CurHeading(FP32 *valPtr);
extern TP_STATUS Attitude_Get_HeadingDot(FP32 *valPtr);
extern TP_STATUS Attitude_Get_CurRollDot(FP32 *valPtr);
extern TP_STATUS Attitude_Get_CurPitchDot(FP32 *valPtr);
extern TP_STATUS Attitude_Get_CurYawDot(FP32 *valPtr);

extern TP_STATUS Attitude_Set_CurRoll(FP32 *valPtr);
extern TP_STATUS Attitude_Set_CurPitch(FP32 *valPtr);
extern TP_STATUS Attitude_Set_CurYaw(FP32 *valPtr);
extern TP_STATUS Attitude_Set_CurHeading(FP32 *valPtr);
extern TP_STATUS Attitude_Set_HeadingDot(FP32 *valPtr);
extern TP_STATUS Attitude_Set_CurRollDot(FP32 *valPtr);
extern TP_STATUS Attitude_Set_CurPitchDot(FP32 *valPtr);
extern TP_STATUS Attitude_Set_CurYawDot(FP32 *valPtr);


extern TP_STATUS Attitude_GetVal(UObj_Attitude *valPtr);

extern TP_STATUS Attitude_SetVal(UObj_Attitude *valPtr);


#ifdef __cplusplus
}
#endif

#endif // ~_UOBJ_ATTITUDE_H_
