/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** display_game
*/

#include "defender.h"

void display_game(sfRenderWindow *window, game_object_t *game_asset,
game_t *game_obj)
{
    sfRenderWindow_drawSprite(window, game_obj->background, NULL);

    dislplay_building(window, game_obj->building_head, sfTrue);
    if (game_obj->scene == ASSAULT_ROUND)
        dislplay_enemy(window, game_obj->enemy_head);
    display_hud(window, game_obj->hud_obj);
    sfRenderWindow_drawSprite(window,game_asset->cursor , NULL);
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfColor_fromRGBA(121, 210, 230, 100));
}

void dislplay_enemy(sfRenderWindow *window, enemy_t *head)
{
    while (head != NULL) {
        if (head->sprite != NULL)
            sfRenderWindow_drawSprite(window, head->sprite , NULL);
        head = head->next;
    }
}

void dislplay_building(sfRenderWindow *window, building_t *head, sfBool bool)
{
    while (head != NULL) {
        if (bool == sfTrue)
            sfRenderWindow_drawCircleShape(window, head->area, NULL);
        sfRenderWindow_drawSprite(window, head->sprite , NULL);
        head = head->next;
    }
}
