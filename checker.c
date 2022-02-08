#include <BMS.h>
#include <assert.h>


int Temperature_Range(float Temp_F )
{
  if((TEMP_LOW_THRESHOLD > Temp_F) || (TEMP_HIGH_THRESHOLD < Temp_F)) 
  {
    printf("Temperature out of range!\n");
    return 0;
  }
  else
  {
    return 1;
  }
}

int SOC(float SOC_F)
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

int ChargeRate(float chargeRate_F)
{
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
  int (*Temperature_Range_FP)(float)= Temperature_Range;
  int (*SOC_FP)(float)=SOC;
  int(*ChargeRate_FP)(float) = ChargeRate;
  
  
    assert(batteryIsOk(25,70,0.7,Temperature_Range_FP, SOC_FP, ChargeRate_FP));
//  assert(!batteryIsOk(50, 85, 0));

  return 0;
}
