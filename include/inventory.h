/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** inventory object
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

typedef struct item_s {
    sfTexture *texture;
    sfSprite *sprite;
    int item_id;
    struct item_s *next;
} item_t;

struct inventory_s {
    size_t cursor;
    size_t item_id;
    sfClock *bound;
    sfRectangleShape *shape;
    struct item_s *items;
};

typedef struct inventory_s inventory_t;

#endif /* INVENTORY_H_ */
