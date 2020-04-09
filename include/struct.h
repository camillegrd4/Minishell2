/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct shell {
    char *cmd;
    char **array;
    char *path;
    char **path_bis;
    char **save_env;
    char *name;
    char *remove;
    char **new_env;
    int line;
    char *unset;
    int pos;
    int find_line;
}shell_t;

typedef struct env {
    char *name;
    char *params;
    char *str;
    struct tetris *next;
}env_t;

#endif /* !STRUCT_H */
