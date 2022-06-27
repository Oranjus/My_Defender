##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## /
##

SRC	=	src/main.c	\
		src/window.c	\
		src/load_object.c	\
		src/utils/cursor.c	\
		src/utils/evt_click_sprite.c	\
		src/utils/help.c	\
		src/utils/load_sprite.c	\
		src/utils/load_text.c	\
		src/utils/button/button/display_btn.c	\
		src/utils/button/button/manage_btn.c	\
		src/utils/button/button/init_buton.c	\
		src/utils/button/button/listen_event.c	\
		src/utils/load_music.c	\
		src/EVENT/event.c	\
		src/EVENT/listener.c	\
		src/MENU/load_menu.c	\
		src/MENU/menu_loop.c	\
		src/MENU/sub_menu/info.c	\
		src/MENU/sub_menu/map.c	\
		src/MENU/sub_menu/trophea.c	\
		src/MENU/event_menu.c	\
		src/MENU/display_menu.c	\
		src/MENU/button/method_btn.c	\
		src/MENU/button/load_button.c	\
		src/GAME/game_loop.c	\
		src/GAME/assault_loop.c	\
		src/GAME/build_loop.c	\
		src/GAME/pause.c		\
		src/GAME/display_game.c	\
		src/GAME/EVENT/game_event.c	\
		src/GAME/load_game.c	\
		src/GAME/object/ENEMIE/manage_enemie.c	\
		src/GAME/object/ENEMIE/init_enemie.c	\
		src/GAME/object/ENEMIE/spawn_enemie.c	\
		src/GAME/object/building/building.c	\
		src/GAME/object/building/manage_build.c	\
		src/GAME/object/building/init_build.c	\
		src/HUD/display_hud.c	\
		src/HUD/load_hud.c	\
		src/HUD/method_hud.c	\
		src/HUD/update_hud.c	\

CPPFLAGS	=	-I./include

NAME	=	my_defender

LIB 	=	-L lib/my -lmy

CSFMLFLAG	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio

GCC	=	gcc

SRC_ALL	=	$(SRC)

all:	$(NAME)

$(NAME)	:
	@make build
	@$(GCC) $(SRC) -o $(NAME) $(CPPFLAGS) $(LIB) $(CSFMLFLAG)

build:
	@$(MAKE) -s -C lib/my

clean:
	rm -f $(NAME);
	rm -f lib/my/libmy.a

fclean : clean
	clear
	@rm -f *~
	@rm -f *#*

re :	fclean clean all

gdb	:
	gcc $(SRC) -o $(NAME) $(CPPFLAGS) $(LIB) $(CSFMLFLAG) -ggdb3
