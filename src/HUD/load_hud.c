/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_hud
*/

#include "defender.h"

static void load_button_hud(hud_t *hud)
{
    hud->button_list = NULL;
    add_btn(&(hud->button_list), &(button_t) {
        {50, 50}, {16, 16, 16, 16}, {5, 5}, *set_pause});
    add_btn(&(hud->button_list), &(button_t) {
        {WD_WIDTH / 2, 50}, {0, 64, 16, 16}, {5, 5}, *launch_assault});
    add_btn(&(hud->button_list), &(button_t) {
        {WD_WIDTH / 2 + 100, WD_HEIGHT - 50}, {32, 0, 16, 16}, {4, 4},
        next_visualisation});
    add_btn(&(hud->button_list), &(button_t) {
        {WD_WIDTH / 2 - 100, WD_HEIGHT - 50}, {0, 16, 16, 16}, {4, 4},
        previous_visualisation});
}

static void load_sprite_hud(hud_t *hud_obj)
{
    hud_obj->coin =
        init_sprite((sfVector2f){WD_WIDTH - 30, 100},
            (sfIntRect){0, 0, 16, 16}, "resources/hud/coin.png");
        sfSprite_setScale(hud_obj->coin, (sfVector2f){2, 2});
    hud_obj->health_bar =
        init_sprite((sfVector2f){WD_WIDTH - 143, 29},
            (sfIntRect){35, 33, 59, 7}, "resources/hud/health_bar.png");
        sfSprite_setScale(hud_obj->health_bar, (sfVector2f){-2, 2});
    hud_obj->health =
        init_sprite((sfVector2f){WD_WIDTH - 110, 35},
            (sfIntRect){0, 0, 97, 32}, "resources/hud/health_bar.png");
        sfSprite_setScale(hud_obj->health, (sfVector2f){-2, 2});
    hud_obj->visualisation =
        init_sprite((sfVector2f){WD_WIDTH / 2, WD_HEIGHT - 90},
            (sfIntRect){0, 0, 111, 157}, "resources/hud/visualisation.png");
        sfSprite_setScale(hud_obj->visualisation, (sfVector2f){1, 1});
}

static void load_text_hud(hud_t *hud_obj)
{
    hud_obj->nb_gold = init_text(
        (sfVector2f){WD_WIDTH - 120, 75}, 40, NULL);
    sfText_setColor(hud_obj->nb_gold, sfColor_fromRGBA(255, 159, 0, 244));
    sfText_setFont(hud_obj->nb_gold,
        sfFont_createFromFile("resources/FONT/GAMERIA.ttf"));
    sfText_setOutlineThickness(hud_obj->nb_gold, 5);
    hud_obj->loose_text = init_text(
    (sfVector2f){WD_WIDTH / 2 - 187, WD_HEIGHT / 2 - 63}, 70, "YOU LOOSE");
    sfText_setColor(hud_obj->loose_text, sfColor_fromRGB(194, 59, 34));
    sfText_setFont(hud_obj->loose_text,
        sfFont_createFromFile("resources/FONT/GAMERIA.ttf"));
    sfText_setOutlineThickness(hud_obj->loose_text, 5);
    hud_obj->info_text = init_text(
    (sfVector2f){WD_WIDTH / 2 - 187, WD_HEIGHT / 2 - 63}, 30, NULL);
    sfText_setColor(hud_obj->info_text, sfColor_fromRGB(133, 3, 3));
    sfText_setFont(hud_obj->info_text,
        sfFont_createFromFile("resources/FONT/GAMERIA.ttf"));
}

void load_hud(hud_t *hud_obj)
{
    load_button_hud(hud_obj);
    load_sprite_hud(hud_obj);
    load_text_hud(hud_obj);
}

void destroy_hud(hud_t *hud)
{
    sfText_destroy(hud->nb_gold);
    sfText_destroy(hud->info_text);
    sfText_destroy(hud->loose_text);
    sfSprite_destroy(hud->coin);
    sfSprite_destroy(hud->health);
    sfSprite_destroy(hud->health_bar);
    sfSprite_destroy(hud->visualisation);
    destroy_btn(hud->button_list);
    free(hud);
}
