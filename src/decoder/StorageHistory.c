#include "decoder.h"
#include <stdio.h>
#include <string.h>

void Decode(
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
                "Игрок {role_id:%i} помещает на склад гильдии №%i %i шт. предмета {item_id:%i}",
                record->who,
                record->params[0] + 1,
                record->params[2],
                record->params[1]
            );
            break;

        case 1:
            strcpy_s(action, action_size, "Получает");
            sprintf_s(
                description,
                description_size,
                "Игрок {role_id:%i} получает со склада гильдии №%i %i шт. предмета {item_id:%i}",
                record->who,
                record->params[0] + 1,
                record->params[2],
                record->params[1]
            );
            break;

        default:
            sprintf_s(action, action_size, "Неизвестное действие %i", record->type);
    }
}
