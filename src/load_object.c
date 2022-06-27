/*
** EPITECH PROJECT, 2021
** bs_runner
** File description:
** game_object
*/

#include "defender.h"

static int check_load(game_object_t *game_asset)
{
    return 0;
}

game_object_t *load_asset(game_object_t *game_asset)
{
    game_asset = malloc(sizeof(game_object_t));
    game_asset->game_obj = NULL;
    game_asset->cursor = load_cursor("resources/cursor/hand_cursor_2.png");
    game_asset->scene = MENU;
    game_asset->music = load_music("resources/MUSIC/menu.ogg", sfFalse);
    sfMusic_play(game_asset->music);
    game_asset->music_click = load_music("resources/MUSIC/click.ogg", sfFalse);
    my_putstr("\n|INFO :\n|Base game loaded\n");
    return game_asset;
}

void destroy_asset(game_object_t *game_asset)
{
    sfMusic_stop(game_asset->music);
    sfMusic_destroy(game_asset->music);
    sfMusic_stop(game_asset->music_click);
    sfMusic_destroy(game_asset->music_click);
    sfSprite_destroy(game_asset->cursor);
    free(game_asset);
    my_putstr("\n|INFO :\n|Base game destroyed\n");
}
