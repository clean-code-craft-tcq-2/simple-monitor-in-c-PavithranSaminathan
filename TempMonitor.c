#include "TempMonitor.h"

bool (*TempPrintWarning_FP)(float ATemp_F)=TempPrintWarning;
bool (*TempPrintAlarm_FP)(float ATemp_F)=TempPrintAlarm;

bool TempPrintWarning(float ATemp_F)
{
  if(((TEMP_LOW_THRESHOLD + TEMP_WARNING_TOLERANCE) > ATemp_F) || ((TEMP_HIGH_THRESHOLD - TEMP_WARNING_TOLERANCE) < ATemp_F))
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
  if((TEMP_LOW_THRESHOLD > ATemp_F) || (TEMP_HIGH_THRESHOLD < ATemp_F))
  {
    PrintData(Alarm[0]);
    return FALSE;
  }
  else
  {
    return TRUE;
  }
}

/*To check Temperature violation */
bool CheckTemperatureRange(float ATemp_F,bool (*TempPrintWarning_FP)(float), bool (*TempPrintAlarm_FP)(float))
{
  if(!TempPrintAlarm_FP(ATemp_F))
  {
    return FALSE;
  }
  else
  {
    TempPrintWarning_FP(ATemp_F);
    return TRUE;
  }
}

#if(WORK_ENVIRONMENT == TEST)

void Test_CheckTemperatureRange(float ATemp_F,bool Expected_Result)
{
  bool Test_Result;
  Test_Result = CheckTemperatureRange(ATemp_F,TempPrintWarning_FP,TempPrintAlarm_FP); 
  assert(Expected_Result == Test_Result);
}

void Test_TempPrintAlarm(float ATemp_F,bool Expected_Result)
{
  bool Test_Result;
  Test_Result = TempPrintAlarm(ATemp_F); 
  assert(Expected_Result == Test_Result);
}

void Test_TempPrintWarning(float ATemp_F,bool Expected_Result)
{
  bool Test_Result;
  Test_Result = TempPrintWarning(ATemp_F); 
  assert(Expected_Result == Test_Result);
}


#endif
