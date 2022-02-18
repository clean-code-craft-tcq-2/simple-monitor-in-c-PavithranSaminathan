#ifndef SOCMonitor_H
#define SOCMonitor_H

#include "BMS.h"
#include "PrintLanguage.h"

#define SOC_WARNING_TOLERANCE   4
#define SOC_LOW_THRESHOLD     (float)20U
#define SOC_HIGH_THRESHOLD    (float)80U

bool (*SOCPrintWarning_FP)(float SOC_F);
bool (*SOCPrintAlarm_FP)(float SOC_F);

bool SOCPrintWarning(float SOC_F);
bool SOCPrintAlarm(float SOC_F);

extern bool CheckSOC(float SOC_F,bool (*SOCPrintWarning_FP)(float), bool (*SOCPrintAlarm_FP)(float));


#endif
