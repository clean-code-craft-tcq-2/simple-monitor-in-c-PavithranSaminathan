#ifndef BMS_H
#define BMS_H

#include <stdio.h>

typedef unsigned char  bool;

#define TRUE     1
#define FALSE    0

#define TOLERANCE_CHARGE_RATE  (float)0.2
#define DEFAULT_CHARGE_RATE    (float)0.8

bool (*CheckChargeRatePrintWarning_FP)(float chargeRate_F);
bool (*CheckChargeRatePrintAlarm_FP)(float chargeRate_F);

#endif
