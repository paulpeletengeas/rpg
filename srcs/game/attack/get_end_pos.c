/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_end_pos
*/

#include "proto.h"

sfVector2f    get_end_pos(game_obj *obj)
{
    sfVector2f end_pos;
    float stock_angle = sfSprite_getRotation(obj->player->sprite) + 180;

    stock_angle *= (3.1415 / 180);
    end_pos.x = obj->fire->range * cos(stock_angle) + obj->fire->start.x;
    end_pos.y = obj->fire->range * sin(stock_angle) + obj->fire->start.y;
    return (end_pos);
}