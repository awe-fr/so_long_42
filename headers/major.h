#ifndef MAJOR_H
# define MAJOR_H

// # include "./MLX42/mlx42.h"
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* struct */

typedef struct s_map_info
{
	char	**map;
	char	*map_path;
	char	*map_flat;
	bool	playable;
	bool	player;
	bool	closed;
	bool	shape;
	bool	exit;
	int		map_file;
	int		objects;
}	t_map_info;

/* error */
void	error_in_parsing_map(t_map_info *map);
void	bad_arguments();
void	bad_path();

/* utils */
char	*ft_strjoin(char *first, char *second);
char	*ft_strcopy(char *str);
int		ft_strlen(char *str);

/* parsing */
void	map_init(t_map_info *map, char *path);
int	map_by_grid_loop(t_map_info *map, int i, int x);
int	map_by_grid(t_map_info *map);
int map_parsing(t_map_info *map);
int	map_by_line(t_map_info *map);
int	next_line_count(char *str);
int	get_map(t_map_info *map);
int	count_line(char *str);

/* free */
void	map_free(t_map_info *map);

#endif