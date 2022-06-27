/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** build_loop
*/

#include "defender.h"

static void display_round(sfRenderWindow *window,
game_object_t *game_asset, game_t *game_obj)
{
    sfRenderWindow_drawSprite(window, game_obj->background, NULL);
    dislplay_building(window, game_obj->building_head, sfTrue);
    display_hud(window, game_obj->hud_obj);
    sfRenderWindow_drawSprite(window, game_obj->hud_obj->visualisation , NULL);
    sfRenderWindow_drawSprite(window, game_asset->cursor , NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfColor_fromRGBA(121, 210, 230, 100));
}

void static event_manage(sfRenderWindow *window, game_object_t *game_asset,
game_t *game_obj, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events(window, event, game_asset);
            analyse_events_game(window, event, game_asset, game_obj);
            analyse_events_build(window, event, game_asset, game_obj);
            game_asset->state_click = 0;
    }
}

void static action(sfRenderWindow *window, game_object_t *game_asset,
game_t *game_obj, sfClock *clock)
{
    if ((float)sfClock_getElapsedTime(clock).microseconds
        / 1000.0f > 100.0f) {
            update_hud(game_obj, clock);
            sfClock_restart(clock);
    }
    if (catch_pause(game_asset, window, game_obj))
        reset_button_list(game_obj->hud_obj->button_list);
}

void building_round(game_object_t *game_asset, sfRenderWindow *window,
game_t *game_obj)
{
    sfEvent event;
    sfClock *clock = sfClock_create();

    reset_button_list(game_obj->hud_obj->button_list);
    game_obj->hud_obj->loose = sfFalse;
    while (game_obj->scene == BUILDING_ROUND) {
        event_manage(window, game_asset, game_obj, event);
        action(window, game_asset, game_obj, clock);
        display_round(window, game_asset, game_obj);
    }
    sfClock_destroy(clock);
}
