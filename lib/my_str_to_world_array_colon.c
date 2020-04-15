/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#include "my.h"

int number_char_colon(char *str, int i)
{
    int number_char = 0;

    if (!str)
        return 84;
    while (str[i] != '\0') {
        if ((str[i] == ':' || str[i] == ' ' || str[i] == '\t')
        && (str[i + 1] != ':' && str[i + 1] != ' ' && str[i + 1] != '\t'
        && str[i + 1] != '\0'))
            number_char += 1;
        i += 1;
    }
    return number_char;
}

int lines_colon(char *str)
{
    int i = 0;

    if (!str)
        return 84;
    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}

char **add_letter_colon(char **array, int number, char *str, int i)
{
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
        while (str[i] == ' ' || str[i] == '\t' || str[i] == ':')
            i++;
        array[a][j] = '\0';
        j = 0;
        a += 1;
        --number;
    }
    array[a] = NULL;
    return array;
}

char **check_space(char **array, int number)
{
    int j = 0;
    int a = 0;
    int i = 0;
    int x = 0;
    char **form = malloc(sizeof(char *) * (number + 1));

    while (array[i]) {
        i = 0;
        x = 0;
        form[i] = malloc(sizeof(char) * (my_strlen(array[i])) + 1);
        while (array[i][j]) {
            if (array[a][x] == ' ' && (array[a][x + 1] == ' ' || array[a][x + 1] == '\0'))
                x++;
            else
                form[i][j] = array[a][x];
                j += 1;
                x += 1;
            form[a][x] = '\0';
            x++;
            a += 1;
        }
    }
    form[a] = NULL;
    return form;
}

char **my_str_to_world_array_colon(char *str)
{
    int number = 0;
    int stock = 0;
    char **array = NULL;
    int i = 0;

    while (str[i] == ' ') {
        printf("coucou\n");
        i++;
    }
    i = 0;
    number = number_char_colon(str, i) + 1;
    stock = number;
    array = malloc(sizeof(char *) * (number + 1));
    array = add_letter_colon(array, number, str, i);
    /*while (array[i] != NULL) {
        array[i] = check_space(array, stock);
        i++;
    }*/
    return array;
}