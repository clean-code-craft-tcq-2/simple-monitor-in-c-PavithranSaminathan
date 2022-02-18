/** INCLUDES **/
#include "ChargeRateMonitor.h"
#include <assert.h>

bool (*CheckChargeRatePrintWarning_FP)(float chargeRate_F)=CheckChargeRatePrintWarning;
bool (*CheckChargeRatePrintAlarm_FP)(float chargeRate_F)=CheckChargeRatePrintAlarm;


/** Brief :- This function print warning message if charge rate exceeds 0.6*/

bool CheckChargeRatePrintWarning(float chargeRate_F)
{
   if((DEFAULT_CHARGE_RATE - TOLERANCE_CHARGE_RATE)< chargeRate_F )
  {
    PrintData(Notify[2]);
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

/** Brief :- This function print alarm message if charge rate exceeds 0.8*/

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

/** Brief :- This function will print alarm or warning message based on input charget rate value*/

bool CheckChargeRate(float chargeRate_F,bool (*CheckChargeRatePrintWarning_FP)(float), bool (*CheckChargeRatePrintAlarm_FP)(float))
{
  if(!CheckChargeRatePrintAlarm_FP(chargeRate_F))
  {
    return FALSE;
  }
  else
  {
     CheckChargeRatePrintWarning_FP(chargeRate_F);
     return TRUE;
  }
}


#if(WORK_ENVIRONMENT == TEST)

/** Brief :- This test function will check CheckChargeRate output*/

bool Test_CheckChargeRate(float chargeRate_F,bool Expected_Result )
{
   bool Test_Result;
   Test_Result=CheckChargeRate( chargeRate_F,CheckChargeRatePrintWarning_FP,CheckChargeRatePrintAlarm_FP);
   assert(Expected_Result == Test_Result);
}

/** Brief :- This test function will check CheckChargeRatePrintAlarm output*/

bool Test_CheckChargeRatePrintAlarm(float chargeRate_F,bool Expected_Result )
{
   bool Test_Result;
   Test_Result=CheckChargeRatePrintAlarm(chargeRate_F);
   assert(Expected_Result == Test_Result);
}

/** Brief :- This test function will check CheckChargeRatePrintWarning output*/

bool Test_CheckChargeRatePrintWarning(float chargeRate_F,bool Expected_Result )
{
   bool Test_Result;
   Test_Result=CheckChargeRatePrintWarning(chargeRate_F);
   assert(Expected_Result == Test_Result);
}

#endif
