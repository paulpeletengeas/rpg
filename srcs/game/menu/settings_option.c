/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** settings option
*/

#include "proto.h"

int init_setting(set_t *set)
{
    set->volmusic = sfText_create();
    set->volsound = sfText_create();
    set->plus_text2 = sfTexture_createFromFile("assets/menu/plus.png", NULL);
    set->plus2 = sfSprite_create();
    set->moins_text2 = sfTexture_createFromFile("assets/menu/moins.png", NULL);
    set->moins2 = sfSprite_create();
    set->plus_text = sfTexture_createFromFile("assets/menu/plus.png", NULL);
    set->plus = sfSprite_create();
    set->moins_text = sfTexture_createFromFile("assets/menu/moins.png", NULL);
    set->moins = sfSprite_create();
    set->close_text = sfTexture_createFromFile("assets/menu/quit.png", NULL);
    set->close = sfSprite_create();
    set->music = "Music";
    set->sound = "Sound";
    set->music_txt = sfText_create();
    set->sound_txt = sfText_create();
    set->font = sfFont_createFromFile("assets/fonts/mine.ttf");
    if (check_settings(set))
        return 1;
    return 0;
}

void set_settings(set_t *set)
{
    sfSprite_setTexture(set->close, set->close_text, sfTrue);
    sfSprite_setPosition(set->close, set->close_pos);
    sfSprite_setTexture(set->plus2, set->plus_text2, sfTrue);
    sfSprite_setPosition(set->plus2, set->plus_pos2);
    sfSprite_setTexture(set->moins, set->moins_text, sfTrue);
    sfSprite_setPosition(set->moins, set->minus_pos1);
    sfSprite_setTexture(set->moins2, set->moins_text2, sfTrue);
    sfSprite_setPosition(set->moins2, set->minus_pos2);
    sfSprite_setTexture(set->plus, set->plus_text, sfTrue);
    sfSprite_setPosition(set->plus, set->plus_pos1);
    sfText_setFont(set->music_txt, set->font);
    sfText_setFont(set->sound_txt, set->font);
    sfText_setString(set->sound_txt, set->sound);
    sfText_setString(set->music_txt, set->music);
    sfText_setPosition(set->sound_txt, set->sound_pos);
    sfText_setPosition(set->music_txt, set->music_pos);
    sfText_setCharacterSize(set->sound_txt, 50);
    sfText_setCharacterSize(set->music_txt, 50);
}

void init_vectors(set_t *set)
{
    set->sound_pos.x = 850;
    set->sound_pos.y = 500;
    set->close_pos.x = 820;
    set->close_pos.y = 800;
    set->plus_pos1.x = 1200;
    set->plus_pos1.y = 350;
    set->minus_pos1.x = 650;
    set->minus_pos1.y = 350;
    set->minus_pos2.x = 650;
    set->minus_pos2.y = 650;
    set->plus_pos2.x = 1200;
    set->plus_pos2.y = 650;
    set->music_pos.x = 850;
    set->music_pos.y = 200;
    set->volmus_pos.x = 900;
    set->volmus_pos.y = 350;
    set->volso_pos.x = 900;
    set->volso_pos.y = 650;
}

void init_volume(set_t *set)
{
    sfText_setFont(set->volmusic, set->font);
    sfText_setFont(set->volsound, set->font);
    sfText_setString(set->volmusic, set->volM);
    sfText_setString(set->volsound, set->volS);
    sfText_setPosition(set->volmusic, set->volmus_pos);
    sfText_setPosition(set->volsound, set->volso_pos);
    sfText_setCharacterSize(set->volmusic, 50);
    sfText_setCharacterSize(set->volsound, 50);
}

int settings_option(game_obj *obj, sfEvent event)
{
    set_t set;
    int setting = 1;

    if (init_setting(&set))
        return 84;
    init_vectors(&set);
    set_settings(&set);
    while (setting == 1) {
        set.volM = int_to_str(sfMusic_getVolume(obj->sound->music));
        set.volS = int_to_str(sfMusic_getVolume(obj->sound->click));
        init_volume(&set);
        sfRenderWindow_clear(obj->sys->win, sfBlack);
        draw_settingopt(obj, set);
        sfRenderWindow_display(obj->sys->win);
        while (sfRenderWindow_pollEvent(obj->sys->win, &event)) {
            setting_evt(obj, event, &setting, &set);
        }
    }
    return 0;
}
