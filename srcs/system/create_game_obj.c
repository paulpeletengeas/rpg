/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create game object
*/

#include <time.h>
#include <stdlib.h>
#include "proto.h"

game_obj *create_game_object(void)
{
    game_obj *obj = (game_obj *)malloc(sizeof(game_obj));

    if (!obj || !(obj->sys = create_sys()) ||
        !(obj->sound = create_sound()) ||
        !(obj->map = create_map()) ||
        !(obj->hud = create_hud()) ||
        !(obj->use = init_utility()) ||
        !create_pnj_struct(obj) ||
        !(obj->enemy = init_enemy((rand() % 10) + 5)) ||
        init_player(obj) || !(obj->parts = init_particles(obj, 16)) ||
        init_spell(obj) ||
        !(obj->enemy = init_enemy((rand() % 15) + 10)) ||
        !(obj->bg = create_parallax()) ||
        init_player(obj) ||
        !(obj->parts = init_particles(obj, 16)) ||
        init_spell(obj))
        return (NULL);
    return (obj);
}
