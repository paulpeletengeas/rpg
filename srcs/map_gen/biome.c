/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** determine which tile to be display next in function of the biome
*/

#include <stdlib.h>

int *randomize_biome(int biome)
{
    int *biome_tile = malloc(sizeof(int) * 337);
    int index = 0;
    int ret = 0;

    if (!biome_tile)
        return (NULL);
    while (index <= 336)
        biome_tile[index++] = ((ret = (rand() % 8) + 1) > 4) ? biome : ret;
    biome_tile[index] = -1;
    return (biome_tile);
}
