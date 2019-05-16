/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** main function
*/

#include <stdlib.h>
#include "proto.h"

int game_loop(game_obj *obj)
{
    while (sfRenderWindow_isOpen(obj->sys->win)) {
        check_enemy_life(obj);
        if (analyse_event(obj) || display_strtmenu(obj) || display_pause(obj))
            return (0);
        enemy_move(obj, obj->enemy, sfSprite_getPosition(obj->player->sprite));
        display_map(obj);
        display_fire(obj);
        get_item(obj);
        display_particles(obj);
        if (display_help(obj))
            return 0;
        display_sprites(obj->enemy, obj->sys->win);
        display_spell(obj);
        display_player(obj);
        show_pnj(obj);
        display_hud(obj);
        sfRenderWindow_display(obj->sys->win);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    game_obj *obj = NULL;

    (void)ac;
    (void)av;
    if (!env || !env[0] || !(obj = create_game_object()) ||
        game_loop(obj))
        return (84);
    return (0);
}
