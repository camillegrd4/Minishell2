/*
** EPITECH PROJECT, 2020
** exec
** File description:
** exec
*/

#include "my.h"

int find_path(shell_t *shell, char **envp)
{
    int i = 0;

    if (!shell || !envp)
        return 84;
    while (shell->save_env[i]) {
        if (my_strncmp_next(shell->save_env[i], "PATH", 4) == 0) {
            shell->path_bis = my_str_to_world_array_colon(&shell->save_env[i][5]);
            return 0;
        }
        i++;
    }
    return 84;
}

int command_not_found(char **envp, shell_t *shell)
{
    if (!shell || !envp)
        return 84;
    my_putstr_without_return(shell->cmd);
    my_putstr(": Command not found.");
    my_putchar('\n');
    exit(0);
}

int access_function(int i, char **envp, char *path, shell_t *shell)
{
    if (access(path, F_OK) == 0) {
        if (execve(path, shell->array, envp) == -1)
            exit(0);
        exit(0);
    }
    return 0;
}

int execve_function(char **envp, shell_t *shell)
{
    int i = 0;

    if (!envp || !shell)
        return 84;
    if (find_path(shell, envp) == 84)
        command_not_found(envp, shell);
    while (shell->path_bis[i] != NULL) {
        if (access(shell->array[0], F_OK) == 0) {
            access_function(i, envp, shell->array[0], shell);
        } else {
            shell->path_bis[i] = my_strcat_two(shell->path_bis[i], shell->array[0]);
            if (access(shell->path_bis[i], F_OK) == 0)
                access_function(i, envp, shell->path_bis[i], shell);
        }
        i++;
    }
    command_not_found(envp, shell);
    return 0;
}

int exec_function(char **envp, shell_t *shell)
{
    struct stat buf;
    pid_t pid;

    if (!envp || !shell)
        return 84;
    if (my_strncmp(shell->array[0], "cd", 2) != 0
        && my_strncmp(shell->array[0], "exit", 4) != 0
        && my_strncmp(shell->array[0], "setenv", 6) != 0
        && my_strncmp(shell->array[0], "unsetenv", 8) != 0) {
        pid = fork();
        if (pid == -1)
            return 84;
        if (pid == 0) {
            if (execve_function(envp, shell) == 84)
                return 84;
        } else {
            pid = waitpid(-1, NULL, 0);
        }
    }
    return 0;
}