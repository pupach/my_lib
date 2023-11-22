#ifndef LEN_ARRAY
#define LEN_ARRAY

#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

struct len_arr
{
    int size_arr = -1;
    void *arr;
};

void len_arr_merge (len_arr *arr_where_merge, const len_arr *arr_from_merge);

len_arr * gen_struct_len_arr(void *arr, int size_arr);

void printf_len_arr_in_LOG_int(len_arr *arr_to_print, FILE* str_out);

void printf_len_arr_in_LOG_char(len_arr *arr_to_print, FILE* str_out);

void len_arr_merge_int(len_arr *arr_where_merge, const len_arr *arr_from_merge);

void len_arr_merge_char(len_arr *arr_where_merge, const len_arr *arr_from_merge);

#endif
