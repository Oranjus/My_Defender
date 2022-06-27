/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** map
*/

#include "defender.h"

static void remap_btn(button_t *button_list)
{
    disappear_btn(button_list);
    change_sprite_btn(button_list->button,
        (sfVector2f){50, 50}, (sfIntRect){0, 48, 16, 16});
    button_list->method_event = *go_back_scene;
    change_sprite_btn(button_list->next->button,
        (sfVector2f){WD_WIDTH / 2 - 200, WD_HEIGHT / 2},
        (sfIntRect){0, 16, 16, 16});
    button_list->next->method_event = *go_back_scene;
    change_sprite_btn(button_list->next->next->button,
        (sfVector2f){WD_WIDTH / 2 + 200, WD_HEIGHT / 2},
        (sfIntRect){32, 0, 16, 16});
    button_list->next->next->method_event = *go_back_scene;
}

void map_select(game_object_t *game_asset, sfRenderWindow *window,
menu_t *menu_obj)
{
    sfEvent event;
    remap_btn(menu_obj->button_list);
    while (game_asset->scene == MAP) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events_menu(window, event, menu_obj, game_asset);
            analyse_events(window, event, game_asset);
        }
        display_btn(window, menu_obj->button_list);
        sfRenderWindow_drawSprite(window,game_asset->cursor , NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfColor_fromRGBA(149, 125, 173, 60));
    }
    reset_button_list(menu_obj->button_list);
}
