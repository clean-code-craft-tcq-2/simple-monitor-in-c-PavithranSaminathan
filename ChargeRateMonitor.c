#include "ChargeRateMonitor.h"

bool (*CheckChargeRatePrintWarning_FP)(float chargeRate_F)=CheckChargeRatePrintWarning;
bool (*CheckChargeRatePrintAlarm_FP)(float chargeRate_F)=CheckChargeRatePrintAlarm;

bool CheckChargeRatePrintWarning(float chargeRate_F)
{
   if((DEFAULT_CHARGE_RATE - TOLERANCE_CHARGE_RATE)< chargeRate_F && (DEFAULT_CHARGE_RATE > chargeRate_F ))
  {
    PrintData(Notify[2]);
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

bool CheckChargeRatePrintAlarm(float chargeRate_F)
{
   if(DEFAULT_CHARGE_RATE < chargeRate_F )
  {
    PrintData(Alarm[2]);
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}

/*To check ChargeRate violation */
bool CheckChargeRate(float chargeRate_F,bool (*CheckChargeRatePrintWarning_FP)(float), bool (*CheckChargeRatePrintAlarm_FP)(float))
{
  if(CheckChargeRatePrintWarning_FP(chargeRate_F))
  {
    return TRUE;
  }
  else
  {
    return (CheckChargeRatePrintAlarm_FP(chargeRate_F));
  }
}
