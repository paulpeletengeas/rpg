/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** function prototypes
*/

#ifndef PROTO_H_
#define PROTO_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include <stdbool.h>

#include "enemy.h"
#include "struct.h"
#include "particles.h"
#include "menu.h"

/*MENU*/
int display_strtmenu(game_obj *);
use_t *init_utility(void);
int strt_menu(game_obj *);
int display_pause(game_obj *obj);
int pause_menu(game_obj *obj);
int pause_menuevt(game_obj *, sfEvent);
int settings_option(game_obj *, sfEvent);
void setting_evt(game_obj *, sfEvent, int *, set_t *);
void draw_settingopt(game_obj *, set_t);
int check_settings(set_t *);
parallax_t **create_parallax(void);
void display_parallax(game_obj *obj);

/*UTILS*/
char *int_to_str(int);
int display_help(game_obj *);
int help_menu(game_obj *);
int my_atoi(char *);
int my_strlen(char *);
int compare(char *, char *);
int int_len(int nb);

/* SYSTEM FUNCTIONS */
fire_t *init_attack(void);
sys_t *create_sys(void);
sound_t *create_sound(void);
game_obj *create_game_object(void);
void kill_game_obj(game_obj *);
void toggle_vol(game_obj *, sfMusic *);

/* GAME FUNCTIONS */
int game_loop(game_obj *);

/* EVENT FUNCTION */
int analyse_event(game_obj *);
int check_keyboard(game_obj *);
void check_mouse(game_obj *, sfEvent);
int player_inrange(game_obj *);

/* MAP GEN */
map_t *create_map(void);
int add_tile(tile_t **, int, sfTexture *);
void display_map(game_obj *);
wild_t *create_wildlife(int, sfTexture *);
void free_wildlife(wild_t *);
int *randomize_biome(int);
sfIntRect get_tile_rect(int);
int reload_map(game_obj *);

/* HUD */
hud_t *create_hud(void);
void display_hud(game_obj *);
life_t *create_life(sfTexture *);
void display_life(game_obj *);
void display_gold(game_obj *);
gold_t *create_gold(void);

/* PLAYER */
int init_player(game_obj *);
void display_player(game_obj *);
void move_player(game_obj *);
void reset_player_pos(game_obj *);

/* PNJ | INTERACTION*/
game_obj *create_pnj_struct(game_obj *obj);
sfSprite *create_sprite(char *asset_path);
void show_pnj(game_obj *obj);

/* ENEMY */
enemy_t    *init_enemy(int);
void    display_sprites(enemy_t *enemy, sfRenderWindow *win);
void    get_time(enemy_t **);
float    vector_dist(sfVector2f);
sfVector2f    normalize_vector(sfVector2f);
void    enemy_move(game_obj *, enemy_t *, sfVector2f);
int check_enemy_life(game_obj *);
void    get_time(enemy_t **enemy);
float    vector_dist(sfVector2f dir);
sfVector2f    normalize_vector(sfVector2f dir);
void    enemy_move(game_obj *, enemy_t *enemy, sfVector2f);
int check_enemy_life(game_obj *obj);
void delete_enemy(enemy_t **, size_t);

/* ATTACK */
void    get_fire_coords(game_obj *);
sfVector2f    get_end_pos(game_obj *);
void    display_fire(game_obj *);
void    launch_fire(game_obj *);
int    init_spell(game_obj *);
void    display_spell(game_obj *);

/* PARTICLES */
part_t    *init_particles(game_obj *, int);
void    display_particles(game_obj *);

/* INVENTORY */
int draw_selector(game_obj *obj);
inventory_t *init_inventory(void);
void check_selector(game_obj *obj);
int get_item(game_obj *obj);
int put_in_inventory(game_obj *obj, item_t *to_copy);
int add_item_to_list(item_t **list, int item_id);
int display_items_in_inventory(game_obj *);

/* XML */
xml_obj *get_xml(char *filepath, char *name);
xml_obj *get_values(char *);
int skip(int, char *);

#endif /* PROTO_H_ */
