/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** event_menu
*/

#include "defender.h"

void analyse_events_menu(sfRenderWindow *window, sfEvent event,
menu_t *menu_obj, game_object_t *game_asset)
{
    sfVector2f pos_onclick = {-200, -200};

    if (event.type == sfEvtMouseButtonPressed) {
        sfVector2f pos_onclick = {event.mouseButton.x, event.mouseButton.y};
        listen_event_btn(pos_onclick, game_asset, menu_obj->button_list);
    }
}
