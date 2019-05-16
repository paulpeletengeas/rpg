/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** player struct
*/

#ifndef PLAYER_H_
#define PLAYER_H_

typedef struct mana_s {
    float qt_mana;
    sfRectangleShape *disp_mana;
} mana_t;

typedef struct player
{
    sfTexture *texture;
    sfSprite *sprite;
    char *pseudo;
    bool is_fire;
    float life;
    int gold;
    int quest_ok;
    struct mana_s *mana;
    struct item_s *items;
} player_t;

#endif /* PLAYER_H_ */
