/*
** EPITECH PROJECT, 2022
** dev_menu
** File description:
** init_buton
*/

#include "defender.h"

static button_t *init_button(button_t *button_obj)
{
    button_t *out_btn = malloc(sizeof(button_t));

    out_btn->position = button_obj->position;
    out_btn->size = button_obj->size;
    out_btn->scale = button_obj->scale;
    out_btn->method_event = button_obj->method_event;
    out_btn->method_event_reset = button_obj->method_event;
    out_btn->button = init_sprite(out_btn->position, out_btn->size,
        "resources/menu/button_stone.png");
    sfSprite_setScale(out_btn->button, out_btn->scale);
    return out_btn;
}

void add_btn(button_t **head, button_t *button_obj)
{
    button_t *new_node = init_button(button_obj);
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    button_t *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}

int destroy_btn(button_t *button_list)
{
    button_t *tmp;

    while (button_list != NULL) {
        tmp = button_list;
        sfSprite_destroy(button_list->button);
        free(button_list);
        button_list = tmp->next;
    }
}
