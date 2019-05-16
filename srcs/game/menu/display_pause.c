/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display_pause
*/

#include "proto.h"

int display_pause(game_obj *obj)
{
    int error = 0;

    if (obj->use->str_pause == 1) {
        obj->use->pause = 1;
        error = pause_menu(obj);
        if (error == 1) {
            obj->use->str_pause = 0;
            return 1;
        }else if (error == 84) {
            obj->use->str_pause = 0;
            return 84;
        }
        obj->use->str_pause = 0;
    }
    return 0;
}