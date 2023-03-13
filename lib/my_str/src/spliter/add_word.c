/*
** EPITECH PROJECT, 2023
** B-PSU-200-BDX-2-1-minishell1-tom.mendy
** File description:
** add_word
*/

#include "spliter.h"

void add_word(char **word_array, char *str, int *word_index, int i)
{
    word_array[(*word_index)] = malloc(sizeof(char) * (i + 1));
    int j;
    for (j = 0; j < i; j += 1) {
        word_array[(*word_index)][j] = str[j];
    }
    word_array[(*word_index)][j] = '\0';
    (*word_index) += 1;
}
