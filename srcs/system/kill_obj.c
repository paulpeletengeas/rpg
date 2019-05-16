/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** clean all sprite, texture...
*/

#include "proto.h"

void kill_sound(sound_t *sound)
{
    sfMusic_setLoop(sound->music, sfFalse);
    sfMusic_stop(sound->music);
    sfMusic_stop(sound->click);
    sfMusic_destroy(sound->music);
    sfMusic_destroy(sound->click);
}

void kill_sys(sys_t *sys)
{
    sfClock_destroy(sys->clock);
    sfRenderWindow_destroy(sys->win);
}

void kill_game_obj(game_obj *obj)
{
    kill_sound(obj->sound);
    kill_sys(obj->sys);
}
