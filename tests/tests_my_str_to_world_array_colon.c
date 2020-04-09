/*
** EPITECH PROJECT, 2020
** tests
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(null_pointeur, number_char_colon, .init = redirect_all_stdout)
{
    cr_assert_eq(number_char_colon(NULL), 84);
}

Test(basic, number_char_colon, .init = redirect_all_stdout)
{
    cr_assert_eq(number_char_colon("hello"), 0);
}

Test(with_space, number_char_colon, .init = redirect_all_stdout)
{
    cr_assert_eq(number_char_colon("hello world"), 1);
}

Test(null_pointeur, lines_colon, .init = redirect_all_stdout)
{
    cr_assert_eq(lines_colon(NULL), 84);
}

Test(easy, lines_colon, .init = redirect_all_stdout)
{
    cr_assert_eq(lines_colon("hello"), 5);
}

Test(empty, lines_colon, .init = redirect_all_stdout)
{
    cr_assert_eq(lines_colon(" "), 1);
}

Test(easy, my_str_to_world_array_colon, .init = redirect_all_stdout)
{
    cr_assert(my_str_to_world_array_colon("hello"), "hello");
}