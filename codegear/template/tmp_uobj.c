/**
 ******************************************************************************
 * @file       ubj_$${NAMELC}.c
 * @author     王乐辉<wanglehui8357@163.com> Copyright (C) 2013.
 * @brief      Implementation of the $${NAME} Export Data Type. This file has been
 *             automatically generated by the GearCoder.
 *             $(DESCRIPTION)
 * @note       This is an automatically generated file.
 *             !!!DO NOT modify manually!!!.
 ******************************************************************************
**/

#include "uobj_$${NAMELC}.h"
#include "uobjadmin.h"
#include "syncobj.h"

/******************************************************************************/
/* Global Variable*/
$${INST_DEFINE}
static UObjMetaData g$${NAME}MetaData;

/*
 * 辅助函数，获取指定成员变量的内存占用大小
*/
static TP_STATUS _$${NAME}_MemberSize(U32 memID)
{
    if(memID > UOBJ_$${NAMEUC}_MEMBERCNT)
    {
        return TP_INVALID_MEMBERID;
    }

	switch(memID)
	{
	case 0: return sizeof(UObj_$${NAME});
    $${MEMSIZEINFO}
    default:
        return TP_INVALID_MEMBERID;
	}
	return TP_OK;
}


/*
 * 辅助函数，设置指定成员变量内容
*/
static TP_STATUS _$${NAME}_SetValue(U32 instId, U32 memID, void* newVal)
{
    TP_STATUS status;

    _UOBJ_SYNC_t obj;
    CreateSyncObj(&obj);
    if(memID > UOBJ_$${NAMEUC}_MEMBERCNT)
    {
        return TP_INVALID_MEMBERID;
    }

    if(instId >= UOBJ_$${NAMEUC}_INSTCNT)
    {
        return TP_INVALID_INSTID;
    }

    RequestGrant(obj);
    switch(memID)
    {
    $${MEMVAL_SET_INFO}
    }
    ReleaseGrant(obj);
    return TP_OK;
}

/*
 * 辅助函数，获取指定成员变量内容
*/
static TP_STATUS _$${NAME}_GetValue(U32 instId, U32 memID, void* valBuf, U32 bufSize)
{
    _UOBJ_SYNC_t obj;
    CreateSyncObj(&obj);

    if(memID > UObj_$${NAMEUC}_MEMBERCNT)
    {
        return TP_INVALID_MEMBERID;
    }

    if(instId >= UObj_$${NAMEUC}_INSTCNT)
    {
        return TP_INVALID_INSTID;
    }

    RequestGrant(obj);
    switch(memID)
    {
    $${MEMVAL_GET_INFO}
    }
    ReleaseGrant(obj);

    return TP_OK;
}

void $${NAME}_Init(void)
{
    g$${NAME}MetaData.memberCnt = UObj_$${NAMEUC}_MEMBERCNT;
    g$${NAME}MetaData.accessType =  $(ACCESS_TYPE);
    g$${NAME}MetaData.pFunMemberSize = _$${NAME}_MemberSize;
    g$${NAME}MetaData.pFunGetValue = _$${NAME}_GetValue;
    g$${NAME}MetaData.pFunSetValue = _$${NAME}_SetValue;

    gMetaDataTab[UObj_$${NAMEUC}_ID] = &g$${NAME}MetaData;
}

$${MEM_GETTER_IMP}
$${MEM_SETTER_IMP}

/**********************************************************************/
TP_STATUS $${NAME}_Get($${INSTID_PARA1} UObj_$${NAME} *valPtr)
{
    _UOBJ_SYNC_t obj;
    CreateSyncObj(&obj);
    if(instId >= UObj_$${NAMEUC}_INSTCNT)
    {
        return TP_INVALID_INSTID;
    }

    RequestGrant(obj);
    memcpy(valuePtr, &g$${NAME}Inst$${INSTID_PARA2}, sizeof(UObj_$${NAME}));
    ReleaseGrant(obj);

    return TP_OK;
}
/**********************************************************************/
TP_STATUS $${NAME}_Set($${INSTID_PARA1} UObj_$${NAME} *valPtr)
{
    _UOBJ_SYNC_t obj;
    CreateSyncObj(&obj);
    if(instId >= UObj_$${NAMEUC}_INSTCNT)
    {
        return TP_INVALID_INSTID;
    }

    RequestGrant(obj);
    memcpy(&g$${NAME}Inst$${INSTID_PARA2}, valuePtr, sizeof(UObj_$${NAME}));
    ReleaseGrant(obj);

    return TP_OK;
}
