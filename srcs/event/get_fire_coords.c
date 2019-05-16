/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_fire_coords
*/

#include "proto.h"

void    get_fire_coords(game_obj *obj)
{
    sfSprite_setRotation(obj->fire->sprite,
                         sfSprite_getRotation(obj->player->sprite) + 180);
    obj->fire->pos = sfSprite_getPosition(obj->player->sprite);
    obj->fire->start = sfSprite_getPosition(obj->player->sprite);
    obj->fire->end = get_end_pos(obj);
    obj->player->is_fire = true;
}