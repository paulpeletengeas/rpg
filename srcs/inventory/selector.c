/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** inventory selector
*/

#include "proto.h"

void check_selector(game_obj *obj)
{
    sfVector2f pos = sfRectangleShape_getPosition(obj->hud->selector->shape);

    if (sfClock_getElapsedTime(obj->hud->selector->bound).microseconds
        / 1000000.0 >= 0.1) {
        if (sfKeyboard_isKeyPressed(sfKeyRight) && pos.x < 640 + (72 * 8)) {
            pos.x += 72;
            sfRectangleShape_setPosition(obj->hud->selector->shape, pos);
        } else if (sfKeyboard_isKeyPressed(sfKeyLeft) && pos.x > 640) {
            pos.x -= 72;
            sfRectangleShape_setPosition(obj->hud->selector->shape, pos);
        }
        sfClock_restart(obj->hud->selector->bound);
    }
}

int draw_selector(game_obj *obj)
{
    sfRenderWindow_drawRectangleShape(obj->sys->win, obj->hud->selector->shape,
                                      NULL);
    return (0);
}
