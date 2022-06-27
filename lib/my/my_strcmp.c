/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** my_strcmp
*/

#include "my.h"
#include <stddef.h>

int my_strcmp(char const *str1, char const *str2)
{
    int count = 0;
    if (str1 == NULL || str2 == NULL){
        return 84;
    }
    while (str1[count] != '\0' || str2[count] != '\0') {
        if (str1[count] > str2[count])
            return (str1[count] - str2[count]);
        else if (str1[count] < str2[count])
            return (str1[count] - str2[count]);
        else
            ++count;
    }
    return 0;
}
