/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** player in range
*/

#include "proto.h"

int player_inrange(game_obj *obj)
{
    size_t x = sfSprite_getPosition(obj->player->sprite).x;
    size_t y = sfSprite_getPosition(obj->player->sprite).y;

    if (x < 300 && x > 0 && y < 1000 && y < 800)
        return 0;
    return 1;
}