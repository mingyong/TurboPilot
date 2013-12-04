/*
 * uavsettings.h
 * 用于自驾仪参数加载和保持
 */
#ifndef _UAV_SETTINGS_H_
#define _UAV_SETTINGS_H_

#include "datatype.h"

extern void UavSetting_Init(void);
extern void UavSetting_Load(void);
extern void UavSetting_Save(void);

#endif /* _UAV_SETTINGS_H_ */
