/*
** EPITECH PROJECT, 2020
** env
** File description:
** env
*/

#include "my.h"

int find_line(shell_t *shell, int i, int j, int y)
{
    while (shell->name[j] != '\0') {
        if (shell->save_env[y][i] != shell->name[j]) {
            return 1;
        }
        j++;
        i++;
    }
    return 0;
}

int count_line(char **envp)
{
    int i = 0;
    int counter = 0;

    while (envp[i] != NULL) {
        i++;
    }
    return i;
}

char **create_list_env(char **envp, shell_t *shell)
{
    int i = 0;
    int j = 0;
    char **str = malloc(sizeof(char *) * (count_line(envp)) + 1);

    while (envp[j] != NULL) {
        str[i] = malloc(sizeof(char) * (my_strlen(envp[j])) + 1);
        str[i] = my_strdup(envp[j]);
        j++;
        i++;
    }
    str[i] = NULL;
    return str;
}

int print_env(char **str, shell_t *shell)
{
    int i = 0;

    while (str[i] != NULL) {
        my_putstr(str[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}