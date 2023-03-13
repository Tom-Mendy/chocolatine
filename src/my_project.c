/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** my_project
*/

#include "my_project.h"

int my_project(int argc, char **argv)
{
    char **str = my_load_file_in_array("Makefile");
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != NULL ; i += 1)
    {
        printf("%s\n", str[i]);
    }
    for (int i = 0; str[i] != NULL; i += 1)
    {
        free(str[i]);
    }
    free(str);
    return 0;
}
