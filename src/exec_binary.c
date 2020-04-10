/*
** EPITECH PROJECT, 2020
** binary
** File description:
** binary
*/

#include "my.h"

int exec_binary(shell_t *shell, char **envp)
{
    if (execve(shell->array[0], shell->array, envp) == -1)
        exit(0);
    exit(0);
    return 0;
}

int exec_function_system(shell_t *shell, char **envp, int i)
{
    shell->path_bis[i] 
        = my_strcat_two(shell->path_bis[i], shell->array[0]);
    if (access(shell->path_bis[i], F_OK) == 0)
        access_function(i, envp, shell->path_bis[i], shell);
    return 0;
}