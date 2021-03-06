/**
 ******************************************************************************
 * @file       ubj_flycmditem.c
 * @author     王乐辉<wanglehui8357@163.com> Copyright (C) 2013.
 * @brief      Implementation of the FlyCmdItem Export Data Type. This file has been
 *             automatically generated by the GearCoder.
 *             $(DESCRIPTION)
 * @note       This is an automatically generated file.
 *             !!!DO NOT modify manually!!!.
 ******************************************************************************
**/

#include "uobj_flycmditem.h"
#include "uobjadmin.h"
#include "syncobj.h"

/******************************************************************************/
/* Global Variable*/
static UObj_FlyCmdItem gFlyCmdItemInst[1000];
static UObjMetaData gFlyCmdItemMetaData;

/*
 * 辅助函数，获取指定成员变量的内存占用大小
*/
static TP_STATUS _FlyCmdItem_MemberSize(U32 memID)
{
    if(memID > UOBJ_FLYCMDITEM_MEMBERCNT)
    {
        return TP_INVALID_MEMBERID;
    }

	switch(memID)
	{
	case 0: return sizeof(UObj_FlyCmdItem);
    case 1: return sizeof(S16);
	case 2: return sizeof(U8);
	case 3: return sizeof(S32);
	case 4: return sizeof(S32);
	case 5: return sizeof(U8);
	case 6: return sizeof(S32);
	case 7: return sizeof(S32);
	
    default:
        return TP_INVALID_MEMBERID;
	}
	return TP_OK;
}


/*
 * 辅助函数，设置指定成员变量内容
*/
static TP_STATUS _FlyCmdItem_SetValue(U32 instId, U32 memID, void* newVal)
{
    TP_STATUS status;

    _UOBJ_SYNC_t obj;
    CreateSyncObj(&obj);
    if(memID > UOBJ_FLYCMDITEM_MEMBERCNT)
    {
        return TP_INVALID_MEMBERID;
    }

    if(instId >= UOBJ_FLYCMDITEM_INSTCNT)
    {
        return TP_INVALID_INSTID;
    }

    RequestGrant(obj);
    switch(memID)
    {
    case 1: memcpy(valPtr, &gFlyCmdItemInst.CmdCode, sizeof(S16));
	case 2: memcpy(valPtr, &gFlyCmdItemInst.Para1Type, sizeof(U8));
	case 3: memcpy(valPtr, &gFlyCmdItemInst.Para1ValueA, sizeof(S32));
	case 4: memcpy(valPtr, &gFlyCmdItemInst.Para1ValueB, sizeof(S32));
	case 5: memcpy(valPtr, &gFlyCmdItemInst.Para2Type, sizeof(U8));
	case 6: memcpy(valPtr, &gFlyCmdItemInst.Para2ValueA, sizeof(S32));
	case 7: memcpy(valPtr, &gFlyCmdItemInst.Para2ValueB, sizeof(S32));
	
    }
    ReleaseGrant(obj);
    return TP_OK;
}

/*
 * 辅助函数，获取指定成员变量内容
*/
static TP_STATUS _FlyCmdItem_GetValue(U32 instId, U32 memID, void* valBuf, U32 bufSize)
{
    _UOBJ_SYNC_t obj;
    CreateSyncObj(&obj);

    if(memID > UObj_FLYCMDITEM_MEMBERCNT)
    {
        return TP_INVALID_MEMBERID;
    }

    if(instId >= UObj_FLYCMDITEM_INSTCNT)
    {
        return TP_INVALID_INSTID;
    }

    RequestGrant(obj);
    switch(memID)
    {
    case 1: memcpy(&gFlyCmdItemInst.CmdCode, valPtr, sizeof(S16));
	case 2: memcpy(&gFlyCmdItemInst.Para1Type, valPtr, sizeof(U8));
	case 3: memcpy(&gFlyCmdItemInst.Para1ValueA, valPtr, sizeof(S32));
	case 4: memcpy(&gFlyCmdItemInst.Para1ValueB, valPtr, sizeof(S32));
	case 5: memcpy(&gFlyCmdItemInst.Para2Type, valPtr, sizeof(U8));
	case 6: memcpy(&gFlyCmdItemInst.Para2ValueA, valPtr, sizeof(S32));
	case 7: memcpy(&gFlyCmdItemInst.Para2ValueB, valPtr, sizeof(S32));
	
    }
    ReleaseGrant(obj);

    return TP_OK;
}

