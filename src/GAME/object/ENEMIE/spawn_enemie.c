/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** sapwn_enemie
*/

#include "defender.h"

sfIntRect get_random_zone(direction dir)
{
    sfIntRect rect = {1, 1, 1, 1};
    switch (dir) {
        case UP:
            rect = (sfIntRect){1, WD_WIDTH, -500, 1};
            break;
        case DOWN:
            rect = (sfIntRect){1, WD_WIDTH, WD_HEIGHT, WD_HEIGHT + 500};
            break;
        case LEFT:
            rect = (sfIntRect){-500, 1, 1 ,WD_HEIGHT};
            break;
        case RIGHT:
            rect = (sfIntRect){WD_WIDTH, WD_WIDTH + 500, -1 , WD_HEIGHT};
            break;
    }
    return rect;
}

static int get_nbr_btwn(int min, int max, int randomiser)
{
    srand(647654375497847 * randomiser);
    return rand() % (max - min) + min;
}

sfVector2f get_pos_random(int randomiser, sfIntRect zone)
{
    int x_max = zone.top;
    int x_min = zone.left;
    int y_max = zone.height;
    int y_min = zone.width;

    sfVector2f pos;
    pos.x = get_nbr_btwn(x_min, x_max, randomiser);
    randomiser *= 3;
    pos.y = get_nbr_btwn(y_min, y_max, randomiser);
    return pos;
}
