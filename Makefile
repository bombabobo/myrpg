##
## EPITECH PROJECT, 2023
## Untitled (Workspace)
## File description:
## Makefile
##

HEADER_NAME = my.h

NAME = my_rpg

CFILES	=	src/main.c \
		src/create/create_struct.c \
		src/create/create_map.c \
		src/create/create_gamescene.c \
		src/create/create_ui.c \
		src/create/create_ingame_ui.c \
		src/create/create_string.c \
		src/free/free_struct.c \
		src/free/free_ui.c \
		src/free/free_ingame_ui.c \
		src/updates/update_game.c \
		src/updates/update_player.c \
		src/updates/update_mobs.c \
		src/updates/update_ingame_ui.c \
		src/updates/update_inv.c \
		src/updates/update_ui.c \
		src/updates/update_settings.c \
		src/updates/update.c \
		src/events/event.c \
		src/events/event_ui.c \
		src/events/event_settings.c \
		src/events/player_events.c \
		src/set/set_player.c \
		src/save_load/save_struct.c \
		src/save_load/load_struct.c \
		src/button.c \
		src/collisions.c \
		src/read_file.c \
		src/window/window_mode.c \

OFILES = $(CFILES:.c=.o)

CFLAGS = $(BASE_FLAGS) $(CSFML_FLAGS)

CSFML_FLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

BASE_FLAGS = -g3 -Wall -Wextra -lm

all: $(NAME)

$(NAME): $(OFILES)
	@gcc -o $(NAME) $(CFILES) $(CFLAGS)

clean:
	@rm -rf $(OFILES)

fclean: clean
	@rm -rf $(NAME) vgcore.*

re: fclean all

reclean: fclean all
	@rm -rf $(OFILES)
