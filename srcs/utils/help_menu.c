/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** help menu
*/

#include "proto.h"

int init_howtplay(help_t *help)
{
    sfVector2f pos = {500, 200};

    help->howtplay = sfTexture_createFromFile("assets/menu/pading.png",
                     NULL);
    help->htp = sfSprite_create();
    help->text = sfText_create();
    help->font = sfFont_createFromFile("assets/fonts/mine.ttf");
    help->keybind = "KeyBinding";
    help->close = sfText_create();
    help->shut = "Press Space to close";
    sfSprite_setTexture(help->htp, help->howtplay, sfTrue);
    sfSprite_setPosition(help->htp, pos);
    if (!help->howtplay || !help->font)
        return 1;
    return 0;
}

void init_text(help_t *help)
{
    sfVector2f pos1 = {750, 50};
    sfVector2f pos2 = {715, 100};

    sfText_setFont(help->text, help->font);
    sfText_setFont(help->close, help->font);
    sfText_setPosition(help->text, pos1);
    sfText_setPosition(help->close, pos2);
    sfText_setCharacterSize(help->text, 50);
    sfText_setCharacterSize(help->close, 30);
    sfText_setColor(help->text, sfBlack);
    sfText_setColor(help->close, sfBlack);
    sfText_setString(help->text, help->keybind);
    sfText_setString(help->close, help->shut);
}

void draw_help(game_obj *obj, help_t *help)
{
        sfRenderWindow_clear(obj->sys->win, sfWhite);
        sfRenderWindow_drawSprite(obj->sys->win, help->htp, NULL);
        sfRenderWindow_drawText(obj->sys->win, help->text, NULL);
        sfRenderWindow_drawText(obj->sys->win, help->close, NULL);
        sfRenderWindow_display(obj->sys->win);
}

int help_menu(game_obj *obj)
{
    sfEvent event;
    int loop = 1;
    help_t help;

    if (init_howtplay(&help))
        return 84;
    init_text(&help);
    while (loop == 1) {
        draw_help(obj, &help);
        while (sfRenderWindow_pollEvent(obj->sys->win, &event)) {
            if (sfKeyboard_isKeyPressed(sfKeySpace))
                loop = 0;
        }
    }
    return 0;
}