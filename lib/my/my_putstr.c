/*
** EPITECH PROJECT, 2021
** MY_PUTSTR
** File description:
** display astring given in input
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

void my_putstr(char const *str)
{
    if (str != NULL) {
        write(1, str, my_strlen(str));
    }
}
