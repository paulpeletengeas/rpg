/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check keyboard event
*/

#include "proto.h"

void check_attack(game_obj *obj)
{
    if (sfKeyboard_isKeyPressed(sfKeyP) && obj->player->is_fire == false &&
        obj->player->mana->qt_mana >= 50) {
        obj->player->mana->qt_mana -= 50;
        get_fire_coords(obj);
    }
    if (sfKeyboard_isKeyPressed(sfKeyO) && obj->spell->fire == false &&
        obj->player->mana->qt_mana >= 70) {
        obj->player->mana->qt_mana -= 70;
        obj->spell->fire = true;
    }
}

int check_keyboard(game_obj *obj)
{
    check_selector(obj);
    if (sfKeyboard_isKeyPressed(sfKeyC) &&
        sfKeyboard_isKeyPressed(sfKeyLControl)) {
        kill_game_obj(obj);
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyM))
        toggle_vol(obj, obj->sound->music);
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        obj->use->str_pause = 1;
        obj->use->pause = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyH))
        obj->use->help = 1;
    check_attack(obj);
    return (0);
}
