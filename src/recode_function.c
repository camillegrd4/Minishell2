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
    my_putstr("exit\n");
    exit(0);
    return 0;
}

int cd_normal(shell_t *shell, char *path)
{
    errno = 0;
    if (chdir(path) == -1) {
        if (errno == EACCES) {
            my_putstr("error: Permission denied.\n");
            return 1;
        }
        if (errno == ENOENT) {
            my_putstr(path);
            my_putstr(": No such file or directory.\n");
            return 1;
        }
        if (errno == ENOTDIR) {
            my_putstr(path);
            my_putstr(": Not a directory.\n");
            return 1;
        }
    }
    return 0;
}

int cd_function(shell_t *shell)
{
    if (!shell || !shell->array[0])
        return 84;
    if (my_strncmp(shell->array[1], "-", 1) == 0) {
        if (cd_normal(shell, "..") == 1)
            return 1;
    } else {
        if (cd_normal(shell, shell->array[1]) == 1)
            return 1;
    }
    return 0;
}

int setenv_function(char **envp, shell_t *shell)
{
    int i = 0;

    if (!shell)
        return 84;
    if (shell->array[3] != NULL) {
        my_putstr("setenv: Too many arguments.\n");
        return 1;
    }
    if (shell->array[1])
        change_env(envp, shell);
    return 0;
}

int unsetenv_function(shell_t *shell)
{
    if (!shell)
        return 84;
    if (my_unsetenv(shell) == 1)
        return 1;
    return 0;
}