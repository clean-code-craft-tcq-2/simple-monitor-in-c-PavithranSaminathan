#include "BMS.h"
#include <assert.h>

#define TEMP_WARNING_TOLERANCE  4
#define SOC_WARNING_TOLERANCE   4
#define TOLERANCE_CHARGE_RATE   float(0.2)

/*To check Temperature violation */
int CheckTemperatureRange(float Temp_F )
{
  if((TEMP_LOW_THRESHOLD > Temp_F) || (TEMP_HIGH_THRESHOLD < Temp_F)) 
  {
    printf("Temperature out of range!\n");
    return FALSE;
  }
  else if(((TEMP_LOW_THRESHOLD + TEMP_WARNING_TOLERANCE) > Temp_F) || ((TEMP_HIGH_THRESHOLD - TEMP_WARNING_TOLERANCE) < Temp_F))
  {
    return TRUE;
  }
  else
  {
    return TRUE;
  }
}

/*To check State of Charge violation */
int CheckSOC(float SOC_F)
{
  if((SOC_LOW_THRESHOLD > SOC_F) || (SOC_HIGH_THRESHOLD < SOC_F))
  {
    printf("State of Charge out of range!\n");
    return 0;
  }
    else
  {
    return 1;
  }
}

/*To check ChargeRate violation */
int CheckChargeRate(float chargeRate_F)
{
  if((DEFAULT_CHARGE_RATE + TOLERANCE_CHARGE_RATE)< chargeRate_F )
  {
    
  }
  if(DEFAULT_CHARGE_RATE < chargeRate_F)
  {
    printf("Charge Rate out of range!\n");
    return 0;
  }
    else
  {
    return 1;
  }
}

int batteryIsOk(float ATemp_F,float Asoc_F, float AChargeRate_F,int (*Temperature_Range_FP)(float) , int (*SOC_FP)(float) , int(*ChargeRate_FP)(float)) 
{    
  return (Temperature_Range_FP(ATemp_F) && SOC_FP(Asoc_F) && ChargeRate_FP(AChargeRate_F));   
}

int main() 
{  
  int (*Temperature_Range_FP)(float)= CheckTemperatureRange;
  int (*SOC_FP)(float)=CheckSOC;
  int(*ChargeRate_FP)(float) = CheckChargeRate;
  
    /*Assert function to check batteryIsOk function */
   assert(batteryIsOk(25,70,0.7,Temperature_Range_FP, SOC_FP, ChargeRate_FP));
   assert(!batteryIsOk(50, 85, 0,Temperature_Range_FP, SOC_FP, ChargeRate_FP));
  
    /*Assert function to check SOC function*/
    assert(!SOC(19));
    assert(SOC(20));
    assert(SOC(79));
    assert(SOC(80));
    assert(!SOC(81));
  
    /*Assert function to check Temperature_Range function*/
    assert(Temperature_Range(0));
    assert(Temperature_Range(44));
    assert(!Temperature_Range(46));
  
    /*Assert function to check ChargeRate function*/
    assert(ChargeRate(0.7));
    assert(!ChargeRate(1));
  
  return 0;
}
