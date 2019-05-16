/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** creation file
*/

#include "proto.h"

game_obj *create_pnj_struct(game_obj *obj)
{
    return ((!(obj->pnj = malloc(sizeof(pnj_t))))? NULL : obj);
}

sfSprite *create_sprite(char *asset_path)
{
    sfTexture *texture;
    sfSprite *sprite;

    if (!asset_path)
        return NULL;
    if (!(texture = sfTexture_createFromFile(asset_path, NULL)))
        return NULL;
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
