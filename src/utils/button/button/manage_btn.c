/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-lucas.brahimi
** File description:
** manage_btn
*/

#include "defender.h"

void reset_button_list(button_t *button_list)
{
    while (button_list != NULL) {
        reset_button(button_list);
        button_list = button_list->next;
    }
}

void change_sprite_btn(sfSprite *sprite, sfVector2f pos, sfIntRect size)
{
    sfSprite_setTextureRect(sprite, size);
    sfSprite_setPosition(sprite, pos);
}

button_t *reset_button(button_t *button_obj)
{
    sfSprite_setPosition(button_obj->button, button_obj->position);
    sfSprite_setTextureRect(button_obj->button, button_obj->size);
    button_obj->method_event = button_obj->method_event_reset;
}

void disappear_btn(button_t *button_list)
{
    while (button_list != NULL) {
        change_sprite_btn(button_list->button,
        (sfVector2f){-500, -500}, (sfIntRect){0, 48, 16, 16});
        button_list = button_list->next;
    }
}