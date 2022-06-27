/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** manage_build
*/

#include "defender.h"

static float calc_distance(sfVector2f enemy, sfVector2f build)
{
    sfVector2f vector_dir = {(build.x - enemy.x), (build.y - enemy.y)};
    float norme = ABS(vector_dir.x);
    norme += ABS(vector_dir.y);
    norme = ABS(norme);
    return norme;
}

void static color_enemy(sfSprite * sprite)
{
    sfColor color = sfSprite_getColor(sprite);

    if (color.g == 105 && color.b == 97)
        sfSprite_setColor(sprite,
            sfColor_fromRGBA(255, 255, 255, 244));
    else
        sfSprite_setColor(sprite,
            sfColor_fromRGBA(255, 105, 97, 244));
}

void attack_tower(enemy_t *enemy, building_t *building_list)
{
    float radius = 0;
    float distance = 0;

    while (building_list != NULL) {
        radius = sfCircleShape_getRadius(building_list->area) + 50;
        distance = calc_distance(sfSprite_getPosition(enemy->sprite),
            building_list->position);
        if (distance <= radius) {
            enemy->stat.health -= building_list->stat.damage;
            color_enemy(enemy->sprite);
        }
        building_list = building_list->next;
    }
}

void place_new_build(game_t *game_obj, sfVector2f pos, building build_type)
{
    build_stat_t stat = select_build_type(build_type);

    if (game_obj->gold >= stat.price) {
        game_obj->gold -= stat.price;
        add_node(&(game_obj->building_head), stat, pos);
    } else {
        pop_up_text("cant t  afford\n",
            50, game_obj->hud_obj);
    }
}
