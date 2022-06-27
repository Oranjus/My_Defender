/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** listen_event
*/

#include "defender.h"

int exec_btn_method(sfVector2f pos_onclick, game_object_t *game_asset,
button_t *button_obj)
{
    if (check_hitbox(button_obj->button, pos_onclick)
    && button_obj->method_event != NULL) {
        sfMusic_stop(game_asset->music_click);
        sfMusic_play(game_asset->music_click);
        button_obj->method_event(game_asset);
        game_asset->state_click = 1;
        return 1;
    } else {
        return 0;
    }
}

int listen_event_btn(sfVector2f pos_onclick, game_object_t *game_asset,
button_t *button_head)
{
    while (button_head != NULL) {
        exec_btn_method(pos_onclick, game_asset, button_head);
        button_head = button_head->next;
    }
}
