/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/

#include "my.h"

shell_t *init_struct_minishell(void)
{
    shell_t * shell = malloc(sizeof(shell_t));
    if (!shell)
        return NULL;
    shell->array = NULL;
    shell->cmd = NULL;
    shell->path = NULL;
    shell->path_bis = NULL;
    return shell;
}