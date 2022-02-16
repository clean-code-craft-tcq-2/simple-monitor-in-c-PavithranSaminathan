#include "BMS.h"
#include "TempMonitor.h"
#include "PrintLanguage.h"

#include <assert.h>


bool SOCPrintWarning(float SOC_F)
{
if(((SOC_LOW_THRESHOLD + SOC_WARNING_TOLERANCE) > SOC_F) || ((SOC_HIGH_THRESHOLD - SOC_WARNING_TOLERANCE ) < SOC_F))
  {
    PrintData(Notify[1]);
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

bool SOCPrintAlarm(float SOC_F)
{
if((SOC_LOW_THRESHOLD > SOC_F) || (SOC_HIGH_THRESHOLD < SOC_F))
  {
    PrintData(Alarm[1]);
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}


/*To check State of Charge violation */
bool CheckSOC(float SOC_F,bool (*SOCPrintWarning_FP)(float), bool (*SOCPrintAlarm_FP)(float))
{
  if(SOCPrintWarning_FP(SOC_F))
  {
    return 1;
  }
  else
  {
    return(SOCPrintAlarm_FP(SOC_F));
  }
}


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

//bool batteryIsOk(float ATemp_F,float Asoc_F, float AChargeRate_F,bool (*Temperature_Range_FP)(float) , bool (*SOC_FP)(float) , bool(*ChargeRate_FP)(float)) 
//{    
//  return (Temperature_Range_FP(ATemp_F) && SOC_FP(Asoc_F) && ChargeRate_FP(AChargeRate_F));   
//}

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
  

bool (*SOCPrintWarning_FP)(float SOC_F)=SOCPrintWarning;
bool (*SOCPrintAlarm_FP)(float SOC_F)=SOCPrintAlarm;
bool (*CheckChargeRatePrintWarning_FP)(float chargeRate_F)=CheckChargeRatePrintWarning;
bool (*CheckChargeRatePrintAlarm_FP)(float chargeRate_F)=CheckChargeRatePrintAlarm;

//bool (*Temperature_Range_FP)(float)= CheckTemperatureRange;
//bool (*SOC_FP)(float)=CheckSOC;
//bool (*ChargeRate_FP)(float) = CheckChargeRate;
  
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
  
  return 0;
}


