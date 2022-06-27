/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** trophea
*/

#include "defender.h"

static char *rules(char const *filepath, char *buffer)
{
    buffer = malloc(sizeof(char)*(1500));
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    read(fd, buffer, 1500);
    return buffer;
}

static void remap_btn(button_t *button_list)
{
    disappear_btn(button_list);
    change_sprite_btn(button_list->button,
        (sfVector2f){50, 50}, (sfIntRect){0, 48, 16, 16});
    button_list->method_event = *go_back_scene;
}

void trophea(game_object_t *game_asset, sfRenderWindow *window,
menu_t *menu_obj)
{
    sfEvent event;
    char *buffer = rules("resources/menu/info.txt", buffer);
    remap_btn(menu_obj->button_list);
    sfText *text_info = init_text((sfVector2f){100, 100}, 20, buffer);
    while (game_asset->scene == TROPHEA) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            analyse_events_menu(window, event, menu_obj, game_asset);
            analyse_events(window, event, game_asset);
        }
        display_btn(window, menu_obj->button_list);
        sfRenderWindow_drawText(window, text_info, NULL);
        sfRenderWindow_drawSprite(window, game_asset->cursor , NULL);
        sfRenderWindow_display(window);
        sfRenderWindow_clear(window, sfColor_fromRGBA(149, 125, 173, 60));
    }
    reset_button_list(menu_obj->button_list);
    free(buffer);
}
