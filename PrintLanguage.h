#ifndef PrintLanguage_h
#define PrintLanguage_h

#include <stdio.h>

#define ENGLISH   1
#define GERMAN    2

#define LANGUAGE GERMAN

extern const char *Notify[];
extern const char *Alarm[];

extern void PrintData(const char *data);

#endif
