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

void _DecodeFactionRole(char *buffer, size_t size, int role);

/**
 * Processor implementations
 */

void Processor_WriteHeader(FILE *dst)
{
    fprintf(dst, "ID\tДАТА\tИГРОК\tДЕЙСТВИЕ\tП0\tП1\tП2\tОПИСАНИЕ\n");
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
        record->params[0],
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
            strcpy_s(action, action_size, "Получает предмет");
            sprintf_s(description, description_size, "Игрок {role_id:%i} получает предмет {item_id:%i}.",
                record->who,
                record->params[0]
            );
            break;

        case 1:
            strcpy_s(action, action_size, "Вносит вклад (доблесть)");
            sprintf_s(description, description_size, "Игрок {role_id:%i} вносит вклад %i очков доблести.",
                record->who,
                record->params[0]
            );
            break;

        case 2:
            strcpy_s(action, action_size, "Вносит вклад (золото)");
            sprintf_s(description, description_size, "Игрок {role_id:%i} вносит вклад %i золота гильдии.",
                record->who,
                record->params[0]
            );
            break;

        case 5:
            strcpy_s(action, action_size, "Приглашает игрока");
            sprintf_s(description, description_size, "Игрок {role_id:%i} приглашает игрока {role_id:%i} в гильдию.",
                record->who,
                record->params[0]
            );
            break;

        case 6:
            strcpy_s(action, action_size, "Вступает в гильдию");
            sprintf_s(description, description_size, "Игрок {role_id:%i} вступает в гильдию.",
                record->who
            );
            break;

        case 7:
            strcpy_s(action, action_size, "Отказывается вступить в гильдию");
            sprintf_s(description, description_size, "Игрок {role_id:%i} отказывается вступить в гильдию.",
                record->who
            );
            break;

        case 8:
            strcpy_s(action, action_size, "Покидает гильдию");
            sprintf_s(description, description_size, "Игрок {role_id:%i} покидает гильдию.",
                record->who
            );
            break;

        case 9:
            char role[64];
            _DecodeFactionRole(role, sizeof(role), record->params[1]);

            strcpy_s(action, action_size, "Изменяет должность");
            sprintf_s(description, description_size, "Игрок {role_id:%i} %s игрока {role_id:%i} до должности %s.",
                record->who,
                record->params[2] == 1 ? "повышает" : "понижает",
                record->params[0],
                role
            );
            break;

        case 10:
            strcpy_s(action, action_size, "Изгоняет игрока");
            sprintf_s(description, description_size, "Игрок {role_id:%i} изгоняет игрока {role_id:%i} из гильдии.",
                record->who,
                record->params[0]
            );
            break;

        default:
            sprintf_s(action, action_size, "Неизвестное действие %i", record->type);
    }
}

void _DecodeFactionRole(char *buffer, size_t size, int role)
{
    buffer[0] = 0;

    switch (role)
    {
    case 2:
        strcpy_s(buffer, size, "Мастер");
        break;

    case 3:
        strcpy_s(buffer, size, "Маршал");
        break;

    case 4:
        strcpy_s(buffer, size, "Майор");
        break;

    case 5:
        strcpy_s(buffer, size, "Капитан");
        break;

    case 6:
        strcpy_s(buffer, size, "Рядовой");
        break;

    default:
        sprintf_s(buffer, size, "Неизвестная должность %i", role);
    }
}