/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** display_hud
*/

#include "defender.h"

void display_hud(sfRenderWindow *window, hud_t *hud)
{
    sfRenderWindow_drawText(window, hud->nb_gold, NULL);
    if (hud->loose == sfTrue)
        sfRenderWindow_drawText(window, hud->loose_text, NULL);
    if (hud->couldown_text > 0) {
        hud->couldown_text -= 1;
        sfRenderWindow_drawText(window, hud->info_text, NULL);
    }
    sfRenderWindow_drawSprite(window, hud->coin, NULL);
    sfRenderWindow_drawSprite(window, hud->health_bar, NULL);
    sfRenderWindow_drawSprite(window, hud->health, NULL);
    display_btn(window, hud->button_list);
}
