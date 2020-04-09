/*
** EPITECH PROJECT, 2020
** test
** File description:
** test
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(NULL_pointeur, exec_function, .init = redirect_all_stdout)
{
    cr_assert_eq(exec_function(NULL, NULL), 84);
}

Test(envp_null, exec_function, .init = redirect_all_stdout)
{
    shell_t *shell;
    cr_assert_eq(exec_function(NULL, shell), 84);
}

Test(NULL_pointeur, find_path, .init = redirect_all_stdout)
{
    cr_assert_eq(find_path(NULL, NULL), 84);
}

Test(NULL_pointeur, execve_function, .init = redirect_all_stdout)
{
    cr_assert_eq(execve_function(NULL, NULL), 84);
}