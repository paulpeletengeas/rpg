/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** function prototypes
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "map.h"
#include "player.h"
#include "gui.h"
#include "menu.h"

typedef struct xml
{
    int x;
    int y;
    int width;
    int height;
} xml_obj;

typedef struct parallax
{
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
} parallax_t;

typedef struct system
{
    sfRenderWindow *win;
    sfClock *clock;
    int view;
} sys_t;

typedef struct sound_design
{
    sfClock *bound;
    sfMusic *music;
    sfMusic *click;
} sound_t;

typedef struct pnj_s {
    sfSprite *spt_pnj;
} pnj_t;

typedef struct game
{
    struct system *sys;
    struct sound_design *sound;
    struct player *player;
    struct enemy_s *enemy;
    struct parallax **bg;
    struct pnj_s *pnj;
    struct utility *use;
    struct map *map;
    struct hud *hud;
    struct fire *fire;
    struct s_part *parts;
    struct magic *spell;
} game_obj;

#endif /* STRUCT_H_ */
