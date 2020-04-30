/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include "my.h"

int check_stars(shell_t *shell)
{
    int i = 2;
    int j = 0;

    while (shell->array[i][j] != '\0') {
        if (shell->array[i][j] ==  '*') {
            return 1;
        }
        j++;
    }
    return 0;
}

int which_caracters(shell_t *shell, int i, int j)
{
    if ((shell->array[i][j] < 'a' || shell->array[i][j] > 'z')
    && (shell->array[i][j] < 'A' || shell->array[i][j] > 'Z')) {
        return 1;
    }
    return 0;
}

int check_second_arg(char **envp, shell_t *shell)
{
    int i = 2;
    int j = 0;
    int value = 0;

    if (!shell || !envp)
        return 84;
    while (shell->array[i] && shell->array[i][j] != '\0') {
        if (which_caracters(shell, i, j) == 1 && check_stars(shell) == 1) {
            my_putstr(shell->array[i]);
            my_putstr(": No match.\n");
            return 1;
        }
        j++;
    }
    return 0;
}

int check_letter(char **envp, shell_t *shell)
{
    int i = 1;
    int j = 0;

    while (shell->array[i][j] != '\0') {
        if ((shell->array[i][j] < 'a' || shell->array[i][j] > 'z')
        && (shell->array[i][j] < 'A' || shell->array[i][j] > 'Z')
        && (shell->array[i][j] < '1' || shell->array[i][j] > '9')) {
            my_putstr("setenv: Variable name must contain ");
            my_putstr("alphanumeric characters.\n");
            return 1;
        }
        j++;
    }
    return 0;
}