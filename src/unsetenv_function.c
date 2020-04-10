/*
** EPITECH PROJECT, 2020
** unset
** File description:
** unset
*/

#include "my.h"

char **remove_line(shell_t *shell, int i, int y)
{
    y = 0;
    int j = 0;
    int x = 0;
    char **new = malloc(sizeof(char *) * (count_line(shell->save_env)));

    while (shell->save_env[y] != NULL) {
        new[x] = malloc(sizeof(char) * (my_strlen_env(shell->save_env[i])));
        if (y == (shell->pos - 1)) {
            new[x] = my_strdup(shell->save_env[y]);
            y++;
        } else {
            new[x] = my_strdup(shell->save_env[y]);
        }
        y++;
        x++;
    }
    return new;
}

int find_line_unset(shell_t *shell, int i, int j, int y)
{
    int x = 0;
    char *save = malloc(sizeof(char) * my_strlen_egale(shell->save_env[y]));

    while (shell->save_env[y][i] != '=') {
        save[x] = shell->save_env[y][i];
        x++;
        i++;
    }
    if (my_strncmp(save, shell->array[1], my_strlen(shell->name)) != 0) {
        return 1;
    }
    shell->pos = y;
    return 0;
}

int my_unsetenv(shell_t *shell)
{
    int y = 0;
    int i = 0;
    int j = 0;

    if (!shell->array[1])
        return 0;
    shell->unset = my_strdup(shell->array[1]);
    while (shell->save_env[y] != NULL) {
        if (shell->save_env[y][i] == shell->unset[j]) {
            if (i = find_line_unset(shell, i, j, y) != 1) {
                shell->save_env = remove_line(shell, i, y);
                break;
            } else
                y++;
        } else
            y++;
    }
    my_putstr(shell->array[0]);
    my_putstr(": Command not found.\n");
    return 1;
}