#include "SOCMonitor.h"
#include <assert.h>


bool (*SOCPrintWarning_FP)(float SOC_F)=SOCPrintWarning;
bool (*SOCPrintAlarm_FP)(float SOC_F)=SOCPrintAlarm;

bool SOCPrintWarning(float SOC_F)
{
if((((SOC_LOW_THRESHOLD + SOC_WARNING_TOLERANCE) > SOC_F) && (SOC_LOW_THRESHOLD < SOC_F))  ||
  ((((SOC_HIGH_THRESHOLD - SOC_WARNING_TOLERANCE) < SOC_F)) && (SOC_HIGH_THRESHOLD  > SOC_F)))
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
  if(!SOCPrintAlarm_FP(SOC_F))
  {
    return FALSE;
  }
  else
  {
    SOCPrintWarning_FP(SOC_F);
    return TRUE;
  }
}

#if(WORK_ENVIRONMENT == TEST)

void Test_CheckSOC(float ASOC,bool Expected_Result)
{
  bool Test_Result;
  Test_Result=CheckSOC(ASOC,SOCPrintWarning_FP,SOCPrintAlarm_FP);
  assert(Expected_Result == Test_Result);
}

bool Test_SOCPrintAlarm(float SOC_F,bool Expected_Result)
{
  bool Test_Result;
  Test_Result =SOCPrintAlarm(SOC_F);
  assert(Expected_Result == Test_Result);
}

bool Test_SOCPrintWarning(float SOC_F,bool Expected_Result)
{
  bool Test_Result;
  Test_Result =SOCPrintWarning(SOC_F);
  assert(Expected_Result == Test_Result);
}


#endif
