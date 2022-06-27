/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** manage_enemie
*/

#include "defender.h"

static sfVector2f calc_vector(sfVector2f enemy, sfVector2f build)
{
    sfVector2f vector_dir = {(build.x - enemy.x), (build.y - enemy.y)};
    float norme = ABS(vector_dir.x);
    norme += ABS(vector_dir.y);
    norme = ABS(norme);
    vector_dir = (sfVector2f){(vector_dir.x / norme), (vector_dir.y / norme)};
    return vector_dir;
}

void init_move(enemy_t *head, building_t *main_castle)
{
    while (head != NULL && main_castle != NULL) {
        head->direction = calc_vector(head->position,
            sfSprite_getPosition(main_castle->sprite));
        head = head->next;
    }
}

void move_enemy(enemy_t *head, sfVector2f coo_main_castle, game_t *game_obj)
{
    while (head != NULL) {
        if (!check_hitbox(head->sprite, coo_main_castle)) {
            sfSprite_move(head->sprite, head->direction);
        } else {
            game_obj->dead_enemies += 1;
            game_obj->health -= head->stat.damage;
            head->stat.damage = 0;
            sfSprite_setScale(head->sprite, (sfVector2f){0, 0});
        }
        head = head->next;
    }
}

void attack_enemie(game_t *game_obj)
{
    enemy_t *head = game_obj->enemy_head;
    building_t *building_list = game_obj->building_head;

    while (head != NULL) {
        attack_tower(head, building_list);
        if (head->stat.health <= 0 && head->stat.dead != 1) {
            game_obj->gold += head->stat.price;
            game_obj->dead_enemies += 1;
            head->stat.dead = 1;
            head->stat.damage = 0;
            sfSprite_setScale(head->sprite, (sfVector2f){0, 0});
            return;
        }
        head = head->next;
    }
}
