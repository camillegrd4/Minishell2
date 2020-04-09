/*
** EPITECH PROJECT, 2020
** tests
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(NULL_pointeur, my_strncmp, .init = redirect_all_stdout)
{
    cr_assert_eq(my_strncmp("hy", NULL, 4), 84);
}

Test(NULL_pointeur_two, my_strncmp, .init = redirect_all_stdout)
{
    cr_assert_eq(my_strncmp(NULL, "hy", 4), 84);
}

Test(equal, my_strncmp, .init = redirect_all_stdout)
{
    cr_assert_eq(my_strncmp("by", "by", 4), 0);
}

Test(different, my_strncmp, .init = redirect_all_stdout)
{
    cr_assert(my_strncmp("by", "hy", 4), -5);
}