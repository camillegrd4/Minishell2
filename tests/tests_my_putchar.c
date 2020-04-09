/*
** EPITECH PROJECT, 2019
** test_my_putchar.c
** File description:
** test
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_putchar, simple)
{
    cr_redirect_stdout();
    my_putchar('t');
    cr_expect_stdout_eq_str("t");
}