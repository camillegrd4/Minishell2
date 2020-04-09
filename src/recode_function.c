/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"

int exit_function(shell_t *shell)
{
    if (!shell)
        return 84;
    exit(0);
    return 0;
}

int cd_function(shell_t *shell)
{
    if (!shell || !shell->array[0])
        return 84;
    if (chdir(shell->array[1]) == -1)
        return 84;
    return 0;
}

int setenv_function(char **envp, shell_t *shell)
{
    int i = 0;

    if (!shell)
        return 84;
    if (shell->array[1])
        change_env(envp, shell);
    return 0;
}

int unsetenv_function(shell_t *shell)
{
    if (!shell)
        return 84;
    my_unsetenv(shell);
    return 0;
}