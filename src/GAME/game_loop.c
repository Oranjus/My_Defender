/*
** EPITECH PROJECT, 2022
** menu
** File description:
** game_loop
*/

#include "defender.h"

int game_loop(game_object_t *game_asset, sfRenderWindow *window)
{
    sfEvent event;
    game_t *game_obj = malloc(sizeof(game_t));

    load_game(game_obj);
    sfMusic_pause(game_asset->music);
    game_asset->game_obj = game_obj;
    while (game_asset->scene == GAME) {
        switch (game_obj->scene) {
        case BUILDING_ROUND:
            building_round(game_asset, window, game_obj);
            break;
        case ASSAULT_ROUND:
            assault_round(game_asset, window, game_obj);
            break;
        }
    }
    destroy_game(game_obj);
}
