/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check assets
*/

#include "proto.h"

int check_settings(set_t *set)
{
    if (!set->plus_text || !set->moins_text || !set->moins_text2
        || !set->plus_text2 || !set->close_text || !set->font)
        return 1;
    return 0;
}