/*
** EPITECH PROJECT, 2020
** setenv function
** File description:
** setenv function
*/

#include "my.h"

int check_setenv(char **envp, shell_t *shell)
{
    if (!shell->array[1]) {
        print_env(shell->save_env, shell);
        return 2;
    }
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
    int x = 0;

    if (!shell)
        return 84;
    if (x = check_setenv(envp, shell) == 1)
        return 1;
    if (x == 2)
        return 0;
    if (shell->array[1] != NULL)
        change_env(envp, shell);
    return 0;
}