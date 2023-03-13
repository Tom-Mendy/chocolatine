/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** spliter
*/

#ifndef SPLITER_H_
    #define SPLITER_H_
    #include <stdlib.h>
    #include "my_str.h"
    void add_word(char **word_array, char *str, int *word_index, int i);
    int generate_tab(char ** word_array, char *str, char spe_char,
    int *word_index);
    int change_begin_str(char **str, char spe_char);
    char **spliter(char *str, char const *const delimiter);
#endif /* !SPLITER_H_ */
