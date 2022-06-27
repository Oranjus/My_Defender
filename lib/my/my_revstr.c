/*
** EPITECH PROJECT, 2021
** task03
** File description:
** function that reverses a string
*/

#include "my.h"
#include <stdlib.h>

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int j = 0;
    char temp;

    while (j < i + 1) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        j++;
        i--;
    }
    return str;
}
