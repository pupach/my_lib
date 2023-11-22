#include "len_array.h"
#include "../../my_lib/work_with_file.h"


#define GEN_LEN_ARR_MERGE(type)                                            \
void len_arr_merge_##type(len_arr *arr_where_merge, const len_arr *arr_from_merge)                        \
{\
    for (int i = 0; i < arr_from_merge->size_arr; i++)\
    {\
        (((type *)arr_where_merge->arr))[arr_where_merge->size_arr] = ((type *)(arr_from_merge->arr))[i];\
        (arr_where_merge->size_arr) += 1;\
    }\
}

#define GEN_PRINT_LEN_ARR_IN_LOG(type, str_type)                                            \
void printf_len_arr_in_LOG_##type(len_arr *arr_to_print, FILE* str_out)                     \
{              \
    assert(arr_to_print != nullptr);\
    LOG(1, stderr, "\nmrrmrmmrmr\n");                                                                             \
    for(int i = 0; i < arr_to_print->size_arr; i++)                                         \
    {\
        LOG(1, stderr, "printf_len_arr_in_LOG"#str_type"\n", *((type *)(arr_to_print->arr) + i));     \
    }                                                                                       \
}

GEN_LEN_ARR_MERGE(int);

GEN_LEN_ARR_MERGE(char);

GEN_PRINT_LEN_ARR_IN_LOG(char, "%c");

GEN_PRINT_LEN_ARR_IN_LOG(int, "%d");

len_arr * gen_struct_len_arr(void *arr, int size_arr)
{
    if((size_arr > -1) and (arr != nullptr))
    {
        // TODO: rename normalno
        // TODO: move anywhere else, not in onegin
        len_arr *sorted_str = (len_arr *)calloc(sizeof(len_arr), 1);
        sorted_str->arr = arr;
        sorted_str->size_arr = size_arr;
//        LOG(1, stderr, "gen_struct_len_arr pointer %p\n", sorted_str);
        return sorted_str;
    }
    else
    {
        fprintf(stderr, "all_bad_bad_str");
        return nullptr;
    }
}

void len_arr_merge (len_arr *arr_where_merge, const len_arr *arr_from_merge)//вопрос про дефайны, как это все делать
{
    for (int i = 0; i < arr_from_merge->size_arr; i++)
    {
        (((int *)arr_where_merge->arr))[arr_where_merge->size_arr] = ((int *)(arr_from_merge->arr))[i];
        (arr_where_merge->size_arr) += 1;

    }
}
