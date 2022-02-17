#include "PrintLanguage.h"

#if(LANGUAGE == ENGLISH)
const char *Notify[] ={"TEMPERATURE ALERT",
                     "SOC ALERT",
                     "CHARGE ALERT"
                    };
const char *Alarm[] ={"TEMPERATURE OUT OF RANGE",
                     "SOC OUT OF RANGE ",
                     "CHARGE RATE TOO LOW"
                    };
#elif(LANGUAGE == GERMAN)
const char *Notify[] ={"TEMPERATURALARM",
                     "SOC-ALARM",
                     "LADEZAHLALARM"
                    };
const char *Alarm[] ={"TEMPERATUR AUSSERHALB DES BEREICHS",
                     "SOC AUSSERHALB DER REICHWEITE",
                     "LADESTUFE ZU NIEDRIG"
                    };
#endif

/** This function Print output data **/

void PrintData(const char *data)
{
  printf("%s\n",data);
}
