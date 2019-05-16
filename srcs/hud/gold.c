/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display gold
*/

#include <stdlib.h>
#include "proto.h"

void display_gold(game_obj *obj)
{
    sfIntRect rect = sfSprite_getTextureRect(obj->hud->gold->sprite);
    char *ret = int_to_str(obj->player->gold);

    sfText_setString(obj->hud->gold->text, ret);
    free(ret);
    if (sfClock_getElapsedTime(obj->hud->gold->clock).microseconds
        / 1000000.0 >= 0.05) {
        rect.left += 56;
        if (rect.left >= 560)
            rect.left = 0;
        sfSprite_setTextureRect(obj->hud->gold->sprite, rect);
        sfClock_restart(obj->hud->gold->clock);
    }
    sfRenderWindow_drawText(obj->sys->win, obj->hud->gold->text, NULL);
    sfRenderWindow_drawSprite(obj->sys->win, obj->hud->gold->sprite, NULL);
}

sfText *create_counter(sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos = {1165, 805};

    sfText_setString(text, "0");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
    return (text);
}

gold_t *create_gold(void)
{
    sfVector2f pos = {1100, 822};
    sfVector2f scale = {0.7, 0.7};
    sfIntRect rect = {0, 0, 56, 56};
    gold_t *dest = malloc(sizeof(gold_t));

    if (!dest || !(dest->texture =
                   sfTexture_createFromFile("./assets/gui/coin.png", NULL)) ||
        !(dest->font = sfFont_createFromFile("./assets/fonts/DS-DIGI.TTF")))
        return (NULL);
    dest->sprite = sfSprite_create();
    dest->clock = sfClock_create();
    sfSprite_setTexture(dest->sprite, dest->texture, sfTrue);
    sfSprite_setTextureRect(dest->sprite, rect);
    sfSprite_setPosition(dest->sprite, pos);
    sfSprite_scale(dest->sprite, scale);
    dest->text = create_counter(dest->font);;
    return (dest);
}
