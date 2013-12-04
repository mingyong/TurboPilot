/**
 ******************************************************************************
 * @file       UObjAdmin.c
 * @author     王乐辉<wanglehui8357@163.com> Copyright (C) 2013.
 * @brief      administrator of all uav object data type
 * @note       This is an automatically generated file.
 *             !!!DO NOT modify manually!!!.
 ******************************************************************************
**/

#include "uobjadmin.h"
/************************************************************************/
/* UAV Objects  include files                                                                                   */
/************************************************************************/
$$UOBJ_INC

/*
* Meta data table for all uav object
*/
UObjMetaData* gMetaDataTab[$$UOBJ_TYPE_CNT];

static void UObjAdmin_Init(void)
{
	/*Init all uav object instance*/
$$ALL_UOBJ_INIT
}

/*
* use to set uav object value
*/
TP_STATUS UObjSetValue(U32 typeId, U32 instId, U32 memId, void* newValue)
{    
    if(typeId < UOBJ_TYPE_CNT)
    {
        return gMetaDataTab[typeId]->pFunSetValue(instId, memId, newValue);        
    }
    return TP_INVALID_TYPEID;
}

/*
* use to get value from uav object 
*/
TP_STATUS UObjGetValue(U32 typeId, U32 instId, U32 memId, void* valBuf, U32 bufSize)
{
    if(typeId < UOBJ_TYPE_CNT)
    {        
        return gMetaDataTab[typeId]->pFunGetValue(instId, memId, valBuf, bufSize);
    }
    return TP_INVALID_TYPEID;    
}
