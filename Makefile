NAME = so_long

SRCS = main.c\
	src/map_management/*.c\
	src/window_management/*.c\
	src/game_management/*.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(SRCS) include/minilibx-linux/libmlx.a -lXext -lX11 -o $(NAME)
				
clean:
			$(RM) $(OBJS)
			
fclean:		clean
			$(RM) $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re
