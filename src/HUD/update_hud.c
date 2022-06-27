/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** update_hud
*/

#include "defender.h"

void pop_up_text(char *message, int time, hud_t *hud_obj)
{
    sfVector2f center = {WD_WIDTH / 2, WD_HEIGHT / 2};
    sfFloatRect rect;

    sfText_setString(hud_obj->info_text, message);
    rect = sfText_getLocalBounds(hud_obj->info_text);
    center.x -= rect.width / 2;
    center.y -= rect.height / 2;
    sfText_setPosition(hud_obj->info_text, center);
    hud_obj->couldown_text = time;
}

void update_heart(game_t *game_obj)
{
    int offset = ((game_obj->health / 10) * 59) / 100;
    sfIntRect rect = {35, 33, offset, 7};
    sfSprite_setTextureRect(game_obj->hud_obj->health_bar, rect);
}

static void anim_text(game_t *game_obj)
{
    sfVector2f pos = {WD_WIDTH - 50, 75};
    sfText_setString(game_obj->hud_obj->nb_gold, nbr_to_str(game_obj->gold));
    sfFloatRect rect = sfText_getLocalBounds(game_obj->hud_obj->nb_gold);
    pos.x -= rect.width;
    sfText_setPosition(game_obj->hud_obj->nb_gold, pos);
}

void update_hud(game_t *game_obj, sfClock *clock)
{
    anim_text(game_obj);
    anim_sprite(game_obj->hud_obj->coin, (sfIntRect){16, 0},
        (sfIntRect){16, 16, 80, 16});
    update_heart(game_obj);
}
