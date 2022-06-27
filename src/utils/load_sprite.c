/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** load_sprite
*/

#include "defender.h"

sfSprite *init_sprite(sfVector2f pos, sfIntRect size, char *filepath)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setOrigin(sprite, (sfVector2f){size.width / 2, size.height / 2});
    sfSprite_setTexture(sprite,
    sfTexture_createFromFile(filepath, NULL), sfFalse);
    if (size.left != -1)
        sfSprite_setTextureRect(sprite, size);
    sfSprite_setPosition(sprite , pos);
}

void anim_sprite(sfSprite *sprite, sfIntRect offset_rect, sfIntRect last)
{
    sfIntRect rect = sfSprite_getTextureRect(sprite);

    rect = (sfIntRect){rect.left + offset_rect.left, offset_rect.top,
        rect.width, rect.height};
    if (rect.left >= last.width || rect.top >= last.height) {
        rect = (sfIntRect){0, 0, rect.width, rect.height};
    }
    sfSprite_setTextureRect(sprite, rect);
}
