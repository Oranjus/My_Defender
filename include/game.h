/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include "defender.h"

typedef struct game_object game_object_t;
typedef struct hud hud_t;

typedef enum {
    CASTLE,
    CATAPULTE,
    WIZARD,
    SMALL_CASTLE
} building;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} direction;

typedef enum {
    BUILDING_ROUND,
    ASSAULT_ROUND,
    PAUSE_ROUND,
    QUIT_GAME
} game_scene;

typedef struct build_stat {
    float radius;
    char *filepath;
    sfIntRect size;
    int price;
    int damage;
} build_stat_t;

typedef struct building {
    build_stat_t stat;
    sfSprite *sprite;
    sfVector2f position;
    sfCircleShape *area;
    void (*action_on_click)(game_object_t *);
    struct building *next;
} building_t;

typedef struct enemie_stat {
    char *filepath;
    sfIntRect size;
    int health;
    int price;
    int damage;
    int dead;
} enemie_stat_t;

typedef struct enemy {
    enemie_stat_t stat;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f direction;
    void (*action_on_click)(game_object_t *);
    struct enemy *next;
} enemy_t;

typedef struct game {
    game_scene scene;
    sfSprite *background;
    sfMusic *music;
    hud_t *hud_obj;
    building_t *building_head;
    enemy_t *enemy_head;
    char *filepath_bg;
    building selected_build;
    sfBool pause;
    int rounds;
    int gold;
    int health;
    int nbr_enemy;
    int dead_enemies;
    int score;
} game_t;

//game_loop
int game_loop(game_object_t *game_asset, sfRenderWindow *window);

//display
void display_game(sfRenderWindow *window,game_object_t *game_asset,
game_t *game_obj);
void dislplay_enemy(sfRenderWindow *window, enemy_t *head);
void dislplay_building(sfRenderWindow *window, building_t *head, sfBool bool);

//load
void load_game(game_t *game_obj);
int destroy_game(game_t *game_obj);

//event
void analyse_events_game(sfRenderWindow *window, sfEvent event
, game_object_t *game_asset, game_t *game_obj);
void analyse_events_build(sfRenderWindow *window, sfEvent event
, game_object_t *game_asset, game_t *game_obj);

//pause
void pause_round(game_object_t *game_asset, sfRenderWindow *window,
game_t *game_obj);
int catch_pause(game_object_t *game_asset, sfRenderWindow *window,
game_t *game_obj);

//assault_loop
void assault_round(game_object_t *game_asset, sfRenderWindow *window,
game_t *game_obj);

//building
void building_round(game_object_t *game_asset, sfRenderWindow *window,
game_t *game_obj);
build_stat_t select_build_type(building build_type);
void place_building(game_t *game_obj, sfVector2f pos);
void attack_tower(enemy_t *enemy, building_t *building_list);
void add_node(building_t **head, build_stat_t stat, sfVector2f pos);
void place_new_build(game_t *game_obj, sfVector2f pos, building build_type);
void destroy_building(building_t *head);

//enemy
void load_enemy(game_t *game_obj, int nbr);
void create_n_list(int lenght, enemy_t **root);
void move_enemy(enemy_t *head, sfVector2f coo_main_castle, game_t *game_obj);
void init_move(enemy_t *head, building_t *main_castle);
sfVector2f get_pos_random(int randomiser, sfIntRect zone);
sfIntRect get_random_zone(direction dir);
void destroy_enemy(enemy_t *head);
void attack_enemie(game_t *game_obj);
void add_node_enemie(enemy_t **head, enemie_stat_t stat, int randomiser,
sfIntRect zone);

#endif /* !GAME_H_ */
