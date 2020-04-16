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
    struct comma_s *comma;
}shell_t;

typedef struct comma_s {
    char *first_arg;
    char *second_arg;
}comma_t;

#endif /* !STRUCT_H */
