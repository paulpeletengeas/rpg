/*
** EPITECH PROJECT, 2019
** rpg_attack
** File description:
** struct
*/

#ifndef ENEMY_H_
    #define ENEMY_H_

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>

typedef struct enemy_life_s {
    float health;
    sfRectangleShape *disp_life;
} enemy_life_t;

typedef struct fire
{
    sfIntRect rect;
    int offset;
    sfClock *clock;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f start;
    sfVector2f end;
    float range;
    struct fire *next;
} fire_t;

typedef struct magic {
    sfIntRect rect;
    int offset;
    sfClock *clock;
    sfSprite *sprite;
    sfVector2f pos;
    bool fire;
    int delay;
} magic_t;

typedef struct enemy_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2f dir;
    sfClock *clock;
    struct enemy_life_s *life;
    struct enemy_s *next;
} enemy_t;

#endif /* !ENEMY_H_ */
