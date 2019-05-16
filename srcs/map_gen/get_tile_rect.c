/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** return rect un function of tile number
*/

#include "proto.h"

sfIntRect get_tile_rect(int tile_type)
{
    sfIntRect dest = {0, 0, 80, 80};

    if (tile_type == 1) {
        return (dest);
    }
    if (tile_type == 2) {
        dest.top = 80;
        return (dest);
    }
    if (tile_type == 3) {
        dest.left = 80;
        return (dest);
    }
    if (tile_type == 4) {
        dest.left = 80;
        dest.top = 80;
        return (dest);
    }
    return (dest);
}
