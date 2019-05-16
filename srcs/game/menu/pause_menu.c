/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** pause menu
*/

#include "proto.h"

static int check_assets(pause_t *pause)
{
    pause->press_pos.x = 470;
    pause->press_pos.y = 600;
    pause->menu_pos.x = 750;
    pause->menu_pos.y = 400;
    pause->play_pos.x = 200;
    pause->play_pos.y = 500;
    pause->close_pos.x = 1500;
    pause->close_pos.y = 500;
    if (!pause->bg_text || !pause->font || !pause->play_text
        || !pause->close_text)
        return 84;
    return 0;
}

static int init_pause(pause_t *pause)
{
    pause->bg_text = sfTexture_createFromFile("assets/menu/bgstrtmenu.jpg",
                     NULL);
    pause->bg = sfSprite_create();
    pause->font = sfFont_createFromFile("assets/fonts/mine.ttf");
    pause->menu_txt = sfText_create();
    pause->press_txt = sfText_create();
    pause->menu = "Game is Pause";
    pause->press = "Press B to unpause the game";
    pause->play_text = sfTexture_createFromFile("assets/menu/Mainmenu.png",
                        NULL);
    pause->play = sfSprite_create();
    pause->close_text = sfTexture_createFromFile("assets/menu/quit.png",
                        NULL);
    pause->close = sfSprite_create();
    if (check_assets(pause)) return 84;
    return 0;
}

static int init_setting(pause_t *pause)
{

    pause->setting_text = sfTexture_createFromFile("assets/menu/settings.png",
                          NULL);
    pause->setting = sfSprite_create();
    pause->setting_pos.x = 800;
    pause->setting_pos.y = 700;
    if (!pause->setting_text)
        return 84;
    return 0;
}

static void set_pause(pause_t *pause)
{
    sfColor brown = sfColor_fromRGB(160, 82, 45);

    sfSprite_setTexture(pause->play, pause->play_text, sfTrue);
    sfSprite_setTexture(pause->close, pause->close_text, sfTrue);
    sfSprite_setTexture(pause->setting, pause->setting_text, sfTrue);
    sfSprite_setPosition(pause->setting, pause->setting_pos);
    sfSprite_setTexture(pause->bg, pause->bg_text, sfTrue);
    sfSprite_setPosition(pause->play, pause->play_pos);
    sfSprite_setPosition(pause->close, pause->close_pos);
    sfText_setFont(pause->menu_txt, pause->font);
    sfText_setFont(pause->press_txt, pause->font);
    sfText_setString(pause->menu_txt, pause->menu);
    sfText_setString(pause->press_txt, pause->press);
    sfText_setPosition(pause->menu_txt, pause->menu_pos);
    sfText_setPosition(pause->press_txt, pause->press_pos);
    sfText_setCharacterSize(pause->menu_txt, 50);
    sfText_setCharacterSize(pause->press_txt, 50);
    sfText_setColor(pause->menu_txt, brown);
    sfText_setColor(pause->press_txt, brown);
}

int pause_menu(game_obj *obj)
{
    sfEvent event;
    pause_t pause;

    if (init_pause(&pause)) return 84;
    if (init_setting(&pause))
        return 84;
    set_pause(&pause);
    while (obj->use->pause == 1) {
        sfRenderWindow_drawSprite(obj->sys->win, pause.bg, NULL);
        sfRenderWindow_drawText(obj->sys->win, pause.menu_txt, NULL);
        sfRenderWindow_drawText(obj->sys->win, pause.press_txt, NULL);
        sfRenderWindow_drawSprite(obj->sys->win, pause.play, NULL);
        sfRenderWindow_drawSprite(obj->sys->win, pause.close, NULL);
        sfRenderWindow_drawSprite(obj->sys->win, pause.setting, NULL);
        sfRenderWindow_display(obj->sys->win);
        while (sfRenderWindow_pollEvent(obj->sys->win, &event)) {
            if (pause_menuevt(obj, event))
                return 1;
        }
    }
    return 0;
}