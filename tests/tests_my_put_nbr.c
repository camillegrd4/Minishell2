/*
** EPITECH PROJECT, 2019
** test
** File description:
** test
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(modulo_nbr, exit_code_2, .init = redirect_all_stdout)
{
        int nb = 10;
        my_put_nbr(nb);
        cr_assert_stdout_eq_str("10", "10");
}

Test(modulo_nbr_neg, exit_code_2, .init = redirect_all_stdout)
{
        int nb = -10;
        my_put_nbr(nb);
        cr_assert_stdout_eq_str("-10", "-10");
}

Test(modulo_overflow, exit_code_2, .init = redirect_all_stdout)
{
        int nb = -2147483648;
        my_put_nbr(nb);
        cr_assert_stdout_eq_str("-2147483648", "-2147483648");
}