void FlyCmdItem_Init(void)
{
    gFlyCmdItemMetaData.memberCnt = UObj_FLYCMDITEM_MEMBERCNT;
    gFlyCmdItemMetaData.accessType =  $(ACCESS_TYPE);
    gFlyCmdItemMetaData.pFunMemberSize = _FlyCmdItem_MemberSize;
    gFlyCmdItemMetaData.pFunGetValue = _FlyCmdItem_GetValue;
    gFlyCmdItemMetaData.pFunSetValue = _FlyCmdItem_SetValue;

    gMetaDataTab[UObj_FLYCMDITEM_ID] = &gFlyCmdItemMetaData;
}

TP_STATUS FlyCmdItem_Get_CmdCode(U32 instId, S16 *valuePtr)
{
	return _FlyCmdItem_GetValue(instId, 0, valPtr, sizeof(S16));
}
TP_STATUS FlyCmdItem_Get_Para1Type(U32 instId, U8 *valuePtr)
{
	return _FlyCmdItem_GetValue(instId, 1, valPtr, sizeof(U8));
}
TP_STATUS FlyCmdItem_Get_Para1ValueA(U32 instId, S32 *valuePtr)
{
	return _FlyCmdItem_GetValue(instId, 2, valPtr, sizeof(S32));
}
TP_STATUS FlyCmdItem_Get_Para1ValueB(U32 instId, S32 *valuePtr)
{
	return _FlyCmdItem_GetValue(instId, 3, valPtr, sizeof(S32));
}
TP_STATUS FlyCmdItem_Get_Para2Type(U32 instId, U8 *valuePtr)
{
	return _FlyCmdItem_GetValue(instId, 4, valPtr, sizeof(U8));
}
TP_STATUS FlyCmdItem_Get_Para2ValueA(U32 instId, S32 *valuePtr)
{
	return _FlyCmdItem_GetValue(instId, 5, valPtr, sizeof(S32));
}
TP_STATUS FlyCmdItem_Get_Para2ValueB(U32 instId, S32 *valuePtr)
{
	return _FlyCmdItem_GetValue(instId, 6, valPtr, sizeof(S32));
}

TP_STATUS FlyCmdItem_Set_CmdCode(U32 instId, S16 *valuePtr)
{
	return _FlyCmdItem_SetValue(instId, 0, valPtr, sizeof(S16);
}
TP_STATUS FlyCmdItem_Set_Para1Type(U32 instId, U8 *valuePtr)
{
	return _FlyCmdItem_SetValue(instId, 1, valPtr, sizeof(U8);
}
TP_STATUS FlyCmdItem_Set_Para1ValueA(U32 instId, S32 *valuePtr)
{
	return _FlyCmdItem_SetValue(instId, 2, valPtr, sizeof(S32);
}
TP_STATUS FlyCmdItem_Set_Para1ValueB(U32 instId, S32 *valuePtr)
{
	return _FlyCmdItem_SetValue(instId, 3, valPtr, sizeof(S32);
}
TP_STATUS FlyCmdItem_Set_Para2Type(U32 instId, U8 *valuePtr)
{
	return _FlyCmdItem_SetValue(instId, 4, valPtr, sizeof(U8);
}
TP_STATUS FlyCmdItem_Set_Para2ValueA(U32 instId, S32 *valuePtr)
{
	return _FlyCmdItem_SetValue(instId, 5, valPtr, sizeof(S32);
}
TP_STATUS FlyCmdItem_Set_Para2ValueB(U32 instId, S32 *valuePtr)
{
	return _FlyCmdItem_SetValue(instId, 6, valPtr, sizeof(S32);
}


/**********************************************************************/
TP_STATUS FlyCmdItem_Get(U32 instId, UObj_FlyCmdItem *valPtr)
{
    _UOBJ_SYNC_t obj;
    CreateSyncObj(&obj);
    if(instId >= UObj_FLYCMDITEM_INSTCNT)
    {
        return TP_INVALID_INSTID;
    }

    RequestGrant(obj);
    memcpy(valuePtr, &gFlyCmdItemInst[instId], sizeof(UObj_FlyCmdItem));
    ReleaseGrant(obj);

    return TP_OK;
}
/**********************************************************************/
TP_STATUS FlyCmdItem_Set(U32 instId, UObj_FlyCmdItem *valPtr)
{
    _UOBJ_SYNC_t obj;
    CreateSyncObj(&obj);
    if(instId >= UObj_FLYCMDITEM_INSTCNT)
    {
        return TP_INVALID_INSTID;
    }

    RequestGrant(obj);
    memcpy(&gFlyCmdItemInst[instId], valuePtr, sizeof(UObj_FlyCmdItem));
    ReleaseGrant(obj);

    return TP_OK;
}
