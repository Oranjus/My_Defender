/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** enemie
*/

#include "defender.h"

static void load_enemy_sprite(enemy_t *enemy_obj, enemie_stat_t stat,
int randomiser, sfIntRect zone)
{
    enemy_obj->stat = stat;
    enemy_obj->position = get_pos_random(randomiser, zone);
    enemy_obj->sprite = init_sprite(enemy_obj->position,
        enemy_obj->stat.size, enemy_obj->stat.filepath);
}

void add_node_enemie(enemy_t **head, enemie_stat_t stat, int randomiser,
sfIntRect zone)
{
    enemy_t *new_node = malloc(sizeof(enemy_t));
    new_node->next = NULL;
    load_enemy_sprite(new_node, stat, randomiser, zone);

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    enemy_t *curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new_node;
}

void create_n_list(int lenght, enemy_t **root)
{
    srand(488856565 * 4);
    sfIntRect zone = get_random_zone(rand() % 4);
    enemie_stat_t stat = (enemie_stat_t){"resources/game_sprite/enemie.png",
        (sfIntRect){0, 0, 40, 33}, 25, 15, 25, 0};

    for (int i = 0; i < lenght; i++) {
        add_node_enemie(root, stat, i, zone);
    }
}

void destroy_enemy(enemy_t *head)
{
    enemy_t *temp;

    while (head != NULL) {
        temp = head;
        sfSprite_destroy(head->sprite);
        free(head);
        head = temp->next;
    }
}
