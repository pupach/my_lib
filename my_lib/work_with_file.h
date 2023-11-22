#ifndef WORK_WITH_FILe
#define WORK_WITH_FILe
#include <stdlib.h>
  // � ���, � ���, ������ ���� �� ����, �����������!!!
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "len_arr/len_array.h"
#include <assert.h>

#define LOG(mode, stream_out, args...)                                                        \
    do                                                                                        \
    {                                                                                       \
        if(mode)                                                                            \
        {                                                                                           \
            fprintf(stream_out, args);                                                      \
        }                                                                                   \
    } while(0)


#define HANDLER_ERROR(a...)\
    do\
    {\
        CODE_ERRORS code_ret = a;\
        if(code_ret < 0)\
        {\
            fprintf(stderr, #a"  CODE_RETURN %d\n", code_ret); /*все плохие кода ошибок отрицательны   КАК МОЖНО СДЕЛАТЬ ЛУЧШЕ*/\
            exit(1);\
        }\
    }while(0)


enum CODE_ERRORS
{
    ALL_GOOD   = 0,
    TWO_VAL    = 1,
    VAL_NAN    = -97,//TODOсделать отдельне enumы
    VAL_INF    = -20,
    VAL_POISON = -30,
    VAL_ZERO   = -40,
    BAD_RETURN = -50,
    OVERFLOW_STACK = -1,
    UNDEF_ERROR = -59,
    WAS_REALLOC = 9,
    STACK_SOON_EMPTY = -4,
    OUT_BORDER = -2,
    STACK_EMPTY = -5,
    PTR_NULL = -10,
    BAD_HASH = -23,
    NO_HLT = -90,
    NO_NUMBER = -100,
    BAD_VERSION = -99,
    UNDEF_COM = -63,
    PTR_CALLOC_NULL = -76,
    PTR_ARR_NULL = -49,
    PTR_LIST_LABELS_NULL = -432,
    PTR_ASSEMBLER_NULL = -987,
    WRONG_DATA = -256
};


struct Time_Holder
{
    int year        = -1;
    int month       = -1;
    int day         = -1;
    int hour        = -1;
    int minutes     = -1;
    int seconds     = -1;
    int miliseconds = -1;
};


const int MAX_SIZE = 2;

const int MAX_SIZE_FILE = 255 * 8;//
const char POISON_VAL_FOR_CHAR = '_';


char *Create_Filename_by_Time();

Time_Holder getTime();

CODE_ERRORS Create_Png_And_Show(char *filename);

len_arr *read_from_file_to_buff(FILE *stream_read);

CODE_ERRORS free_mem_buf(len_arr *buff);

char *Myinsert_str_to_str(const char *str1, const char *str2, size_t index_of_insert);

void close_file_for_debug(FILE *stream_out);

FILE *open_file(const char *text="_", char *mode="r");
#endif
