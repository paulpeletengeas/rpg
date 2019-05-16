/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** launch fire
*/

#include "proto.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

int    max_range(game_obj *obj)
{
    sfVector2f max;

    max.x = obj->fire->pos.x - obj->fire->start.x;
    max.y = obj->fire->pos.y - obj->fire->start.y;
    if (vector_dist(max) > obj->fire->range)
        return (1);
    return (0);
}

void    analyse_collision(game_obj *obj)
{
    enemy_t *current = obj->enemy;
    sfVector2f col;

    while (current) {
        col.x = obj->fire->pos.x - current->pos.x;
        col.y = obj->fire->pos.y - current->pos.y;
        if (vector_dist(col) < 30) {
            obj->player->gold += 10;
            current->life->health -= 75;
            obj->player->is_fire = false;
        }
        current = current->next;
    }
}

void    launch_fire(game_obj *obj)
{
    float i = 1000000.0;
    sfVector2f dist;

    dist.x = obj->fire->start.x - obj->fire->end.x;
    dist.y = obj->fire->start.y - obj->fire->end.y;
    if (sfClock_getElapsedTime(obj->fire->clock).microseconds / i >= 0.02
        && vector_dist(dist) != 0) {
        obj->fire->rect.left += obj->fire->offset;
        if (obj->fire->rect.left >= 512)
            obj->fire->rect.left = 0;
        dist = normalize_vector(dist);
        obj->fire->pos.x += dist.x * 8;
        obj->fire->pos.y += dist.y * 8;
        sfSprite_setPosition(obj->fire->sprite, obj->fire->pos);
        sfSprite_setTextureRect(obj->fire->sprite, obj->fire->rect);
        sfClock_restart(obj->fire->clock);
    }
    analyse_collision(obj);
    if (max_range(obj) != 0)
        obj->player->is_fire = false;
}
