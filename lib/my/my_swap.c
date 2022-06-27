/*
** EPITECH PROJECT, 2021
** MY_SWAP
** File description:
** function swap content of 2 integer
*/

#include "my.h"

void my_swap(int *first_int, int *second_int)
{
    int stock_scd;

    stock_scd = *second_int;
    *second_int = *first_int;
    *first_int = stock_scd;
}
