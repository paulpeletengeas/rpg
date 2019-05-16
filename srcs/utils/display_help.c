/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display help
*/

#include "proto.h"

int display_help(game_obj *obj)
{
    int error = 0;

    if (obj->use->help) {
        error = help_menu(obj);
        if (error == 1) {
            obj->use->help = 0;
            return 1;
        } else if (error == 84) {
            obj->use->help = 0;
            return 84;
        }
        obj->use->help = 0;
    }
    return 0;
}