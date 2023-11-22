#include "str_func.h"
#include "work_with_file.h"



int Myputs(const char *str)
{
    while(*str)
    {
        putc((int)*str, stdout);
        str++;
    }
    return 1;

}

char *Mystrchr(const char *str, int ch)
{
    int i = 0;
    while(str[i])
    {
        if ((int)(str[i]) == ch)
        {
            return ((char*)str + i);
        }
        i++;
    }
    return nullptr;
}

int Mystrlen(const char *str)
{
    if (str == nullptr) return 0;
    int i = 0;
    while(*(str + i))
    {
        i++;
    }
    return i;
}

char *Mystrcpy(char *destptr, const char *srcptr)
{
    if ((destptr == nullptr) or (srcptr == nullptr)) return nullptr;
    int counter = 0;
    int len_dest = Mystrlen(destptr);

    while(*(srcptr + counter))
    {
        *(destptr + counter) = *(srcptr + counter);
        counter++;
    }

    *(destptr + counter) = '\0';
    counter++;

    while (counter<len_dest)
    {
        *(destptr + counter) = '\0';
        counter++;
    }


    return destptr;
}


char * Mystrcat(char * destptr, const char * srcptr )
{
    if ((destptr == nullptr) or (srcptr == nullptr)) return nullptr;

    printf("\n%c, %s ssss", *(destptr + strlen(destptr)), srcptr);

    Mystrcpy(destptr + strlen(destptr), srcptr);

    return destptr;
}


char *Myfgets(char *str, int num, FILE *stream)
{
    if ((str == nullptr)) return nullptr;
    int counter = 0;

    while(counter<num)
    {
        char res = getc(stream);
        if ((int) res == EOF)
        {
            break;
        }
        *(str + counter) = res;
        counter++;
    }
    return str;
}

char *Mystrdup(const char *str)
{
    int len = Mystrlen(str) + 1;
    char * ptr = (char *) calloc(len, sizeof(char));

    return Mystrcpy(ptr, str);
}

char *Mystrstr(const char *str, const char *strSearch)
{
    int counter = 0;
    while (*(str + counter))
    {
        int counter_2 = 0;
        int res = 1;
        while(*(strSearch + counter_2))
        {
            if (*(str + counter + counter_2) != *(strSearch + counter_2))
            {
                res = 0;
                break;
            }
            counter_2++;
        }
        if (res)
        {
            return (char *)str + counter;
        }
        counter++;
    }
    return nullptr;
}

char *Myinsert_str_to_str(const char *str1, const char *str2, size_t index_of_insert)
{
    int len_all_str = strlen(str1) + strlen(str2);
    char *ptr_new_str = (char *)calloc(len_all_str, sizeof(char));

    ptr_new_str = strncpy(ptr_new_str, str1, index_of_insert - 1);
    strncpy(ptr_new_str + index_of_insert-1, str2, strlen(str2));
    strcpy(ptr_new_str + index_of_insert-1+strlen(str2), str1+index_of_insert-1);

    return ptr_new_str;
}

// TODO: rename or use isalpha(char)
bool is_letter_rus(char characters)
{
    if (((characters >= 'a') and (characters <= 'z')) or ((characters >= 'A') and (characters <= 'Z')))
    {
        return true;
    }
    return false;
}

bool is_number(char characters)
{
    if ((characters >= '0') and (characters <= '9'))
    {
        return true;
    }
    return false;
}

size_t skip_no_letter(char *str)
{
    size_t counter = 0;

    while(!is_letter_rus(*str))
    {
        LOG(1, stderr, "skip_no_letter %d, %d s%cs\n", ((int)(*str) == (int)'\n'),*str, *str);
        if((int)(*str) == (int)'\n') break;

        str += 1;
        counter += 1;
    }
    return counter;
}


size_t strcpy_to_space(char *destptr,  char *srcptr)
{
    if ((destptr == nullptr) or (srcptr == nullptr)) return 0;

    size_t counter_dest = 0;

    LOG(1, stderr, "strcpy_to_space %s\n", srcptr);
    size_t counter_src = 0;
    LOG(1, stderr, "strcpy_to_space %s\n", srcptr);

    int len_dest = Mystrlen(destptr);

    LOG(1, stderr, "str in input %c, %d\n", *(srcptr + counter_src), is_letter_rus(*(srcptr + counter_src)));

    while(isalpha((int)*(counter_src + srcptr)))
    {
        LOG(1, stderr, "strcpy_to_space %c\n", *(srcptr + counter_src));
        *(destptr + counter_dest) = *(srcptr + counter_src);
        counter_src++;
        counter_dest++;
    }

    size_t fo_ret = counter_src;

    *(destptr + counter_dest) = '\0';
    counter_dest++;

    while (counter_dest<len_dest)
    {
        *(destptr + counter_dest) = '\0';
        counter_dest++;
    }
    return fo_ret;
}

bool check_empty_char(char symbol)
{
    if((is_letter_rus(symbol)) or (is_number(symbol)))
    {
        return false;
    }
    return true;
}

size_t strcpy_to_letter(char *destptr,  char *srcptr)
{
    if ((destptr == nullptr) or (srcptr == nullptr)) return 0;

    size_t counter_dest = 0;

    LOG(1, stderr, "strcpy_to_space %s\n", srcptr);
    size_t counter_src = skip_no_letter(srcptr);

    int len_dest = Mystrlen(destptr);

    while(*(srcptr + counter_src) and (is_letter_rus(*(srcptr + counter_src))))
    {
        LOG(1, stderr, "strcpy_to_space %c\n", *(srcptr + counter_src));
        *(destptr + counter_dest) = *(srcptr + counter_src);
        counter_src++;
        counter_dest++;
    }

    size_t fo_ret = counter_src;

    *(destptr + counter_dest) = '\0';
    counter_dest++;

    while (counter_dest<len_dest)
    {
        *(destptr + counter_dest) = '\0';
        counter_dest++;
    }
    return fo_ret;
}
