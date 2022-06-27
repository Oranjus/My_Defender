/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** init_build
*/

#include "defender.h"

static void init_area(building_t *build, build_stat_t stat, sfVector2f pos)
{
    build->area = sfCircleShape_create();
    sfCircleShape_setOrigin(build->area,
        (sfVector2f){stat.radius, stat.radius});
    sfCircleShape_setPosition(build->area, pos);
    sfCircleShape_setFillColor(build->area, sfColor_fromRGBA(0, 0, 0, 0));
    sfCircleShape_setRadius(build->area, stat.radius);
    sfCircleShape_setOutlineColor(build->area, sfColor_fromRGB(255, 105, 97));
    sfCircleShape_setOutlineThickness(build->area, 2);
}

static void load_build_node(building_t *node, build_stat_t stat,
sfVector2f pos)
{
    node->stat = stat;
    node->position = pos;
    node->sprite = init_sprite(pos, stat.size, stat.filepath);
    init_area(node, stat, pos);
}

build_stat_t select_build_type(building build_type)
{
    build_stat_t stat;

    switch (build_type) {
    case CASTLE:
        stat = (build_stat_t)
        {150, "resources/game_sprite/archer_spritesheet.png",
        (sfIntRect){162, 0, 81, 116}, 600, 7};
        break;
    case CATAPULTE:
        stat = (build_stat_t)
        {100, "resources/game_sprite/catapute_spritesheet.png",
        (sfIntRect){0, 0, 80, 108}, 150, 6};
        break;
    case WIZARD:
        stat = (build_stat_t)
        {200, "resources/game_sprite/wizard_spritesheet.png",
        (sfIntRect){217, 0, 78, 71}, 1000, 10};
        break;
    case SMALL_CASTLE:
        stat = (build_stat_t)
        {125, "resources/game_sprite/tower_spritesheet.png",
        (sfIntRect){973, 0, 90, 100}, 250, 6};
        break;
    }
    return stat;
}

void add_node(building_t **head, build_stat_t stat, sfVector2f pos)
{
    building_t *new_node = malloc(sizeof(building_t));
    new_node->next = NULL;
    load_build_node(new_node, stat, pos);

    if (*head == NULL) {
        sfSprite_setColor(new_node->sprite,
            sfColor_fromRGB(101, 147, 245));
        *head = new_node;
        return;
    }
    building_t *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}

void destroy_building(building_t *head)
{
    building_t *temp;

    while (head != NULL) {
        temp = head;
        sfSprite_destroy(head->sprite);
        free(head);
        head = temp->next;
    }
}
