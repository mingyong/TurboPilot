/**
 ******************************************************************************
 * @file       ModuleAdmin.h
 * @author     王乐辉<wanglehui8357@163.com> Copyright (C) 2013.
 * @brief      administrator of modules
 * @note       This is an automatically generated file.
 *             !!!DO NOT modify manually!!!.
 ******************************************************************************
**/

#ifndef _MODULEADMIN_H_
#define _MODULEADMIN_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "datatype.h"
#include "os.h"
#include "os_cfg.h"

/*!< define the count of moudules*/
#define  MODULES_CNT    $(MODULES_CNT)

/************************************************************************/
/* Micro for Size of each task's stacks
/************************************************************************/
$(TASK_STK_SIZE)

/************************************************************************/
/* Micro for tasks priorities
/************************************************************************/
$(TASK_PRIO)

/************************************************************************/
/* declare for tasks control block
/************************************************************************/
$(TASK_TCB)

extern void Modules_Init(void);

#ifdef __cplusplus
}
#endif

#endif // ~_ModuleAdmin_H_
