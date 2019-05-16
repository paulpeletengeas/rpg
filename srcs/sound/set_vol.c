/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** volume handling
*/

#include "proto.h"

void toggle_vol(game_obj *obj, sfMusic *sound)
{
    if (sfClock_getElapsedTime(obj->sound->bound).microseconds
        / 1000000.0 >= 0.4) {
        if (sfMusic_getVolume(sound) == 100.0) {
            sfMusic_setVolume(sound, 0.0);
        } else {
            sfMusic_setVolume(sound, 100.0);
        }
        sfClock_restart(obj->sound->bound);
    }
}
