/*
** EPITECH PROJECT, 2019
** rpg_attack
** File description:
** enemy_move
*/

#include "proto.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

void    get_angle(sfSprite *sprite, sfVector2f dir)
{
    float pi = 3.141592653589;
    float angle = asin(dir.y / vector_dist(dir)) * 180 / pi;

    if (dir.x < 0) {
        angle += 180;
        angle *= (-1);
    }
    sfSprite_setRotation(sprite, angle);
}

void    enemy_move(game_obj *obj, enemy_t *enemy, sfVector2f player)
{
    enemy_t *current = enemy;

    while (current) {
        current->dir.x = player.x - current->pos.x;
        current->dir.y = player.y - current->pos.y;
        get_angle(current->sprite, current->dir);
        if (sfClock_getElapsedTime(current->clock).microseconds
            / 1000000.0 >= 0.001 && vector_dist(current->dir) <= 200 &&
            vector_dist(current->dir) >= 45) {
            if (vector_dist(current->dir) <= 55)
                obj->player->life -= 0.1;
            current->dir = normalize_vector(current->dir);
            current->pos.x += current->dir.x;
            current->pos.y += current->dir.y;
            sfClock_restart(current->clock);
        }
        sfSprite_setPosition(current->sprite, current->pos);
        current = current->next;
    }
}
