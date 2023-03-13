/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** test_my_str_to_word_array
*/

#include <criterion/criterion.h>
#include "my_str.h"

Test(my_str_to_word_array, rigor) {
    cr_assert_eq(my_str_to_word_array(NULL), NULL);
}
