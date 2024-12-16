#include "Processor.h"
#include <stdio.h>

/**
 * Processor implementations
 */

void Processor_WriteHeader(FILE *dst)
{
    fprintf(dst, "id\ttimestamp\twho\ttype\tparams0\tparams1\tparams2\n");
}

void Processor_WriteRow(FILE *dst, const FactionHistoryRecord_t *record)
{
    fprintf(dst, "%i\t%i\t%i\t%i\t%i\t%i\t%i\n",
        record->id,
        record->timestamp,
        record->who,
        record->type,
        record->params[0],
        record->params[1],
        record->params[2]
    );
}
