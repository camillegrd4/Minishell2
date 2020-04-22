/*
** EPITECH PROJECT, 2020
** mini
** File description:
** mini
*/

#include "my.h"

int my_function(shell_t *shell, char **envp)
{
    pid_t pid = 5;

    if (!envp || !shell)
        return 84;
    if (call_function_recode(envp, shell) == 1) {
        return 1;
    }
    else if (exec_function(envp, shell, pid) == 84) {
        return 84;
    }
    return 0;
}

int check_getline(shell_t *shell, char **envp, int x, char *line)
{
    if (x != -1) {
        shell->cmd = line;
        shell->array = my_str_to_world_array(shell->cmd);
    }
    if (!shell->cmd) {
        my_putstr("exit\n");
        exit(0);
    } else if (x != -1) {
        if (my_function(shell, envp) == 84)
            return 84;
    }
    return 0;
}

int principal_function(char **envp, shell_t *shell)
{
    size_t n = 0;
    char *line;
    int x = 0;
    int i = 0;

    while (1) {
        i = 0;
        if (isatty(STDIN_FILENO) == 1)
            my_putstr("$ > ");
        if (x = getline(&line, &n, stdin) == -1) {
            my_putstr("exit\n");
            exit(0);
        }
        printf("oui\n");
        if (x != -1) {
            printf("ici\n");
            x = check_pipe_function(envp, line, shell, i);
            if (x == 1 || x == 84)
                return x;
            if (x != 2) {
                printf("bloqué la\n");
                check_comma_function(line, shell, envp, x);
            }
        }
    }
    return 0;
}

char minishel(char **argv, char **envp)
{
    shell_t *shell = init_struct_minishell();

    if (!argv || !envp || !shell)
        return 84;
    shell->save_env = create_list_env(envp, shell);
    if (principal_function(envp, shell) == 84)
        return 84;
    return 0;
}