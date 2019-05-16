/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** menu.h
*/

#ifndef MENU_H_
    #define MENU_H_

typedef struct utility {
    int strt_menu;
    int pause;
    int begin;
    int str_pause;
    int help;
}use_t;

typedef struct menu {
    sfTexture *bg_text;
    sfSprite *bg;
    sfFont *font;
    sfText *menu_txt;
    sfText *press_txt;
    char *menu;
    char *press;
    sfVector2f press_pos;
    sfVector2f menu_pos;
    sfTexture *play_text;
    sfSprite *play;
    sfVector2f play_pos;
    sfTexture *close_text;
    sfSprite *close;
    sfVector2f close_pos;
}menu_t;

typedef struct pause {
    sfTexture *bg_text;
    sfSprite *bg;
    sfFont *font;
    sfText *menu_txt;
    sfText *press_txt;
    char *menu;
    char *press;
    sfVector2f press_pos;
    sfVector2f menu_pos;
    sfTexture *play_text;
    sfSprite *play;
    sfVector2f play_pos;
    sfTexture *close_text;
    sfSprite *close;
    sfVector2f close_pos;
    sfTexture *setting_text;
    sfSprite *setting;
    sfVector2f setting_pos;
}pause_t;

typedef struct settings {
    sfTexture *plus_text2;
    sfSprite *plus2;
    sfTexture *moins_text2;
    sfSprite *moins2;
    sfTexture *plus_text;
    sfSprite *plus;
    sfTexture *moins_text;
    sfSprite *moins;
    sfTexture *close_text;
    sfSprite *close;
    sfVector2f close_pos;
    sfVector2f minus_pos1;
    sfVector2f minus_pos2;
    sfVector2f plus_pos1;
    sfVector2f plus_pos2;
    char *music;
    char *sound;
    sfVector2f music_pos;
    sfVector2f sound_pos;
    sfFont *font;
    sfText *music_txt;
    sfText *sound_txt;
    float vol_mus;
    float vol_sou;
    char *volM;
    char *volS;
    sfVector2f volmus_pos;
    sfVector2f volso_pos;
    sfText *volmusic;
    sfText *volsound;
}set_t;

typedef struct help {
    sfSprite *htp;
    sfText *text;
    sfFont *font;
    sfText *close;
    char *keybind;
    char *shut;
    sfTexture *howtplay;
}help_t;
#endif /* !MENU_H_ */
