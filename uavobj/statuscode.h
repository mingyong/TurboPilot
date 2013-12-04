/**
 ******************************************************************************
 * @file       statuscode.h
 * @author     王乐辉<wanglehui8357@163.com> Copyright (C) 2013.
 * @brief      Turbo Pilot status code define
 ******************************************************************************
**/

#ifndef _STATUSCODE_H_
#define _STATUSCODE_H_

/************************************************************************/
/*                      STATUS CODES                                    */
/************************************************************************/
typedef  enum  _TP_STATUS {
    
	TP_OK                        =0,   /*command successfully completed*/
	TP_BAD_VAR_ID                =1,   /*invalid field identifier*/
	TP_CANT_SAVE_VAR             =2,   /*field cannot be written into flash*/
	TP_CANT_CHANGE_VAR_INFLIGHT  =3,   /*field cannot be changed while in flight*/
	TP_INVALID_TYPEID            =4,   /**/
	TP_INVALID_MEMID             =5,   /**/
	TP_INVALID_INSTID            =6,   /**/
	TP_VAR_READ_ONLY             =7,   /**/

} TP_STATUS;

#endif // ~_STATUSCODE_H_

