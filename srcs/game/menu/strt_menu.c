/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** strt_menu
*/

#include "proto.h"

int check_menu(menu_t *menu)
{
    if (!menu->font || !menu->close_text
        || !menu->play_text)
        return 1;
    return 0;
}

int init_menu(menu_t *menu)
{
    menu->font = sfFont_createFromFile("assets/fonts/mine.ttf");
    menu->menu_txt = sfText_create();
    menu->press_txt = sfText_create();
    menu->menu = "Welcome to MyRPG";
    menu->press = "Press H in game for help";
    menu->play_text = sfTexture_createFromFile("assets/menu/start.png", NULL);
    menu->play = sfSprite_create();
    menu->close_text = sfTexture_createFromFile("assets/menu/quit.png", NULL);
    menu->close = sfSprite_create();
    menu->press_pos.x = 600;
    menu->press_pos.y = 600;
    menu->menu_pos.x = 700;
    menu->menu_pos.y = 400;
    menu->play_pos.x = 200;
    menu->play_pos.y = 500;
    menu->close_pos.x = 1500;
    menu->close_pos.y = 500;
    if (check_menu(menu)) return 1;
    return 0;
}

void set_menu(menu_t *menu)
{
    sfColor brown = sfColor_fromRGB(160, 82, 45);

    sfSprite_setTexture(menu->play, menu->play_text, sfTrue);
    sfSprite_setTexture(menu->close, menu->close_text, sfTrue);
    sfSprite_setPosition(menu->play, menu->play_pos);
    sfSprite_setPosition(menu->close, menu->close_pos);
    sfText_setFont(menu->menu_txt, menu->font);
    sfText_setFont(menu->press_txt, menu->font);
    sfText_setString(menu->menu_txt, menu->menu);
    sfText_setString(menu->press_txt, menu->press);
    sfText_setPosition(menu->menu_txt, menu->menu_pos);
    sfText_setPosition(menu->press_txt, menu->press_pos);
    sfText_setCharacterSize(menu->menu_txt, 50);
    sfText_setCharacterSize(menu->press_txt, 50);
    sfText_setColor(menu->menu_txt, brown);
    sfText_setColor(menu->press_txt, brown);
}

int strt_menuevt(game_obj *obj, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(obj->sys->win).x >= 200
        && sfMouse_getPositionRenderWindow(obj->sys->win).x <= 500
        && sfMouse_getPositionRenderWindow(obj->sys->win).y >= 500
        && sfMouse_getPositionRenderWindow(obj->sys->win).y <= 600) {
        obj->use->strt_menu = 0;
        obj->use->begin = 0;
    }
    if (event.type == sfEvtMouseButtonPressed
        && sfMouse_getPositionRenderWindow(obj->sys->win).x >= 1500
        && sfMouse_getPositionRenderWindow(obj->sys->win).x <= 1800
        && sfMouse_getPositionRenderWindow(obj->sys->win).y >= 500
        && sfMouse_getPositionRenderWindow(obj->sys->win).y <= 600) {
        obj->use->strt_menu = 0;
        kill_game_obj(obj);
        return 1;
    }
    return 0;
}

int strt_menu(game_obj *obj)
{
    sfEvent event;
    menu_t menu;

    if (init_menu(&menu))
        return 84;
    set_menu(&menu);
    while (obj->use->strt_menu == 1) {
        display_parallax(obj);
        sfRenderWindow_drawText(obj->sys->win, menu.menu_txt, NULL);
        sfRenderWindow_drawText(obj->sys->win, menu.press_txt, NULL);
        sfRenderWindow_drawSprite(obj->sys->win, menu.play , NULL);
        sfRenderWindow_drawSprite(obj->sys->win, menu.close , NULL);
        sfRenderWindow_display(obj->sys->win);
        while (sfRenderWindow_pollEvent(obj->sys->win, &event)) {
            if (strt_menuevt(obj, event))
                return 1;
        }
    }
    return 0;
}
