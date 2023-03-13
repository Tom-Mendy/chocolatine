/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** generate_tab
*/

#include "spliter.h"

int is_str_only_contain_char(char const * const str, char const c)
{
    for (int i = 0; str[i] != '\0'; i += 1){
        if (str[i] != c)
            return 84;
    }
    return 0;
}

int generate_tab(char ** word_array, char *str, char spe_char, int *word_index)
{
    change_begin_str(&str, spe_char);
    if (is_str_only_contain_char(str, spe_char) == 0)
        return 0;
    int i = 0;
    for (; str[i] != '\0'; i += 1) {
        if (str[i + 1] == '\0') {
            add_word(word_array, str, word_index, i + 1);
            return 0;
        }
        if (str[i + 1] == spe_char){
            add_word(word_array, str, word_index, i + 1);
            str = &(str[i + 1]);
            return generate_tab(word_array, str, spe_char, word_index);
        }
    }
    return 0;
}
