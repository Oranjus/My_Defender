/*
** EPITECH PROJECT, 2022
** menu
** File description:
** cursor
*/

#include "defender.h"

sfSprite *load_cursor(char *filepath)
{
    sfSprite *cursor = sfSprite_create();
    sfVector2f origin = {25, 17};
    sfVector2f scale = {1, 1};
    sfVector2f pos_spawn = {-500, -500};

    sfSprite_setTexture(cursor, sfTexture_createFromFile(filepath, NULL),
    sfFalse);
    sfSprite_setTextureRect(cursor, (sfIntRect){0, 0, 50, 50});
    sfSprite_setPosition(cursor, pos_spawn);
    sfSprite_scale(cursor, scale);
    sfSprite_setOrigin(cursor, origin);
    return cursor;
}

void change_cursor(game_object_t *game_asset, int dir)
{
    char *list_cursor[3] = {
        "image/crosshairs/hand_cursor_1.png",
        "image/crosshairs/hand_cursor_2.png",
        "image/crosshairs/hand_cursor_3.png"
    };
    game_asset->i_cursor += dir;
    if (game_asset->i_cursor > 3)
        game_asset->i_cursor = 0;
    if (game_asset->i_cursor < 0)
        game_asset->i_cursor = 3 - 1;
    sfSprite_destroy(game_asset->cursor);
    game_asset->cursor = load_cursor(list_cursor[game_asset->i_cursor]);
}
