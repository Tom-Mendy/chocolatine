/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** function that splits a string into words
*/

#include <stdlib.h>

int my_str_is_alpha(char const *str);
int my_str_len(char const *str);

static char *creat_word_from_array(int start,
char const * str, int end, char *temp)
{
    int j = 0;
    for (int j = start; j < end; j += 1){
        temp[j - start] = str[j];
    }
    temp[end - start] = '\0';
    return temp;
}

static int count_special_char(char const *str)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0'){
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= '0' && str[i] <= '9'))){
            count += 1;
        }
        i += 1;
    }
    return count;
}

static int add_str(char const * str, int start, int end, char **array)
{
    char *temp;
    temp = malloc(end - start + 1);
    creat_word_from_array(start, str, end, temp);
    if (my_str_len(temp) != 0){
        *array = temp;
        return 1;
    }
    return 0;
}

char **my_str_to_word_array(char const * str)
{
    if (str == NULL)
        return NULL;
    char **array;
    array = malloc(sizeof(char *) * count_special_char(str));
    int start = 0;
    int end = -1;
    int count_array = 0;
    for (int i = 0;i <= my_str_len(str); i += 1){
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' ||
        str[i] > 'Z') && (str[i] < '0' || str[i] > '9')){
            end = i;
        }
        if ((end > -1) && ((str[i] >= '0' && str[i] <= '9') ||
        (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' || str[i] <= 'Z'))){
            count_array += add_str(str, start, end, array + count_array);
            start = end + 1;
            end = -1;
        }
    }
    return array;
}
