/*
** EPITECH PROJECT, 2021
** task01 my_strcpy
** File description:
** function copies str into another
*/

#include "my.h"
#include <stdlib.h>

char *my_strcpy(char *dest , char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return dest;
}
