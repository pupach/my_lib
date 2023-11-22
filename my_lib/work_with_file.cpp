#include "work_with_file.h"
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>


Time_Holder Get_Time()
{
    Time_Holder time_s = {};

    struct timespec ts;
    timespec_get(&ts, TIME_UTC);

    time_t timer = time(NULL);

    struct tm *openTimeTM = localtime(&timer);

    time_s.year        = openTimeTM->tm_year + 1900;
    time_s.month       = openTimeTM->tm_mon + 1;
    time_s.day         = openTimeTM->tm_mday;

    time_s.hour       = openTimeTM->tm_hour;
    time_s.minutes     = openTimeTM->tm_min;
    time_s.seconds     = openTimeTM->tm_sec;
    time_s.miliseconds = ts.tv_nsec;

    return time_s;
}


char *Create_Filename_by_Time()
{
    Time_Holder cur_time = Get_Time();

    char *filename;
    asprintf(&filename, "gr_dump/dump_%d.%d.%d_%d.%d.%d.%d.dot",
            cur_time.day, cur_time.month, cur_time.year,
            cur_time.hour, cur_time.minutes, cur_time.seconds, cur_time.miliseconds);

    return filename;
}


CODE_ERRORS Create_Png_And_Show(char *filename)
{
    assert(filename);

    char *command;
    asprintf(&command, "dot %s -T png -o %s.png", filename, filename);

    system(command);
    free(command);

    return ALL_GOOD;
}


FILE *open_file(const char *text_const, char *mode)
{
    FILE *stream_read = NULL;

    char file_name_to_open[MAX_SIZE_FILE] = {};

    strcpy(file_name_to_open, text_const);

    const size_t size_mode = 10;
    char new_mode[size_mode] = {};


    do{
        LOG(1, stderr, "%s\n", file_name_to_open);
        if (file_name_to_open[0] == POISON_VAL_FOR_CHAR)
        {
            printf("Введите имя файла для открытия \n");


            fscanf(stdin, "%s", file_name_to_open);
        }
        else if(!(strlen(text_const) < MAX_SIZE_FILE))
        {
            printf("Слишком длинное имя");
            file_name_to_open[0] = POISON_VAL_FOR_CHAR;
        }
        if ((mode[0] != 'w') and (mode[0] != 'r'))
        {
            printf("неправильный mode" );
            printf("введите mode" );

            scanf("%.*s", size_mode, new_mode);

            strcpy(new_mode, mode);
        }
        else
        {
            stream_read = fopen(file_name_to_open, mode);
            file_name_to_open[0] = POISON_VAL_FOR_CHAR;
        }

    }while(stream_read == NULL);

    return stream_read;
}

void close_file_for_debug(FILE *stream_out)
{
    if (!((stream_out == stdout) or (stream_out == stderr)))
    {
        fclose(stream_out);
    }
}

len_arr *read_from_file_to_buff(FILE *stream_read)
{
    struct stat info = {};
    fstat(fileno (stream_read), &info);
    int size_buff = 0;

    char *buffer = (char *) calloc((size_t)(info.st_size) + 1, sizeof(char));
    if (buffer == nullptr)
    {
        printf("too big file");
        exit(1);
    }
    size_t res = fread((void *)buffer, sizeof(char), info.st_size, stream_read);

    size_buff = res;
    buffer[size_buff] = '\0';

    fclose(stream_read);

    LOG(1, stderr, "res %d\n", res);

    return gen_struct_len_arr((void *)buffer, res);

}

CODE_ERRORS free_mem_buf(len_arr *buff)
{
    free(buff->arr);
    free(buff);
}
