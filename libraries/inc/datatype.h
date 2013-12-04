/*---------------------------------------------------------------------------*/
/**@file DataType.H
 * @brief 基本数据类型定义，简化类型名称
 * @author WLH <wanglehui8357@163.com>
 * @version 0.1
 * @date 2010-01-01
*/
/*---------------------------------------------------------------------------*/

#ifndef _DATA_TYPE_H
#define _DATA_TYPE_H

#include <assert.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef  unsigned  char        U8;  /*  8-bit unsigned integer                              */
typedef  signed    char        S8;  /*  8-bit   signed integer                              */
typedef  unsigned  short  int  U16; /* 16-bit unsigned integer                              */
typedef  signed    short  int  S16; /* 16-bit   signed integer                              */
typedef  unsigned  long        U32; /* 32-bit unsigned integer                              */
typedef  signed    long        S32; /* 32-bit   signed integer                              */
typedef            float       FP32;/* 32-bit floating point                                */
typedef            double      FP64;/* 64-bit floating point                                */

#ifndef FALSE
/* FALSE macro */
#define FALSE (0==1)
#endif

#ifndef TRUE
/* TRUE macro */
#define TRUE (!(FALSE))
#endif

/***********************************************************************
 * Global Macros
 **********************************************************************/

/* _BIT(n) sets the bit at position "n"
 * _BIT(n) is intended to be used in "OR" and "AND" expressions:
 * e.g., "(_BIT(3) | _BIT(7))".
 */
#ifdef _BIT
#undef _BIT
#endif
#define _BIT(n)	(((U32)(1)) << (n))

#ifdef __cplusplus
}
#endif

#endif/*~_DATA_TYPE_H*/

