# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/12 02:15:18 by nperrin           #+#    #+#              #
#    Updated: 2015/05/14 19:20:58 by nperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Pac-Man

SDL_DIR = SDL

CC = clang

SDL = $(SDL_DIR)/SDL2-2.0.3

SDL_ZIP = $(SDL_DIR)/SDL2-2.0.3.zip

SDL_INC = SDL/include/

PATH_SDL = https://www.libsdl.org/release/SDL2-2.0.3.zip

SRC =	src/map.c main.c	src/point.c		src/pac_man.c	src/tile.c	src/move.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
	$(CC) -o $(NAME) $(OBJ) -I $(SDL_INC) -L SDL/lib -lSDL2

run: $(NAME)
	./$(NAME)

$(NAME): $(SDL) $(OBJ)

$(SDL): $(SDL_DIR) $(SDL_ZIP)
	(cd SDL/SDL2-2.0.3/; ./configure --prefix=`pwd`/..; make ; make install)

$(SDL_DIR):
	mkdir $(SDL_DIR)

$(SDL_ZIP):
	curl $(PATH_SDL) > $(SDL_ZIP)
	(cd $(SDL_DIR); unzip SDL2-2.0.3.zip)

%.o: %.c
	$(CC) $(FLAG) -o $@ -c $< -I $(SDL_INC) -I include

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: re clean fclean run all
