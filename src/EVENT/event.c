/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** all event func
*/

#include "defender.h"

void analyse_events(sfRenderWindow *window, sfEvent event,
game_object_t *game_asset)
{
    sfVector2f pos;

    if (event.type == sfEvtClosed
    || (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)) {
        close_game(game_asset);
        return;
    }
    if (event.type == sfEvtMouseMoved) {
        pos.x = event.mouseMove.x;
        pos.y = event.mouseMove.y;
        sfSprite_setPosition(game_asset->cursor, pos);
    }
    else if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        game_asset->scene = MENU;
    }
}
