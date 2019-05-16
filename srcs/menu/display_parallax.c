/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display background
*/

#include "proto.h"

void display_parallax(game_obj *obj)
{
    int x = 0;
    int index = -1;

    if (sfClock_getElapsedTime(obj->sys->clock).microseconds / 1000000.0 >
        0.01) {
        while (++index < 4) {
            obj->bg[index]->rect.left -= x -= 1;
            sfSprite_setTextureRect(obj->bg[index]->sprite,
                                    obj->bg[index]->rect);
            sfRenderWindow_drawSprite(obj->sys->win,
                                      obj->bg[index]->sprite, NULL);
        }
        sfClock_restart(obj->sys->clock);
    }
}
