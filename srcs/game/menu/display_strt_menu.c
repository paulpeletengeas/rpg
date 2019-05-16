/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display_strtmenu
*/

#include "proto.h"

int display_strtmenu(game_obj *obj)
{
    int error = 0;

    if (obj->use->begin == 1) {
        error = strt_menu(obj);
        if (error == 1) {
            obj->use->begin = 0;
            return 1;
        } else if (error == 84) {
            obj->use->begin = 0;
            return 84;
        }
        obj->use->begin = 0;
    }
    return 0;
}