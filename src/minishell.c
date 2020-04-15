/*
** EPITECH PROJECT, 2020
** mini
** File description:
** mini
*/

#include "my.h"

int my_function(shell_t *shell, char **envp)
{
    if (!envp || !shell)
        return 84;
    if (call_function_recode(envp, shell) == 1) {
        return 1;
    }
    else if (exec_function(envp, shell) == 84) {
        return 84;
    }
    return 0;
}

int check_getline(shell_t *shell, char **envp)
{
    if (!shell->cmd) {
        my_putstr("exit\n");
        exit(0);
    } else {
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

    while (1) {
        if (isatty(STDIN_FILENO) == 1)
            my_putstr("$ > ");
        if (x = getline(&line, &n, stdin) == -1) {
            my_putstr("exit\n");
            exit(0);
        }
        if (x != -1) {
            shell->cmd = line;
            shell->array = my_str_to_world_array(shell->cmd);
        }
        if (check_getline(shell, envp) == 84)
            return 84;
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