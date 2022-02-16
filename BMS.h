#ifndef BMS_H
#define BMS_H

#include <stdio.h>

typedef unsigned char  bool;

#define TRUE     1
#define FALSE    0

#define WORK_ENVIRONMENT TEST

#if(WORK_ENVIRONMENT==TEST)

Test_CheckSOC(float ASOC,bool Expected_Result);

#endif

#endif
