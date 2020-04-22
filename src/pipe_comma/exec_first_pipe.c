/*
** EPITECH PROJECT, 2020
** check
** File description:
** check
*/

#include "my.h"

int exec_father(pid_t pid_two, shell_t *shell, char **envp, int fd[2])
{
    if ((pid_two = fork()) < 0) {
        printf("Erreur 2ème fork\n");
        return 1;
    }
    if (pid_two == 0) {
        close(fd[0]);
        dup2(fd[1], 1);
        if (call_function_recode(envp, shell) == 1)
            return 1;
        else if (exec_function(envp, shell, pid_two) == 84)
            return 84;
        return 1;
    }
    return pid_two;
}

int exec_child(shell_t *shell, pid_t pid, char **envp, int *fd)
{
    shell->array =
            my_str_to_world_array_colon(shell->comma->second_arg_pipe);
    close(fd[1]);
    dup2(fd[0], 0);
    if (call_function_recode(envp, shell) == 1)
        return 1;
    else if (exec_function(envp, shell, pid) == 84)
        return 84;
    return 0;
}

int check_return_function(pid_t pid_two, shell_t *shell)
{
    if (pid_two == 1)
        return 1;
    if (pid_two == 84)
        return 84;
    if (pid_two != 0 && pid_two != 84 && pid_two != 1) {
        wait(NULL);
    }
    return 0;
}

int exec_arg(pid_t pid, shell_t *shell, char **envp, int *fd)
{
    int x = 0;
    pid_t pid_two;

    if (pid == 0) {
        if (x = exec_child(shell, pid, envp, fd) != 0)
            return x;
    } else {
        pid_two = exec_father(pid_two, shell, envp, fd);
        if (pid_two = check_return_function(pid_two, shell) != 0)
            return pid_two;
        return 1;
    }
    return 0;
}

int exec_first_arg(char **envp, char *line, shell_t *shell, int i)
{
    pid_t pid;
    int x = 0;
    int fd[2];

    shell->array = my_str_to_world_array_colon(shell->comma->first_arg_pipe);
    if (pipe(fd) == -1) {
        my_putstr("Erreur pipe\n");
        return 1;
    }
    if ((pid = fork()) < 0) {
        my_putstr("Error fork\n");
        return 1;
    }
    x = exec_arg(pid, shell, envp, fd);
    if (x == 1 || x == 84)
        return x;
    return 2;
}