#ifndef TempMonitor_H
#define TempMonitor_H

#include "PrintLanguage.h"

#define TEMP_WARNING_TOLERANCE  4
#define TEMP_LOW_THRESHOLD     (float)0U
#define TEMP_HIGH_THRESHOLD    (float)45U

bool TempPrintWarning(float ATemp_F);
bool TempPrintAlarm(float ATemp_F);

extern bool CheckTemperatureRange(float ATemp_F,bool (*TempPrintWarning_FP)(float), bool (*TempPrintAlarm_FP)(float));

bool (*TempPrintWarning_FP)(float ATemp_F);
bool (*TempPrintAlarm_FP)(float ATemp_F);

#endif
