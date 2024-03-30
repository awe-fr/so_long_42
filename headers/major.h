#ifndef MAJOR_H
# define MAJOR_H

# include "./MLX42/mlx42.h"
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/* define */

# define SCALE 32

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
	int		start_index;
	int		map_file;
	int		player_x;
	int		player_y;
	int		objects;
	int		size_x;
	int		size_y;
	int		enemy;
}	t_map_info;

typedef	struct s_game_info
{
	mlx_image_t	*img;
	t_map_info	*map;
	mlx_t		*mlx;
}	t_game_info;

/* error */
void	error_in_parsing_map(t_map_info *map);
void	mlx_fail_init(t_game_info *game);
void	bad_map_info(t_map_info *map);
void	bad_arguments();
void	bad_path();

/* utils */
char	*ft_strjoin(char *first, char *second);
char	*ft_strcopy(char *str);
int		ft_strlen(char *str);

/* parsing */
void	map_init(t_map_info *map, char *path);
void	map_parsing(t_map_info *map);
int		map_by_grid_loop(t_map_info *map, int i, int x);
int		get_map_size(t_map_info *map);
int		map_by_grid(t_map_info *map);
int		map_by_line(t_map_info *map);
int		get_player(t_map_info *map);
int		next_line_count(char *str);
int		get_index(t_map_info *map);
int		get_map(t_map_info *map);
int		map_x(t_map_info *map);
int		map_y(t_map_info *map);
int		count_line(char *str);

/* map */
char	**ft_copy_map(t_map_info *map, char **cpy);
void	call_next(t_map_info *map, char **cpy, int y, int x);
int		extract_item(t_map_info *map, int i, int j);
int		is_good_item(t_map_info *map);
int		is_playable(t_map_info *map);
int		check_info(t_map_info *map);
int		is_shaped(t_map_info *map);
int		is_closed(t_map_info *map);
int		scan_map(char **cpy);

/* game */
void	key_handler(void	*gam);
void    game_loop(t_map_info *map);

/* exit */

/* free */
void	free_graphics(t_game_info *map);
void	map_free(t_map_info *map);
void	free_tab(char **tab);

#endif