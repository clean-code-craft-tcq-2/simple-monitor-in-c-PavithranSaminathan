#ifndef BMS_H
#define BMS_H

#include <stdio.h>

typedef unsigned char  bool;

#define TRUE     1
#define FALSE    0

#define WORK_ENVIRONMENT TEST

#if(WORK_ENVIRONMENT==TEST)

extern void Test_CheckSOC(float ASOC,bool Expected_Result);
extern bool Test_SOCPrintWarning(float SOC_F,bool Expected_Result);
extern bool Test_SOCPrintAlarm(float SOC_F,bool Expected_Result);

extern void Test_CheckTemperatureRange(float ATemp_F,bool Expected_Result);
extern void Test_TempPrintAlarm(float ATemp_F,bool Expected_Result);
extern void Test_TempPrintWarning(float ATemp_F,bool Expected_Result);

extern bool Test_CheckChargeRate(float chargeRate_F,bool Expected_Result );
extern bool Test_CheckChargeRatePrintAlarm(float chargeRate_F,bool Expected_Result );
bool Test_CheckChargeRatePrintWarning(float chargeRate_F,bool Expected_Result );

#endif

#endif
