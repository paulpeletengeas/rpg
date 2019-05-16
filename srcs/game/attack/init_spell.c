/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_spell
*/

#include "proto.h"

magic_t    *set_spell_rect(magic_t *spell)
{
    spell->rect.height = 72;
    spell->rect.width = 72;
    spell->rect.left = 0;
    spell->rect.top = 0;
    return (spell);
}

int    init_spell(game_obj *obj)
{
    obj->spell = NULL;
    sfVector2f scale = {2, 2};
    sfTexture *texture = sfTexture_createFromFile("./assets/fire/magic.png",
                                                    NULL);
    sfVector2f origin = {36, 36};

    if (!(obj->spell = malloc(sizeof(magic_t))))
        return (1);
    obj->spell->sprite = sfSprite_create();
    obj->spell = set_spell_rect(obj->spell);
    obj->spell->clock = sfClock_create();
    sfSprite_setTexture(obj->spell->sprite, texture, sfTrue);
    sfSprite_setOrigin(obj->spell->sprite, origin);
    sfSprite_setScale(obj->spell->sprite, scale);
    sfSprite_setTextureRect(obj->spell->sprite, obj->spell->rect);
    sfSprite_setPosition(obj->spell->sprite,
                        sfSprite_getPosition(obj->player->sprite));
    obj->spell->fire = false;
    obj->spell->offset = 72;
    obj->spell->delay = 0;
    return (0);
}