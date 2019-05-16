/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** talk to pnj
*/

#include "proto.h"

void init_texts(sfText **start, sfText **ender,
                sfText **kills, sfFont *font)
{
    sfVector2f pos_strt = {100, 100};
    sfVector2f pos_end = {100, 130};
    sfVector2f pos_kills = {100, 115};

    sfText_setFont(*start, font);
    sfText_setFont(*ender, font);
    sfText_setFont(*kills, font);
    sfText_setColor(*start, sfBlack);
    sfText_setColor(*ender, sfBlack);
    sfText_setColor(*kills, sfBlack);
    sfText_setPosition(*start, pos_strt);
    sfText_setPosition(*ender, pos_end);
    sfText_setPosition(*kills, pos_kills);
    sfText_setCharacterSize(*start, 100);
    sfText_setCharacterSize(*ender, 100);
    sfText_setCharacterSize(*kills, 100);
}

void draw_text(game_obj * obj, sfText *start, sfText *ender, sfText *kills)
{
    sfRenderWindow_drawText(obj->sys->win, start, NULL);
    sfRenderWindow_drawText(obj->sys->win, ender, NULL);
    sfRenderWindow_drawText(obj->sys->win, kills, NULL);
    sfRenderWindow_display(obj->sys->win);
}
