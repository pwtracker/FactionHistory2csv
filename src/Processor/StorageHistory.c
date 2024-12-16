#include "Processor.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * Custom declarations
 */

void _Decode(
    char *action,
    size_t action_size,
    char *description,
    size_t description_size,
    const FactionHistoryRecord_t *record
);

/**
 * Processor implementations
 */

void Processor_WriteHeader(FILE *dst)
{
    fprintf(dst, "ID\tДАТА\tИГРОК\tДЕЙСТВИЕ\tСКЛАД\tПРЕДМЕТ\tКОЛ-ВО\tОПИСАНИЕ\n");
}

void Processor_WriteRow(FILE *dst, const FactionHistoryRecord_t *record)
{
    struct tm* timestamp = _localtime32(&record->timestamp);

    if (timestamp == NULL)
    {
        return;
    }

    char datetime[32];
    strftime(datetime, sizeof(datetime), DT_FORMAT, timestamp);

    char action[128], description[256];
    _Decode(action, sizeof(action), description, sizeof(description), record);

    fprintf(dst, "%i\t%s\t%i\t%s\t%i\t%i\t%i\t%s\n",
        record->id,
        datetime,
        record->who,
        action,
        record->params[0] + 1,
        record->params[1],
        record->params[2],
        description
    );
}

/**
 * Custom implementations
 */

void _Decode(
    char *action,
    size_t action_size,
    char *description,
    size_t description_size,
    const FactionHistoryRecord_t *record
)
{
    action[0] = 0;
    description[0] = 0;

    switch (record->type)
    {
        case 0:
            strcpy_s(action, action_size, "Помещает");
            sprintf_s(
                description,
                description_size,
                "Игрок {role_id:%i} помещает на склад №%i {item_id:%i} x%i",
                record->who,
                record->params[0] + 1,
                record->params[1],
                record->params[2]
            );
            break;

        case 1:
            strcpy_s(action, action_size, "Получает");
            sprintf_s(
                description,
                description_size,
                "Игрок {role_id:%i} получает со склада №%i {item_id:%i} x%i",
                record->who,
                record->params[0] + 1,
                record->params[1],
                record->params[2]
            );
            break;

        default:
            sprintf_s(action, action_size, "Неизвестное действие %i", record->type);
    }
}
