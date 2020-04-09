/*
** EPITECH PROJECT, 2020
** tests
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(pointeur_null, cd_function, .init = redirect_all_stdout)
{
    cr_assert_eq(cd_function(NULL), 84);
}

Test(pointeur_null, setenv_function, .init = redirect_all_stdout)
{
    cr_assert_eq(setenv_function(NULL), 84);
}

Test(pointeur_null, unsetenv_function, .init = redirect_all_stdout)
{
    cr_assert_eq(unsetenv_function(NULL), 84);
}