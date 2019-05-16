/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** display_fire
*/

#include "proto.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

void    display_fire(game_obj *obj)
{
    if (obj->player->is_fire == true) {
        launch_fire(obj);
        sfRenderWindow_drawSprite(obj->sys->win,
                                  obj->fire->sprite,
                                  NULL);
    }
}
