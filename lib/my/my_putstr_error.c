/*
** EPITECH PROJECT, 2022
** error
** File description:
** print on error output
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void my_putstr_error(char *message)
{
    if (message != NULL)
        write(2, message, my_strlen(message));
}
