#ifndef _INCLUDED_PROCESSOR_H
#define _INCLUDED_PROCESSOR_H

#define DT_FORMAT   "%d.%m.%Y %T"

#include <stdio.h>
#include "FactionHistory.h"

void Processor_WriteHeader(FILE *dst);
void Processor_WriteRow(FILE *dst, const FactionHistoryRecord_t *record);

#endif // _INCLUDED_PROCESSOR_H