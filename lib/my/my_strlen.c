/*
** EPITECH PROJECT, 2021
** MR_STRLEN
** File description:
** function counts nbr of char in a str
*/

#include "my.h"

int my_strlen(char const *str)
{
    int counter = 0;

    while (str[counter] != '\0') {
        counter++;
    }
    return counter;
}
