/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** method_btn
*/

#include "defender.h"

void close_game(game_object_t *game)
{
    game->scene = QUIT;
    if (game->game_obj != NULL)
        game->game_obj->scene = QUIT_GAME;
}

void launch_game_btn(game_object_t *game)
{
    game->scene = GAME;
}

void go_back_scene(game_object_t *game)
{
    game->scene = MENU;
}

void go_to_info(game_object_t *game)
{
    game->scene = INFO;
}

void map_selector(game_object_t *game)
{
    game->scene = MAP;
}

void go_to_trophea(game_object_t *game)
{
    game->scene = TROPHEA;
}
