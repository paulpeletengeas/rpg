/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** move the player with z, q, s, d
*/

#include "proto.h"

void rotate(game_obj *obj, sfVector2f pos, sfVector2f old)
{
    float angle = -90;

    if (pos.y < old.y && pos.x < old.x)
        angle += 45;
    else if (pos.y < old.y && pos.x > old.x)
        angle -= 45;
    if (pos.y < old.y)
        angle += 0;
    if (pos.y > old.y && pos.x < old.x)
        angle -= 225;
    else if (pos.y > old.y && pos.x > old.x)
        angle += 225;
    if (pos.y > old.y)
        angle -= 180;
    if (pos.x > old.x)
        angle += 90;
    if (pos.x < old.x)
        angle += 270;
    sfSprite_setRotation(obj->player->sprite, angle);
}

void move_player(game_obj *obj)
{
    sfVector2f old = sfSprite_getPosition(obj->player->sprite);
    sfVector2f pos = old;

    if ((obj->player->quest_ok == 1) &&
        (old.y <= 30 || old.y >= 995 || old.x >= 1890 || old.x <= 26)) {
        reload_map(obj);
    } else {
        if (old.y > 22 && sfKeyboard_isKeyPressed(sfKeyZ))
            pos.y -= 5;
        if (old.y < 1005 && sfKeyboard_isKeyPressed(sfKeyS))
            pos.y += 5;
        if (old.x < 1900 && sfKeyboard_isKeyPressed(sfKeyD))
            pos.x += 5;
        if (old.x > 16 && sfKeyboard_isKeyPressed(sfKeyQ))
            pos.x -= 5;
        if (pos.x != old.x || pos.y != old.y)
            rotate(obj, pos, old);
        sfSprite_setPosition(obj->player->sprite, pos);
    }
}
