#ifndef BMS_H
#define BMS_H

#include <stdio.h>

typedef unsigned char  bool;

#define TRUE     1
#define FALSE    0

#define TEMP_WARNING_TOLERANCE  4
#define TEMP_LOW_THRESHOLD     (float)0U
#define TEMP_HIGH_THRESHOLD    (float)45U

#define SOC_WARNING_TOLERANCE   4
#define SOC_LOW_THRESHOLD     (float)20U
#define SOC_HIGH_THRESHOLD    (float)80U

#define TOLERANCE_CHARGE_RATE   float(0.2)
#define DEFAULT_CHARGE_RATE   (float)0.8

int (*Temperature_Range_FP)(float);
int (*SOC_FP)(float);
int(*ChargeRate_FP)(float);

#endif
