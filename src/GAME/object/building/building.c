/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** building
*/

#include "defender.h"

void update_build(building_t *head)
{
    sfIntRect max_rect = {0, 0, 1828, 108};
    sfIntRect offset = {80, 108, 80, 108};

    while (head != NULL) {
        anim_sprite(head->sprite, offset, max_rect);
        head = head->next;
    }
}
