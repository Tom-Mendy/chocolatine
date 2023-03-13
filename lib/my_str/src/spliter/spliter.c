/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-bsminishell1-tom.mendy
** File description:
** spliter
*/

#include "spliter.h"

int my_count_nb_char_in_str(char *str, char spe_char);

static void replace_delimiter(char *str, int const i,
char const *const delimiter)
{
    for (int j = 1; delimiter[j] != '\0'; j += 1) {
        if (str[i] == delimiter[j])
            str[i] = delimiter[0];
    }
}

char **spliter(char *str, char const *const delimiter)
{
    if (str == NULL || delimiter == NULL)
        return NULL;
    int word_index = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        replace_delimiter(str, i, delimiter);
    }
    change_begin_str(&str, delimiter[0]);
    int num_words = my_count_nb_char_in_str(str, delimiter[0]);
    if (num_words == -1)
        return NULL;
    char **word_array = malloc(sizeof(char *) * (num_words + 1));
    generate_tab(word_array, str, delimiter[0], &word_index);
    word_array[num_words] = NULL;
    return word_array;
}
