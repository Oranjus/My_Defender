/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** method_hud
*/

#include "defender.h"

void set_pause(game_object_t *game_asset)
{
    if (game_asset->game_obj->pause == sfFalse) {
        game_asset->game_obj->pause = sfTrue;
    } else {
        my_putstr("pause\n");
        game_asset->game_obj->pause = sfFalse;
    }
}

void next_visualisation(game_object_t *game_asset)
{
    sfIntRect rect = sfSprite_getTextureRect(
        game_asset->game_obj->hud_obj->visualisation);
    rect.left += 111;
    game_asset->game_obj->selected_build += 1;
    if (game_asset->game_obj->selected_build > 3){
        game_asset->game_obj->selected_build = CASTLE;
        rect.left = 0;
    }
    sfSprite_setTextureRect(game_asset->game_obj->hud_obj->visualisation,
    rect);
}

void previous_visualisation(game_object_t *game_asset)
{
    sfIntRect rect = sfSprite_getTextureRect(
        game_asset->game_obj->hud_obj->visualisation);
    rect.left -= 111;
    game_asset->game_obj->selected_build -= 1;
    if (game_asset->game_obj->selected_build == -1) {
        game_asset->game_obj->selected_build = SMALL_CASTLE;
        rect.left = 333;
    }
    sfSprite_setTextureRect(game_asset->game_obj->hud_obj->visualisation,
    rect);
}

void go_to_menu(game_object_t *game_asset)
{
    game_asset->scene = MENU;
    game_asset->game_obj->scene = -1;
}

void launch_assault(game_object_t *game_asset)
{
    if (game_asset->game_obj->building_head != NULL)
        game_asset->game_obj->scene = ASSAULT_ROUND;
    else {
        pop_up_text("please place your main tower\n",
            50, game_asset->game_obj->hud_obj);
    }
}