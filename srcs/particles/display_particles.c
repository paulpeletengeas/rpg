/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_particles
*/

#include "proto.h"

void    set_pos(part_t *parts, game_obj *obj)
{
    int i = 0;
    int size = rand() % 5 + 8;
    sfVector2f pos = sfSprite_getPosition(obj->player->sprite);

    while (i < (parts->nb * 4)) {
        parts->array[i].position.x = rand() % 64 + (pos.x - 32);
        parts->array[i].position.y = rand() % 64 + (pos.y - 32);
        parts->array[i + 1].position.x = parts->array[i].position.x + size;
        parts->array[i + 1].position.y = parts->array[i].position.y;
        parts->array[i + 2].position.x = parts->array[i].position.x + size;
        parts->array[i + 2].position.y = parts->array[i].position.y + size;
        parts->array[i + 3].position.x = parts->array[i].position.x;
        parts->array[i + 3].position.y = parts->array[i].position.y + size;
        i += 4;
    }
}

void    display_particles(game_obj *obj)
{
    float s = 1000000;
    int i = 0;
    int j = 0;

    if (sfClock_getElapsedTime(obj->parts->clock).microseconds / s >= 0.01) {
        sfVertexArray_clear(obj->parts->vertex);
        i = 0;
        set_pos(obj->parts, obj);
        while (i < obj->parts->nb * 4) {
            j = 0;
            while (j < 4) {
                sfVertexArray_append(obj->parts->vertex,
                                     obj->parts->array[i + j]);
                j++;
            }
            i += 4;
        }
        sfClock_restart(obj->parts->clock);
    }
    sfRenderWindow_drawVertexArray(obj->sys->win, obj->parts->vertex, NULL);
}
