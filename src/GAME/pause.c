/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** pause
*/

#include "defender.h"

static void remap_btn(button_t *button_list, game_t *game_obj)
{
    disappear_btn(button_list);
    change_sprite_btn(game_obj->hud_obj->button_list->button,
    (sfVector2f){WD_WIDTH / 2, 200}, (sfIntRect){32, 0, 16, 16});
    game_obj->hud_obj->button_list->method_event = *set_pause;
    change_sprite_btn(game_obj->hud_obj->button_list->next->button,
    (sfVector2f)(sfVector2f){WD_WIDTH / 2, 300}, (sfIntRect){32, 16, 16, 16});
    game_obj->hud_obj->button_list->next->method_event = *go_to_menu;
    change_sprite_btn(game_obj->hud_obj->button_list->next->next->button,
    (sfVector2f)(sfVector2f){WD_WIDTH / 2, 400}, (sfIntRect){0, 0, 16, 16});
    game_obj->hud_obj->button_list->next->next->method_event = *close_game;
}

void pause_round(game_object_t *game_asset, sfRenderWindow *window,
game_t *game_obj)
{
    sfEvent event;

    reset_button_list(game_obj->hud_obj->button_list);
    remap_btn(game_obj->hud_obj->button_list, game_obj);
    while (game_obj->pause == sfTrue && (game_obj->scene == ASSAULT_ROUND
        || game_obj->scene == BUILDING_ROUND)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events_game(window, event, game_asset, game_obj);
            analyse_events(window, event, game_asset);
            game_asset->state_click = 0;
        }
        display_game(window, game_asset, game_obj);
    }
}

int catch_pause(game_object_t *game_asset, sfRenderWindow *window,
game_t *game_obj)
{
    if (game_obj->pause == sfTrue){
        pause_round(game_asset, window, game_obj);
        return 1;
    }
    game_obj->pause = sfFalse;
    return 0;
}
