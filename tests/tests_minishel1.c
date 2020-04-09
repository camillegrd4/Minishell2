/*
** EPITECH PROJECT, 2020
** tests
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(null_pointeur, minishel, .init = redirect_all_stdout)
{
    cr_assert_eq(minishel(NULL, NULL), 84);
}

Test(affichage, minishel, .init = redirect_all_stdout)
{
    char **envp;
    char **argv;
    cr_assert(minishel(envp, argv), "$ > ");
}

Test(pointeur_null, my_function, .init = redirect_all_stdout)
{
    cr_assert_eq(my_function(NULL, NULL), 84);
}

Test(pointeur_null, call_function_recode, .init = redirect_all_stdout)
{
    cr_assert_eq(call_function_recode(NULL), 84);
}