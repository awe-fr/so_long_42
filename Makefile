NAME = so_long

SRCS = srcs/main.c\
		srcs/game/textures_assign.c\
		srcs/game/textures_getter.c\
		srcs/game/textures_alloc.c\
		srcs/game/player_move_1.c\
		srcs/game/player_move_2.c\
		srcs/game/chose_tiles.c\
		srcs/game/enemy_move.c\
		srcs/game/game_loop.c\
		srcs/game/print.c\
		srcs/map/map_parsing.c\
		srcs/map/flood_field.c\
		srcs/map/get_stuff.c\
		srcs/map/check_map.c\
		srcs/map/parsing.c\
		srcs/utils/recreated_fonction.c\
		srcs/utils/error.c\
		srcs/utils/free.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS_MLX = -Iinclude -ldl -lglfw -pthread -lm -o
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

MLX_PATH  = headers/MLX42/
MLX_EXEC = libmlx42.a
MLX = $(MLX_PATH)$(MLX_EXEC)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(SRCS) $(MLX) $(CFLAGS_MLX) $(NAME) -g
				
clean:
				$(RM) $(OBJS)
			
fclean:			clean
				$(RM) $(NAME)
			
re:				fclean all

.PHONY:			all clean fclean re
