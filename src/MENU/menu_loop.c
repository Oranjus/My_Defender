/*
** EPITECH PROJECT, 2022
** menu
** File description:
** menu_loop
*/

#include "defender.h"

static event_manager(sfRenderWindow *window, sfEvent event,
game_object_t *game_asset, menu_t *menu_obj)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, game_asset);
            analyse_events_menu(window, event, menu_obj, game_asset);
            game_asset->state_click = 0;
        }
}

int menu_loop(game_object_t *game_asset, sfRenderWindow *window)
{
    sfEvent event;
    menu_t *menu_obj = malloc(sizeof(menu_t));

    load_menu(menu_obj);
    while (game_asset->scene == MENU) {
        event_manager(window, event, game_asset, menu_obj);
        switch (game_asset->scene) {
            case MAP:
                map_select(game_asset, window, menu_obj);
                break;
            case TROPHEA:
                trophea(game_asset, window, menu_obj);
                break;
            case INFO:
                info(game_asset, window, menu_obj);
                break;
        }
        display_menu(window, menu_obj, game_asset);
    }
    free_menu(menu_obj);
}
