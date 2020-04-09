/*
** EPITECH PROJECT, 2020
** my_strcat tests
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(NULL_pointeur, my_strcat, .init = redirect_all_stdout)
{
    char *str = my_strcat(NULL, "cd");
    cr_assert_eq(str, NULL);
}

Test(NULL_pointeur_two, my_strcat, .init = redirect_all_stdout)
{
    char *str = my_strcat("cd", NULL);
    cr_assert_eq(str, NULL);
}

Test(easy, my_strcat, .init = redirect_all_stdout)
{
    char *str = my_strcat("cd", "cd");
    cr_assert(str, "cd/cd");
}