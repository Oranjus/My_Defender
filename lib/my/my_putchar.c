/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** function returnning char with ascii in input
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
