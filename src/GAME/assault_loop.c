/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** assault_loop
*/

#include "defender.h"

static void remap_btn(button_t *button_list)
{
    change_sprite_btn(button_list->next->button,
        (sfVector2f){-200, -200}, (sfIntRect){0, 48, 16, 16});
    change_sprite_btn(button_list->next->next->button,
        (sfVector2f){-200, -200}, (sfIntRect){0, 48, 16, 16});
    change_sprite_btn(button_list->next->next->next->button,
        (sfVector2f){-200, -200}, (sfIntRect){0, 48, 16, 16});
}

static void display_round(sfRenderWindow *window, game_object_t *game_asset,
game_t *game_obj)
{
    sfRenderWindow_drawSprite(window, game_obj->background, NULL);
    dislplay_building(window, game_obj->building_head, sfFalse);
    dislplay_enemy(window, game_obj->enemy_head);
    display_hud(window, game_obj->hud_obj);
    sfRenderWindow_drawSprite(window,game_asset->cursor , NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfColor_fromRGBA(121, 210, 230, 100));
}

int static catch_end(game_t *game_obj)
{
    if (game_obj->dead_enemies >= game_obj->nbr_enemy) {
        return 1;
    } else if (game_obj->health <= 0) {
        my_putstr("LOOSE\n");
        game_obj->hud_obj->loose = sfTrue;
        game_obj->pause = sfTrue;
        return 0;
    } else
        return 0;
}

static void action(game_t *game_obj, sfClock *clock)
{
    if (catch_end(game_obj))
            game_obj->scene = BUILDING_ROUND;
    else if ((float)sfClock_getElapsedTime(clock).microseconds /
        1000.0f > 100.0f) {
        update_hud(game_obj, clock);
        attack_enemie(game_obj);
        sfClock_restart(clock);
    }
    move_enemy(game_obj->enemy_head,game_obj->building_head->position,
        game_obj);
}

void assault_round(game_object_t *game_asset, sfRenderWindow *window,
game_t *game_obj)
{
    sfEvent event;
    sfClock *clock = sfClock_create();

    pop_up_text(nbr_to_str(game_obj->rounds),
        100, game_asset->game_obj->hud_obj);
    remap_btn(game_obj->hud_obj->button_list);
    game_obj->nbr_enemy *= game_obj->rounds;
    load_enemy(game_obj, game_obj->nbr_enemy);
    while (game_obj->scene == ASSAULT_ROUND) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events_game(window, event, game_asset, game_obj);
            analyse_events(window, event, game_asset);
        }
        action(game_obj, clock);
        if (catch_pause(game_asset, window, game_obj)) {
            reset_button_list(game_obj->hud_obj->button_list);
            remap_btn(game_obj->hud_obj->button_list);
        }
        display_round(window, game_asset, game_obj);
    }
    game_obj->rounds += 1;
    game_obj->dead_enemies = 0;
    destroy_enemy(game_obj->enemy_head);
    reset_button_list(game_obj->hud_obj->button_list);
    sfClock_destroy(clock);
}
