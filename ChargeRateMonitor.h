#ifndef ChargeRateMonitor_h
#define ChargeRateMonitor_h

#include "BMS.h"
#include "PrintLanguage.h"

#define TOLERANCE_CHARGE_RATE  (float)0.2
#define DEFAULT_CHARGE_RATE    (float)0.8

bool (*CheckChargeRatePrintWarning_FP)(float chargeRate_F);
bool (*CheckChargeRatePrintAlarm_FP)(float chargeRate_F);

bool CheckChargeRatePrintWarning(float chargeRate_F);
bool CheckChargeRatePrintAlarm(float chargeRate_F);
extern bool CheckChargeRate(float chargeRate_F,bool (*CheckChargeRatePrintWarning_FP)(float), bool (*CheckChargeRatePrintAlarm_FP)(float));

#endif
