/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#include "my.h"

int number_char(char *str)
{
    int i = 0;
    int number_char = 0;

    if (!str)
        return 84;
    while (str[i] != '\0') {
        if (str[i] == ':' || str[i] == ' ')
            number_char += 1;
        i += 1;
    }
    return number_char;
}

int lines(char *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}

char **add_letter(char **array, int number, char *str)
{
    int i = 0;
    int j = 0;
    int a = 0;

    while (number > 0 && i <= my_strlen(str)) {
        array[a] = malloc(sizeof(char) * (lines_colon(&str[i]) + 1));
        while (str[i] != '\0' && str[i] != ':' && str[i] != '\t' && 
        str[i] != ' ' && str[i] != '\n') {
            array[a][j] = str[i];
            j += 1;
            i += 1;
        }
        i++;
        array[a][j] = '\0';
        j = 0;
        a += 1;
        --number;
    }
    array[a] = NULL;
    return array;
}

char **my_str_to_world_array(char *str)
{
    int number = number_char_colon(str) + 1;
    char **array = malloc(sizeof(char *) * (number + 1));

    array = add_letter(array, number, str);
    return array;
}