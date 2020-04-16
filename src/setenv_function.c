/*
** EPITECH PROJECT, 2020
** setenv function
** File description:
** setenv function
*/

#include "my.h"

int check_setenv(char **envp, shell_t *shell)
{
    if (shell->array[3] != NULL) {
        my_putstr("setenv: Too many arguments.\n");
        return 1;
    }
    if ((shell->array[1][0] <= 'a' || shell->array[1][0] >= 'z')
    && (shell->array[1][0] <= 'A' || shell->array[1][0] >= 'Z')) {
        printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    return 0;
}

int setenv_function(char **envp, shell_t *shell)
{
    int i = 0;

    if (!shell)
        return 84;
    if (check_setenv(envp, shell) == 1)
        return 1;
    if (shell->array[1])
        change_env(envp, shell);
    return 0;
}