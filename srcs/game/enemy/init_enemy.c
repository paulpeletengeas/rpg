/*
** EPITECH PROJECT, 2019
** rpg_attack
** File description:
** init_enemy
*/

#include "proto.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

static enemy_life_t *create_enemy_life(sfVector2f pos)
{
    enemy_life_t *dest = malloc(sizeof(enemy_life_t));
    sfVector2f life_pos = {pos.x - 20, pos.y - 20};
    sfVector2f size = {50, 5};

    if (!dest)
        return (NULL);
    dest->health = 100.0;
    dest->disp_life = sfRectangleShape_create();
    sfRectangleShape_setSize(dest->disp_life, size);
    sfRectangleShape_setFillColor(dest->disp_life, sfRed);
    sfRectangleShape_setPosition(dest->disp_life, life_pos);
    return (dest);
}

static enemy_t *create_node(sfTexture *texture)
{
    enemy_t *dest = malloc(sizeof(enemy_t));
    sfVector2f origin = {17, 22};
    static sfVector2f offset;
    offset.x = rand() % 1650;
    offset.y =  rand() % 800;
    sfVector2f scale = {1.2, 1.2};

    if (!dest || !(dest->clock = sfClock_create()) ||
        !(dest->life = create_enemy_life(offset)))
        return (NULL);
    dest->texture = texture;
    dest->sprite = sfSprite_create();
    dest->scale = scale;
    dest->pos = offset;
    sfSprite_setOrigin(dest->sprite, origin);
    sfSprite_setScale(dest->sprite, dest->scale);
    sfSprite_setTexture(dest->sprite, dest->texture, sfTrue);
    dest->next = NULL;
    offset.x += rand() % 160 - 80;
    offset.y += rand() % 160 - 80;
    return (dest);
}

static int add_enemy(enemy_t **list, sfTexture *texture)
{
    enemy_t *node = create_node(texture);
    enemy_t *current = *list;

    if (!node)
        return (84);
    if (!(*list)) {
        *list = node;
        return (0);
    }
    while (current->next) {
        current = current->next;
    }
    current->next = node;
    return (0);
}

enemy_t    *init_enemy(int nb)
{
    size_t i = 0;
    enemy_t *head = NULL;
    sfTexture *texture = sfTexture_createFromFile("./assets/enemy/zomb.png",
                                                     NULL);

    if (!texture)
        return (NULL);
    while (i < (size_t)nb) {
        if (add_enemy(&head, texture))
            return (NULL);
        i++;
    }
    return (head);
}
