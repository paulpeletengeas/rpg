/*
** EPITECH PROJECT, 2019
** rpg_attack
** File description:
** normalize_vector
*/

#include "proto.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

sfVector2f    normalize_vector(sfVector2f dir)
{
    float len = vector_dist(dir);

    dir.x = dir.x / len;
    dir.y = dir.y / len;
    return (dir);
}