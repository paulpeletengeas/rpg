/*
** EPITECH PROJECT, 2019
** rpg_attack
** File description:
** vector_dist
*/

#include "proto.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

float    vector_dist(sfVector2f dir)
{
    float x = dir.x;
    float y = dir.y;
    float res = sqrt(x * x + y * y);

    return (res);
}