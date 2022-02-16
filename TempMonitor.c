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
  if(TempPrintWarning_FP(ATemp_F))
  {
    return TRUE;
  }
  else
  {
    return(TempPrintAlarm_FP(ATemp_F));
  }
}
