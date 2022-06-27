/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** display_menu
*/

#include "defender.h"

void display_menu(sfRenderWindow *window, menu_t *menu_obj,
game_object_t *game_asset)
{
    sfRenderWindow_drawSprite(window, menu_obj->background, NULL);

    display_btn(window, menu_obj->button_list);

    sfRenderWindow_drawText(window, menu_obj->title, NULL);
    sfRenderWindow_drawSprite(window, game_asset->cursor , NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfColor_fromRGBA(149, 125, 173, 60));
}
