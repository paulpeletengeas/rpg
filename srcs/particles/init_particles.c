/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_particles
*/

#include "proto.h"
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>

void    make_rand_color(part_t *parts, int i)
{
    int j = 0;
    sfColor color;

    color.r = 255;
    color.g = 150;
    color.b = 100;
    color.a = 125;
    while (j < 4) {
        parts->array[i + j].color = color;
        j++;
    }
}

part_t    *set_part_pos(part_t *parts, game_obj *obj)
{
    int i = 0;
    int size = rand() % 5 + 2;
    sfVector2f pos = sfSprite_getPosition(obj->player->sprite);

    while (i < (parts->nb * 4)) {
        make_rand_color(parts, i);
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
    return (parts);
}

part_t    *init_particles(game_obj *obj, int nb)
{
    part_t *parts = NULL;

    if (!(parts = malloc(sizeof(part_t))))
        return (NULL);
    if (!(parts->array = malloc(sizeof(sfVertex) * (nb * 4))))
        return (NULL);
    parts->nb = nb;
    parts->clock = sfClock_create();
    parts->vertex = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(parts->vertex, sfQuads);
    parts = set_part_pos(parts, obj);
    return (parts);
}