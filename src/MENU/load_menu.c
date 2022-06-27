/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_menu
*/

#include "defender.h"

int load_menu(menu_t *menu_obj)
{
    menu_obj->scene = MAIN;
    load_button(menu_obj);
    load_text(menu_obj);
    menu_obj->background = init_sprite((sfVector2f){0, 0},
        (sfIntRect){-1}, "resources/menu/background.png");
    my_putstr("load_menu\n");
}

int free_menu(menu_t *menu_obj)
{
    sfText_destroy(menu_obj->title);
    sfSprite_destroy(menu_obj->background);
    destroy_btn(menu_obj->button_list);
    free(menu_obj);
    my_putstr("free_menu\n");
}

void load_text(menu_t *menu_obj)
{
    menu_obj->title = sfText_create();
    sfFloatRect size;

    sfText_setString(menu_obj->title, "my defender");
    sfText_setOutlineThickness(menu_obj->title, 5);
    sfText_setOutlineColor(menu_obj->title,
        sfColor_fromRGBA(255, 255, 255, 244));
    sfText_setCharacterSize(menu_obj->title, 150);
    sfText_setFont(menu_obj->title, sfFont_createFromFile(
    "resources/FONT/GAMERIA.ttf"));
    size = sfText_getGlobalBounds(menu_obj->title);
    sfText_setOrigin(menu_obj->title,
        (sfVector2f){size.width / 2, size.height / 2});
    sfText_setPosition(menu_obj->title, (sfVector2f){WD_WIDTH / 2, 30});
    sfText_setColor(menu_obj->title, sfColor_fromRGBA(11, 11, 69, 244));
}
