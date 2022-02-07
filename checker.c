#include <stdio.h>
#include <assert.h>

#define TEMP_LOW_THRESHOLD     (float)0U
#define TEMP_HIGH_THRESHOLD   (float)45U

#define SOC_LOW_THRESHOLD     (float)20U
#define SOC_HIGH_THRESHOLD    (float)80U

#define DEFAULT_CHARGE_RATE   (float)0.8

int Temperature_Range(float Temp_F )
{
  if((TEMP_LOW_THRESHOLD > Temp_F) || (TEMP_HIGH_THRESHOLD < Temp_F)) 
  {
    printf("Temperature out of range!\n");
    return 0;
  }
}

int SOC(float SOC_F)
{
  if((SOC_LOW_THRESHOLD > SOC_F) || (SOC_HIGH_THRESHOLD < SOC_F))
  {
    printf("State of Charge out of range!\n");
    return 0;
  } 
}

int ChargeRate(float chargeRate_F)
{
  if(DEFAULT_CHARGE_RATE < chargeRate_F)
  {
    printf("Charge Rate out of range!\n");
    return 0;
  } 
}

int batteryIsOk(int (*Temperature_Range_FP)(float temp_F) , int (*SOC_FP)(float soc_F) , int(*ChargeRate_FP)(float ChargeRate_F) ) 
{    
  return (Temperature_Range_FP(temp_F) && SOC_FP(soc_F) && ChargeRate_FP(ChargeRate_F));   
}

int main() {
  
  int (*Temperature_Range_FP)(float)= Temperature_Range;
  int (*SOC_FP)(float)=SOC;
  int(*ChargeRate_FP)(float) = ChargeRate;
  
  
    assert(batteryIsOk(Temperature_Range(25), SOC(70), ChargeRate(0.7)));
//  assert(!batteryIsOk(50, 85, 0));
}
