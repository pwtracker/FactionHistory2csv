#define error(...) sprintf_s(error_msg, sizeof(error_msg), __VA_ARGS__)

#include <stdio.h>
#include <stdlib.h>
#include "FactionHistory.h"
#include "Processor.h"

void Process(FILE* src, FILE* dst);

int main(int argc, char* argv[])
{
    printf(PROJECT_NAME " v" PROJECT_VERSION " by " PROJECT_CREDITS "\n\n");

    char error_msg[256] = "\0";

    if (argc > 1)
    {
        FILE* src = fopen(argv[1], "rb");

        if (src != NULL)
        {
            FactionHistoryHeader_t header;

            if (fread(&header, sizeof(header), 1, src) == 1 && IsValidFactionHistorySign(&header))
            {
                char dst_path[256];
                sprintf_s(dst_path, sizeof(dst_path), "%s.csv", argv[1]);

                FILE* dst = fopen(dst_path, "w+");

                if (dst != NULL)
                {
                    Process(src, dst);

                    fclose(dst);
                }
                else
                {
                    error("failed to create the csv table");
                }
            }
            else
            {
                error("invalid binary file");
            }

            fclose(src);
        }
        else
        {
            error("failed to open the binary file");
        }
    }
    else
    {
        error("incorrect usage, just drag and drop the binary file");
    }

    if (error_msg[0])
    {
        fprintf(stderr, "Error: %s.\n\n", error_msg);
        system("pause");
        return -1;
    }

    return 0;
}

void Process(FILE* src, FILE* dst)
{
    Processor_WriteHeader(dst);

    FactionHistoryRecord_t record;
    int prev_id = -1;

    while (fread(&record, sizeof(record), 1, src) == 1 && record.id >= prev_id)
    {
        Processor_WriteRow(dst, &record);

        prev_id = record.id;
    }
}
