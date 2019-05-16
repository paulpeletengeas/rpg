/*
** EPITECH PROJECT, 2019
** rpg_attack
** File description:
** display_sprites
*/

#include "proto.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

static sfVector2f life_size(float health)
{
    sfVector2f new_size = {health / 100.0, 1};

    return (new_size);
}

static sfVector2f life_pos(sfVector2f pos)
{
    sfVector2f new_pos = {pos.x - 20, pos.y - 35};

    return (new_pos);
}

void    display_sprites(enemy_t *enemy, sfRenderWindow *win)
{
    enemy_t *current = enemy;

    while (current) {
        sfSprite_setPosition(current->sprite, current->pos);
        sfRectangleShape_setPosition(current->life->disp_life,
                                     life_pos(current->pos));
        sfRectangleShape_setScale(current->life->disp_life,
                                  life_size(current->life->health));
        sfRenderWindow_drawSprite(win, current->sprite, NULL);
        sfRenderWindow_drawRectangleShape(win, current->life->disp_life, NULL);
        current = current->next;
    }
}
