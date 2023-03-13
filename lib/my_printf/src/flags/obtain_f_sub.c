/*
** EPITECH PROJECT, 2023
** B-CPE-101-BDX-1-1-myprintf-tom.mendy
** File description:
** obtain_double_sub
*/

#include "my_printf.h"

int find_count_unit_lenght(int nb)
{
    int count_unit_lenght = 0;
    while (nb >= 1) {
        nb /= 10;
        count_unit_lenght += 1;
    }
    if (count_unit_lenght == 0){
        count_unit_lenght = 1;
    }
    return count_unit_lenght;
}

static void round_nb_sub(double save_nb, char *string_nb,
int i)
{
    while (i >= 0) {
        string_nb[i] += 1;
        if ((string_nb[i] - 48) == 10) {
            string_nb[i] = '0';
            i -= 1;
        } else {
            i = -84;
        }
    }
}

int round_nb(double save_nb, char *string_nb)
{
    save_nb *= 10;
    char save_first_nb = string_nb[0];
    int i = my_str_len(string_nb) - 1;
    if (((int)save_nb % 10) > 5) {
        round_nb_sub(save_nb, string_nb, i);
    }
    if ((save_first_nb != string_nb[0]) && (string_nb[0] == '0')){
        return 1;
    } else {
        return 0;
    }
}

void concatenate(char *result, char *unit, char *decimal)
{
    int i = 0;
    for (int j = 0; unit[j] != '\0'; j += 1) {
        result[i] = unit[j];
        i += 1;
    }
    for (int j = 0; decimal[j] != '\0'; j += 1) {
        result[i] = decimal[j];
        i += 1;
    }
    result[i] = '\0';
}
