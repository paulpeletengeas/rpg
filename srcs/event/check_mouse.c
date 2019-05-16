/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check mouse event
*/

#include "proto.h"

void check_mouse(game_obj *obj, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && !obj->sys->view)
        sfMusic_play(obj->sound->click);
}
