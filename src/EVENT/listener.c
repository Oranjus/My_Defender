/*
** EPITECH PROJECT, 2022
** menu
** File description:
** listener
*/

#include "defender.h"

int listener_button_list(sfVector2f pos_onclick, sfSprite *button,
game_object_t *game_asset, void (*function)(game_object_t *game_asset))
{
    if (check_hitbox(button, pos_onclick) == 1) {
        (*function)(game_asset);
        return 0;
    } else {
        return -1;
    }
}