/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(modulo_i, exit_code_2, .init = redirect_all_stdout)
{
        char const *str = "i";
        my_putstr(str);
        cr_assert_stdout_eq_str("i", "i");
}

Test(modulo_null, exit_code_2, .init = redirect_all_stdout)
{
        char const *str = 0;
        cr_assert_eq(my_putstr(NULL), 84);
}