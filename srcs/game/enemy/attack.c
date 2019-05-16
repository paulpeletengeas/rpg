/*
** EPITECH PROJECT, 2019
** rpg_attack
** File description:
** attack
*/

#include "proto.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

int    attack(int nb, sfRenderWindow *win)
{
    enemy_t **enemy = init_enemy(nb);

    if (!enemy)
        return (84);
    while (sfRenderWindow_isOpen(win)) {
        enemy_move(enemy, win);
    }
    return (0);
}
