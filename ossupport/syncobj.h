/**
 ******************************************************************************
 * @file       syncobj.h
 * @author     WLH<wanglehui8357@163.com> Copyright (C) 2013.
 * @brief      administrator of uav object data type
 * @note       This is an automatically generated file.
 *             !!!DO NOT modify manually!!!.
 ******************************************************************************
**/

#ifndef _SYNCOBJ_H_
#define _SYNCOBJ_H_

#include "datatype.h"
#include "statuscode.h"

/*
 * 用于支持对Uav Object 的可重入互斥
*/
extern TP_STATUS  CreateSyncObj(_UOBJ_SYNC_t* obj);/* Create a sync object */
extern TP_STATUS  RequestGrant (_UOBJ_SYNC_t  obj);/* Lock sync object     */
extern TP_STATUS  ReleaseGrant (_UOBJ_SYNC_t  obj);/* Unlock sync object   */
extern TP_STATUS  DelSyncObj   (_UOBJ_SYNC_t  obj);/* Delete a sync object */

#endif // ~_SYNCOBJ_H_
