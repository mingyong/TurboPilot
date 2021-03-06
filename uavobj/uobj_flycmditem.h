/**
 ******************************************************************************
 * @file       uobj_FlyCmdItem.h
 * @author     王乐辉<wanglehui8357@163.com> Copyright (C) 2013.
 * @brief      declaration of the FlyCmdItem Export Data Type. This file has been
 *             automatically generated by the GearCoder.
 *             $(DESCRIPTION)
 * @note       This is an automatically generated file.
 *             !!!DO NOT modify manually!!!.
 ******************************************************************************
**/

#ifndef _UOBJ_FLYCMDITEM_H_
#define _UOBJ_FLYCMDITEM_H_

#include "datatype.h"
#include "statuscode.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Export data type constants
#define UOBJ_FLYCMDITEM_ID           2
#define UOBJ_FLYCMDITEM_INSTCNT      1000
#define UOBJ_FLYCMDITEM_MEMBERCNT    7
#define UOBJ_FLYCMDITEM_NAME         "FlyCmdItem"

// data type define
typedef struct {
    S16 CmdCode;              /*!< 命令编码, Units: */
    U8 Para1Type;             /*!< 参数1类型, Units: */
    S32 Para1ValueA;          /*!< 参数1组成值A, Units: */
    S32 Para1ValueB;          /*!< 参数1组成值B, Units: */
    U8 Para2Type;             /*!< 参数2类型, Units: */
    S32 Para2ValueA;          /*!< 参数2组成值A, Units: */
    S32 Para2ValueB;          /*!< 参数2组成值B, Units: */

} UObj_FlyCmdItem;

// Generic interface functions
extern void FlyCmdItem_Init(void);

// Utility for get or set member value
extern TP_STATUS FlyCmdItem_Get_CmdCode(U32 instId, S16 *valPtr);
extern TP_STATUS FlyCmdItem_Get_Para1Type(U32 instId, U8 *valPtr);
extern TP_STATUS FlyCmdItem_Get_Para1ValueA(U32 instId, S32 *valPtr);
extern TP_STATUS FlyCmdItem_Get_Para1ValueB(U32 instId, S32 *valPtr);
extern TP_STATUS FlyCmdItem_Get_Para2Type(U32 instId, U8 *valPtr);
extern TP_STATUS FlyCmdItem_Get_Para2ValueA(U32 instId, S32 *valPtr);
extern TP_STATUS FlyCmdItem_Get_Para2ValueB(U32 instId, S32 *valPtr);

extern TP_STATUS FlyCmdItem_Set_CmdCode(U32 instId, S16 *valPtr);
extern TP_STATUS FlyCmdItem_Set_Para1Type(U32 instId, U8 *valPtr);
extern TP_STATUS FlyCmdItem_Set_Para1ValueA(U32 instId, S32 *valPtr);
extern TP_STATUS FlyCmdItem_Set_Para1ValueB(U32 instId, S32 *valPtr);
extern TP_STATUS FlyCmdItem_Set_Para2Type(U32 instId, U8 *valPtr);
extern TP_STATUS FlyCmdItem_Set_Para2ValueA(U32 instId, S32 *valPtr);
extern TP_STATUS FlyCmdItem_Set_Para2ValueB(U32 instId, S32 *valPtr);


extern TP_STATUS FlyCmdItem_GetVal(U32 instId, UObj_FlyCmdItem *valPtr);

extern TP_STATUS FlyCmdItem_SetVal(U32 instId, UObj_FlyCmdItem *valPtr);


#ifdef __cplusplus
}
#endif

#endif // ~_UOBJ_FLYCMDITEM_H_
