#ifndef _INCLUDED_DECODER_H
#define _INCLUDED_DECODER_H

#include "FactionHistory.h"

void Decode(
    char *action,
    size_t action_size,
    char *description,
    size_t description_size,
    const FactionHistoryRecord_t *record
);

#endif // _INCLUDED_DECODER_H