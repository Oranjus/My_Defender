/*
** EPITECH PROJECT, 2021
** task02 my_strcat
** File description:
** concatenate 2str
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, const char *src)
{
    int i = my_strlen(dest);
    int j = 0;

    while (src[j] != 0) {
        dest[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    dest[i] = '\0';
    return (dest);
}
