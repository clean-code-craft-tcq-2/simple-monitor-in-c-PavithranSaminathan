#include "BMS.h"
#include "TempMonitor.h"
#include "PrintLanguage.h"
#include "SOCMonitor.h"
#include "ChargeRateMonitor.h"

#include <assert.h>

bool batteryIsOk(float ATemp_F,float Asoc_F, float AChargeRate_F,
                 bool (*SOCPrintWarning_FP)(float), bool (*SOCPrintAlarm_FP)(float),
                 bool (*TempPrintWarning_FP)(float), bool (*TempPrintAlarm_FP)(float),
                 bool (*CheckChargeRatePrintWarning_FP)(float), bool (*CheckChargeRatePrintAlarm_FP)(float)
                )
{
      return (CheckSOC(Asoc_F,SOCPrintWarning_FP,SOCPrintAlarm_FP) &&
              CheckChargeRate(AChargeRate_F,CheckChargeRatePrintWarning_FP,CheckChargeRatePrintAlarm_FP) &&
              CheckTemperatureRange(ATemp_F,TempPrintWarning_FP,TempPrintAlarm_FP));
}

bool Test_BatteryIsOk(float ATemp_F,float Asoc_F, float AChargeRate_F,bool Expected_Result)
{
 bool Test_Result;
 Test_Result= batteryIsOk(ATemp_F,Asoc_F,AChargeRate_F,
                          SOCPrintWarning_FP,SOCPrintAlarm_FP,
                          TempPrintWarning_FP,TempPrintAlarm_FP,
                          CheckChargeRatePrintWarning_FP,CheckChargeRatePrintAlarm_FP);
  
  assert(Expected_Result == Test_Result);
}

int main() 
{ 
  #if(WORK_ENVIRONMENT == PRODUCTION)
  
  batteryIsOk(25,70,0.7,SOCPrintWarning_FP,SOCPrintAlarm_FP,TempPrintWarning_FP,TempPrintAlarm_FP,CheckChargeRatePrintWarning_FP,CheckChargeRatePrintAlarm_FP);
  
  #endif
  
  
  #if(WORK_ENVIRONMENT == TEST)
  
  /*Assert function to check batteryIsOk function */
  Test_BatteryIsOk(25,70,0.7,TRUE);
 
  /*Assert function to check SOC function*/    
  Test_CheckSOC(19,FALSE);
  Test_CheckSOC(20,TRUE);
  Test_CheckSOC(45,TRUE);
  Test_CheckSOC(79,TRUE);
  Test_CheckSOC(81,FALSE);
  
  Test_SOCPrintWarning(19,TRUE);
  Test_SOCPrintWarning(20,TRUE);
  Test_SOCPrintWarning(50,FALSE);
  
  Test_SOCPrintAlarm(19,FALSE);
  Test_SOCPrintAlarm(30,TRUE);
  Test_SOCPrintAlarm(85,FALSE);
  
  /*Assert function to check Temperature_Range function*/
  Test_CheckTemperatureRange(12,TRUE);
  Test_CheckTemperatureRange(47,FALSE);
  
  Test_TempPrintAlarm(47,FALSE);
  
  Test_TempPrintWarning(47,TRUE);
  
  /*Assert function to check ChargeRate function*/  
  Test_CheckChargeRate(0.7,TRUE);
  Test_CheckChargeRatePrintAlarm(0.7,TRUE);
  Test_CheckChargeRatePrintWarning(1,TRUE);
  
  #endif
  return 0;
}


