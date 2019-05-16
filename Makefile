##
## EPITECH PROJECT, 2019
## rpg
## File description:
## Makefile
##

NAME	= my_rpg

CC	= gcc

RM	= rm -f

MENU	= ./srcs/menu/create_parallax.c		\
	  ./srcs/menu/display_parallax.c

XML	= ./srcs/xml_interpreter/find_by_name.c	\
	  ./srcs/xml_interpreter/get_values.c	\
	  ./srcs/xml_interpreter/skip.c

UTILS	= ./srcs/utils/int_to_str.c 		\
	  ./srcs/utils/display_help.c 		\
	  ./srcs/utils/help_menu.c		\
	  ./srcs/utils/my_strlen.c		\
	  ./srcs/utils/compare.c		\
	  ./srcs/utils/my_atoi.c

EVENT	= ./srcs/event/check_mouse.c		\
	  ./srcs/event/check_keyboard.c		\
	  ./srcs/event/analyse_events.c		\
	  ./srcs/event/player_inrange.c		\
	  ./srcs/event/move_player.c		\
	  ./srcs/event/get_fire_coords.c

GAME	= ./srcs/game/display_player.c		\
	  ./srcs/game/init_player.c		\
	  ./srcs/game/enemy/init_enemy.c	\
	  ./srcs/game/enemy/vector_dist.c	\
	  ./srcs/game/enemy/normalize_vector.c	\
	  ./srcs/game/enemy/display_sprites.c	\
	  ./srcs/game/enemy/enemy_move.c	\
	  ./srcs/game/enemy/check_enemy_life.c	\
	  ./srcs/game/attack/launch_fire.c	\
	  ./srcs/game/attack/init_attack.c	\
	  ./srcs/game/attack/display_fire.c	\
	  ./srcs/game/attack/init_spell.c   \
	  ./srcs/game/attack/display_spell.c   \
	  ./srcs/game/pnj/show_pnj.c		\
	  ./srcs/game/pnj/csfml_generate.c	\
	  ./srcs/game/menu/display_strt_menu.c	\
	  ./srcs/game/menu/init_utility.c	\
	  ./srcs/game/menu/strt_menu.c		\
	  ./srcs/game/menu/check_settings.c		\
	  ./srcs/game/menu/display_pause.c	\
	  ./srcs/game/menu/draw_settingsopt.c		\
	  ./srcs/game/menu/pause_evt.c		\
	  ./srcs/game/menu/setting_evt.c\
	  ./srcs/game/menu/settings_option.c\
	  ./srcs/game/menu/pause_menu.c		\
	  ./srcs/game/attack/get_end_pos.c

SYSTEM	= ./srcs/system/kill_obj.c		\
	  ./srcs/system/create_sound.c		\
	  ./srcs/system/create_sys.c		\
	  ./srcs/system/create_game_obj.c

MAP	= ./srcs/map_gen/create_wildlife.c	\
	  ./srcs/map_gen/create_tile_set.c	\
	  ./srcs/map_gen/get_tile_rect.c	\
	  ./srcs/map_gen/biome.c		\
	  ./srcs/map_gen/list.c

HUD	= ./srcs/hud/life_list.c		\
	  ./srcs/hud/gold.c			\
	  ./srcs/hud/create_gui.c

SOUND	= ./srcs/sound/set_vol.c

PARTICLE =./srcs/particles/init_particles.c	\
	  ./srcs/particles/display_particles.c

INVENT	= ./srcs/inventory/selector.c		\
	  ./srcs/inventory/put_in_inventory.c	\
	  ./srcs/inventory/display_inventory.c	\
	  ./srcs/inventory/init_selector.c	\
	  ./srcs/inventory/get_item.c

SOUND	= ./srcs/sound/set_vol.c

SRCS	= ./srcs/main.c				\
	  $(HUD)				\
	  $(SOUND)				\
	  $(MAP)				\
	  $(SYSTEM)				\
	  $(EVENT)				\
	  $(GAME)				\
	  $(UTILS)				\
	  $(PARTICLE)				\
	  $(INVENT)				\
	  $(XML)				\
	  $(MENU)

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lm

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
