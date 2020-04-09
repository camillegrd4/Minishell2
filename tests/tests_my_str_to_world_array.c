/*
** EPITECH PROJECT, 2020
** tests
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(null_pointeur, number_char, .init = redirect_all_stdout)
{
    cr_assert_eq(number_char(NULL), 84);
}

Test(basic, number_char, .init = redirect_all_stdout)
{
    cr_assert_eq(number_char("hello"), 0);
}

Test(with_space, number_char, .init = redirect_all_stdout)
{
    cr_assert_eq(number_char("hello world"), 1);
}

Test(null_pointeur, lines, .init = redirect_all_stdout)
{
    cr_assert_eq(lines(NULL), 84);
}

Test(easy, lines, .init = redirect_all_stdout)
{
    cr_assert_eq(lines("hello"), 5);
}

Test(empty, lines, .init = redirect_all_stdout)
{
    cr_assert_eq(lines(" "), 0);
}

Test(easy, my_str_to_world_array, .init = redirect_all_stdout)
{
    cr_assert(my_str_to_world_array("hello"), "hello");
}