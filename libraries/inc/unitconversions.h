/**
 ******************************************************************************
 *
 * @file       UnitConverions.h
 * @author     WLH<wanglehui8357@163.com>
 * @brief      Header for unit conversions library in UnitConverions.c
 *
 *****************************************************************************
 */

#ifndef _UNIT_CONVERSIONS_H_
#define _UNIT_CONVERSIONS_H_

#include "datatype.h"

#define M_PI          3.14159265358979323846
#define RAD2DEG       (180.0/M_PI)
#define DEG2RAD       (M_PI/180.0)

#define M_PI_F        3.14159265358979323846f
#define RAD2DEG_F     (180.0f/M_PI_F)
#define DEG2RAD_F     (M_PI_F/180.0f)

// 弧度和度之间的转换公式
__inline FP64 Rad2Deg(FP64 rad) { return rad * RAD2DEG; }
__inline FP64 Deg2Rad(FP64 deg) { return deg * DEG2RAD; }
__inline FP32 Rad2Deg_F(FP32 rad) { return rad * RAD2DEG_F; }
__inline FP32 Deg2Rad_F(FP32 deg) { return deg * DEG2RAD_F; }

// 公制和英制之间换算公式
__inline FP64 Feet2Meter(FP64 val) { return 0.3048 * val; }
__inline FP64 Meter2Feet(FP64 val) { return val / 0.3048; }
__inline FP32 Feet2Meter_F(FP32 val) { return 0.3048f * val; }
__inline FP32 Meter2Feet_F(FP32 val) { return val / 0.3048f; }

// 速度单位转换公式
// 从km/h到ft/s;
__inline FP64 Kmph2Ftps(FP64 val) { return (val / 0.3048 / 3.6); }
// 从ft/s到km/h;
__inline FP64 Ftps2Kmph(FP64 val) { return (3.6 * 0.3048 * (val)); }
// 从kts(节)到ft/s;
__inline FP64 Kts2Ftps(FP64 val) { return (1852.0 / 3600.0 / 0.3048 * val); }
// 从ft/s到kts(节);
__inline FP64 Ftps2Kts(FP64 val) { return (3600.0 * 0.3048 / 1852 * val); }
// 从kts(节)到km/h;
__inline FP64 Kts2Kmph(FP64 val) { return (1.852 * val); }
// 从km/h到kts(节);
__inline FP64 Kmph2Kts(FP64 val) { return (val / 1.852); }
// 从km/h到m/s
__inline FP64 Kmph2Mps(FP64 val) { return (val / 3.6); }
// 从m/s到km/h
__inline FP64 Mps2Kmph(FP64 val) { return (val * 3.6); }
// 从m/s到ft/s
__inline FP64 Mps2Fts(FP64 val) { return Meter2Feet(val); }

// 从km/h到ft/s;
__inline FP32 Kmph2Ftps_F(FP32 val) { return (val / 0.3048f / 3.6f); }
// 从ft/s到km/h;
__inline FP32 Ftps2Kmph_F(FP32 val) { return (3.6f * 0.3048f * (val)); }
// 从kts(节)到ft/s;
__inline FP32 Kts2Ftps_F(FP32 val) { return (1852.0f / 3600.0f / 0.3048f * val); }
// 从ft/s到kts(节);
__inline FP32 Ftps2Kts_F(FP32 val) { return (3600.0f * 0.3048f / 1852 * val); }
// 从kts(节)到km/h;
__inline FP32 Kts2Kmph_F(FP32 val) { return (1.852f * val); }
// 从km/h到kts(节);
__inline FP32 Kmph2Kts_F(FP32 val) { return (val / 1.852f); }
// 从km/h到m/s
__inline FP32 Kmph2Mps_F(FP32 val) { return (val / 3.6f); }
// 从m/s到km/h
__inline FP32 Mps2Kmph_F(FP32 val) { return (val * 3.6f); }
// 从m/s到ft/s
__inline FP32 Mps2Fts_F(FP32 val) { return Meter2Feet_F(val); }

//extern U32 GpsTimeToUtc();
//extern U32 UtcToGpsTime();

#endif // _UNIT_CONVERSIONS_H_
