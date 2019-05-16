/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** gui structs
*/

#ifndef GUI_H_
#define GUI_H_

#include "inventory.h"

typedef struct life
{
    float state;
    sfSprite *heart;
    sfSprite *container;
    struct life *next;
} life_t;

typedef struct gold
{
    sfClock *clock;
    sfTexture *texture;
    sfSprite *sprite;
    sfText *text;
    sfFont *font;
} gold_t;

typedef struct hud
{
    sfTexture *texture;
    sfSprite *inventory;
    struct gold *gold;
    struct life *life;
    struct inventory_s *selector;
} hud_t;

#endif /* GUI_H_ */
