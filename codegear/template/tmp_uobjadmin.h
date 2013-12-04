/**
 ******************************************************************************
 * @file       UObjAdmin.h
 * @author     王乐辉<wanglehui8357@163.com> Copyright (C) 2013.
 * @brief      administrator of uav object data type
 * @note       This is an automatically generated file.
 *             !!!DO NOT modify manually!!!.
 ******************************************************************************
**/

#ifndef _UOBJADMIN_H_
#define _UOBJADMIN_H_

#include "datatype.h"
#include "statuscode.h"

#define UOBJ_TYPE_CNT $$UOBJ_TYPE_CNT

typedef U32        (*QueryMemSize)(U32 memId);
typedef TP_STATUS  (*ValSetter)(U32 instId, U32 memID, void* newVal);
typedef TP_STATUS  (*ValGetter)(U32 instId, U32 memID, void* valBuf, U32 bufSize);

/**
 * Access types
 */
typedef enum {
	READ_ONLY  = 0,
	WRITE_ONLY = 1,
    READ_WRITE = 2,
} ACCESSTYPE;

/**
 * Uav object data types meta data struct
 */
typedef struct {
    U8 memberCnt;
    ACCESSTYPE   gcsAccess;
    ACCESSTYPE   flightAccess;
    QueryMemSize pFunQueryMemSize;
    ValSetter    pFunSetValue;
    ValGetter    pFunGetValue;
} UObjMetaData;

extern UObjMetaData* gMetaDataTab[$$UOBJ_TYPE_CNT];

/*
 * 对FieldID进行解析的宏定义
*/
#define TypeId(fieldID)                         ((fieldID & 0xFF000000)>>24)
#define memID(fieldID)                          ((fieldID & 0x00FF0000)>>16)
#define InstId(fieldID)                         ((fieldID & 0x0000FFFF))
#define GenFieldID(typeId, memId, instId)       (((typeId&0xFF)<<24)|((memId&0xFF)<<16)|(instId&0xFFFF))

extern TP_STATUS  UObjSetValue(U32 typeId, U32 instId, U32 memID, void* newVal);
extern TP_STATUS  UObjGetValue(U32 typeId, U32 instId, U32 memID, void* valBuf, U32 bufSize);

#endif // ~_UOBJADMIN_H_
