#ifndef _INCLUDED_FACTIONHISTORY_H
#define _INCLUDED_FACTIONHISTORY_H

#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    int from_id;
    int to_id;
} FactionHistoryHeader_t;

typedef struct
{
    int type;
    int id;
    __time32_t timestamp;
    int who;
    int params[3];
} FactionHistoryRecord_t;

inline bool IsValidFactionHistorySign(const FactionHistoryHeader_t *header)
{
    return header->from_id <= header->to_id || (header->from_id == -1 && header->to_id == -2);
}

#endif // _INCLUDED_FACTIONHISTORY_H