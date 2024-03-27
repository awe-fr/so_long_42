#ifndef MAJOR_H
# define MAJOR_H

// # include "./MLX42/mlx42.h"
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

/* struct */

typedef struct s_map_info
{
	char	**map;
	bool	exit;
	bool	player;
	bool	objects;
	bool	closed;
	bool	shape;
	bool	playable;
}	t_map_info;

/* error */
void	bad_arguments();
void	bad_path();

/* utils */
int ft_strlen(char *str);

/* parsing */
int map_parsing(char *map_path);

#endif