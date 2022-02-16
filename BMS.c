#include "BMS.h"
#include "TempMonitor.h"
#include "PrintLanguage.h"
#include "SOCMonitor.h"
#include "ChargeRateMonitor.h"

#include <assert.h>

#define WORK_ENVIRONMENT TEST


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
  
  
int main() 
{  
  #if(WORK_ENVIRONMENT == TEST)
   /*Assert function to check batteryIsOk function */
  assert(batteryIsOk(25,70,0.7,SOCPrintWarning_FP,SOCPrintAlarm_FP,TempPrintWarning_FP,TempPrintAlarm_FP,CheckChargeRatePrintWarning_FP,CheckChargeRatePrintAlarm_FP));
//   assert(!batteryIsOk(50, 85, 0,Temperature_Range_FP, SOC_FP, ChargeRate_FP));
  
    /*Assert function to check SOC function*/
    assert(CheckSOC(19,SOCPrintWarning_FP,SOCPrintAlarm_FP));
//    assert(SOC(20));
//    assert(SOC(79));
//    assert(SOC(80));
//    assert(!SOC(81));
  
    /*Assert function to check Temperature_Range function*/
    assert(CheckTemperatureRange(0,TempPrintWarning_FP,TempPrintAlarm_FP));
//    assert(Temperature_Range(44));
//    assert(!Temperature_Range(46));
  
    /*Assert function to check ChargeRate function*/
    assert(CheckChargeRate(0.7,CheckChargeRatePrintWarning_FP,CheckChargeRatePrintAlarm_FP));
 //   assert(!ChargeRate(1));
  
  #endif
  return 0;
}


