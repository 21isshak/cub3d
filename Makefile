NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
INCLUDE = -I include

INCLUDEMLX = -Iminilibx-linux
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

MAKEFLAGS += --silent

SRCS = $(addprefix src/raycasting/, player_movement.c player_rotation.c key_handlers.c destroy_images.c raycasting.c printing.c textures.c) src/main.c \
	src/parse/parse.c \
	src/parse/parse_tex.c \
	src/parse/parse_color.c \
	src/parse/parse_map.c \
	src/parse/parse_utils.c \
	src/map/map_normalize.c \
	src/map/map_player.c \
	src/map/map_check.c \
	src/utils/error.c \
	src/utils/movement_utils.c \
	src/utils/free.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) $(INCLUDEMLX) -o $(NAME)
	echo "\033[1;35mcub3D\033[0m \033[1;33mgame created\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean
	echo "\033[1;33mobjects cleaned\033[0m"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
	echo "\033[1;33mgame cleaned\033[0m"

re: fclean all

.PHONY: all clean fclean re

