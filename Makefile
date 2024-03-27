NAME = so_long

SRCS = SRCS/*.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS_MLX = -Iinclude -ldl -lglfw -pthread -lm -o
CFLAGS = #-Wall -Werror -Wextra
RM = rm -f

MLX_PATH  = headers/MLX42/
MLX_EXEC = libmlx42.a
MLX = $(MLX_PATH)$(MLX_EXEC)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(SRCS) $(MLX) $(CFLAGS_MLX) $(NAME) -g -O3
				
clean:
			$(RM) $(OBJS)
			
fclean:		clean
			$(RM) $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re
