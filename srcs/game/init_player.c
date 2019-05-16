/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init player
*/

#include <stdlib.h>
#include "proto.h"

static mana_t *create_mana(void)
{
    mana_t *dest = malloc(sizeof(mana_t));
    sfVector2f life_pos = {1325, 895};
    sfVector2f size = {7.5, 75};

    if (!dest)
        return (NULL);
    dest->qt_mana = 100.0;
    dest->disp_mana = sfRectangleShape_create();
    sfRectangleShape_setSize(dest->disp_mana, size);
    sfRectangleShape_setFillColor(dest->disp_mana, sfBlue);
    sfRectangleShape_setPosition(dest->disp_mana, life_pos);
    return (dest);
}

static sfSprite *create_player(sfTexture *texture)
{
    sfSprite *player = sfSprite_create();
    sfIntRect rect = {0, 0, 32, 44};
    sfVector2f pos = {910, 700};
    sfVector2f scale = {1.3, 1.3};
    sfVector2f origin = {16, 22};

    sfSprite_setTexture(player, texture, sfTrue);
    sfSprite_setTextureRect(player, rect);
    sfSprite_setPosition(player, pos);
    sfSprite_setOrigin(player, origin);
    sfSprite_scale(player, scale);
    sfSprite_rotate(player, 270);
    return (player);
}

int init_player(game_obj *obj)
{
    if (!(obj->player = malloc(sizeof(player_t))) ||
        !(obj->player->texture = sfTexture_createFromFile(
              "./assets/player/player.png", NULL)))
        return (84);
    obj->player->sprite = create_player(obj->player->texture);
    obj->player->pseudo = NULL;
    obj->player->items = NULL;
    obj->player->mana = create_mana();
    obj->player->life = 10.0;
    obj->player->gold = 10;
    obj->player->quest_ok = 1;
    obj->player->items = NULL;
    obj->player->is_fire = false;
    obj->fire = init_attack();
    return (0);
}

void reset_player_pos(game_obj *obj)
{
    sfVector2f init_pos = {910, 700};

    sfSprite_setPosition(obj->player->sprite, init_pos);
    sfSprite_rotate(obj->player->sprite, 270);
}
