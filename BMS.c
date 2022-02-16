#include "BMS.h"
#include <assert.h>

#define LANGUAGE ENGLISH

#if(LANGUAGE == ENGLISH)
const char *Notify[] ={"TEMPERATURE ALERT",
                     "SOC ALERT",
                     "CHARGE ALERT"
                    };
const char *Warning[] ={"TEMPERATURE OUT OF RANGE",
                     "SOC OUT OF RANGE ",
                     "CHARGE RATE TOO LOW"
                    };
#elif(LANGUAGE == GERMAN)
const char *Notify[] ={"TEMPERATURALARM",
                     "SOC-ALARM",
                     "LADEZAHLALARM"
                    };
const char *Warning[] ={"TEMPERATUR AUSSERHALB DES BEREICHS",
                     "SOC AUSSERHALB DER REICHWEITE",
                     "LADESTUFE ZU NIEDRIG"
                    };
#endif



void PrintData(const char *data)
{
  printf("%s\n",data);
}

bool TempPrintWarning(float ATemp_F)
{
  if((TEMP_LOW_THRESHOLD > ATemp_F) || (TEMP_HIGH_THRESHOLD < ATemp_F)) 
  {
    PrintData(Notify[0]);
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

bool TempPrintAlarm(float ATemp_F)
{
  if(((TEMP_LOW_THRESHOLD + TEMP_WARNING_TOLERANCE) > ATemp_F) || ((TEMP_HIGH_THRESHOLD - TEMP_WARNING_TOLERANCE) < ATemp_F))
  {
    PrintData(Warning[0]);
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

/*To check Temperature violation */
bool CheckTemperatureRange(float ATemp_F,bool (*PrintWarning_FP)(float ATemp_F), bool (*PrintAlarm_FP)(float ATemp_F))
{
  if(PrintWarning_FP(ATemp_F))
  {
    return TRUE;
  }
  else
  {
    return(PrintAlarm_FP(ATemp_F));
  }
}

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
    PrintData(Warning[1]);
    return TRUE;
  }
  else
  {
    return FALSE;
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
    PrintData(Warning[2]);
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

/*To check ChargeRate violation */
bool CheckChargeRate(float chargeRate_F,bool (*CheckChargeRatePrintWarning_FP)(float chargeRate_F), bool (*CheckChargeRatePrintAlarm_FP)(float chargeRate_F))
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

bool batteryIsOk(float ATemp_F,float Asoc_F, float AChargeRate_F)
{
  return (CheckSOC(Asoc_F,SOCPrintWarning_FP,SOCPrintAlarm_FP) && CheckTemperatureRange(ATemp_F,PrintWarning_FP,PrintAlarm_FP)&& CheckChargeRate(AChargeRate_F,CheckChargeRatePrintWarning_FP,CheckChargeRatePrintAlarm_FP));
}
  
  
int main() 
{  
  
bool (*PrintWarning_FP)(float ATemp_F)=TempPrintAlarm;
bool (*PrintAlarm_FP)(float ATemp_F)=TempPrintWarning;
bool (*SOCPrintWarning_FP)(float SOC_F)=SOCPrintWarning;
bool (*SOCPrintAlarm_FP)(float SOC_F)=SOCPrintAlarm;
bool (*CheckChargeRatePrintWarning_FP)(float chargeRate_F)=CheckChargeRatePrintWarning;
bool (*CheckChargeRatePrintAlarm_FP)(float chargeRate_F)=CheckChargeRatePrintAlarm;

//bool (*Temperature_Range_FP)(float)= CheckTemperatureRange;
//bool (*SOC_FP)(float)=CheckSOC;
//bool (*ChargeRate_FP)(float) = CheckChargeRate;
  
    /*Assert function to check batteryIsOk function */
  assert(batteryIsOk(25,70,0.7));
//   assert(!batteryIsOk(50, 85, 0,Temperature_Range_FP, SOC_FP, ChargeRate_FP));
  
    /*Assert function to check SOC function*/
//    assert(!SOC(19));
//    assert(SOC(20));
//    assert(SOC(79));
//    assert(SOC(80));
//    assert(!SOC(81));
  
    /*Assert function to check Temperature_Range function*/
//    assert(Temperature_Range(0));
//    assert(Temperature_Range(44));
//    assert(!Temperature_Range(46));
  
    /*Assert function to check ChargeRate function*/
 //   assert(ChargeRate(0.7));
 //   assert(!ChargeRate(1));
  
  return 0;
}
