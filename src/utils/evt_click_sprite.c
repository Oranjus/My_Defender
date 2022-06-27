/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** interaction
*/

#include "defender.h"

int check_hitbox(sfSprite *sprite, sfVector2f pos_onclick)
{
    sfFloatRect hitbox = sfSprite_getGlobalBounds(sprite);

    if ((pos_onclick.x > hitbox.left) &&
    (pos_onclick.x < (hitbox.left + hitbox.width))) {
        if ((pos_onclick.y > hitbox.top) &&
        (pos_onclick.y < (hitbox.top + hitbox.height))) {
            return 1;
        }
    }
    return 0;
}
