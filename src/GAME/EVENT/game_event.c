/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** game_event
*/

#include "defender.h"

void analyse_events_build(sfRenderWindow *window, sfEvent event
, game_object_t *game_asset, game_t *game_obj)
{
    sfVector2f pos_onclick;

    if (event.type == sfEvtMouseButtonPressed
    && game_asset->state_click == 0) {
        pos_onclick = (sfVector2f){event.mouseButton.x, event.mouseButton.y};
        place_new_build(game_obj, pos_onclick, game_obj->selected_build);
        game_asset->state_click = 1;
    }
}

void analyse_events_game(sfRenderWindow *window, sfEvent event
, game_object_t *game_asset, game_t *game_obj)
{
    sfVector2f pos_onclick;

    if (event.type == sfEvtClosed) {
        close_game(game_asset);
    } else if (event.type == sfEvtMouseButtonPressed
    && game_asset->state_click == 0) {
        pos_onclick = (sfVector2f){event.mouseButton.x, event.mouseButton.y};
        listen_event_btn(pos_onclick, game_asset,
            game_obj->hud_obj->button_list);
    }
}
