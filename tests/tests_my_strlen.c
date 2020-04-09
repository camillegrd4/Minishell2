/*
** EPITECH PROJECT, 2020
** tests
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(easy, my_strlen, .init = redirect_all_stdout)
{
    int value = my_strlen("hello");
    cr_assert_eq(value, 5);
}

Test(null_pointeur, my_strlen, .init = redirect_all_stdout)
{
    int value = my_strlen(NULL);
    cr_assert_eq(value, 84);
}