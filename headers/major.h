/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   major.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:36:10 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:55:38 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAJOR_H
# define MAJOR_H

# include "./MLX42/mlx42.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

# include <stdio.h>
# include <string.h>

/* define */

# define SCALE 32
# define TEXTURE_SCALE 32

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
	int		*enemy_y;
	int		*enemy_x;
	int		start_index;
	int		map_file;
	int		player_x;
	int		player_y;
	int		objects;
	int		exit_x;
	int		exit_y;
	int		size_x;
	int		size_y;
	int		enemy;
	int		move;
}	t_map_info;

typedef struct s_texture_info
{
	mlx_texture_t	*player_front[3];
	mlx_texture_t	*player_right[3];
	mlx_texture_t	*player_back[3];
	mlx_texture_t	*player_left[3];
	mlx_texture_t	*enemy_front[3];
	mlx_texture_t	*enemy_right[3];
	mlx_texture_t	*enemy_back[3];
	mlx_texture_t	*enemy_left[3];
	mlx_texture_t	*object[24];
	mlx_texture_t	*exit[12];
	mlx_texture_t	*floor[1];
	mlx_texture_t	*wall[1];
}	t_texture_info;

typedef struct s_img_info
{
	unsigned long	***player_front;
	unsigned long	***player_right;
	unsigned long	***player_back;
	unsigned long	***player_left;
	unsigned long	***enemy_front;
	unsigned long	***enemy_right;
	unsigned long	***enemy_back;
	unsigned long	***enemy_left;
	unsigned long	***object;
	unsigned long	***exit;
	unsigned long	***floor;
	unsigned long	***wall;
}	t_img_info;

typedef struct s_game_info
{
	t_texture_info	*textures;
	mlx_image_t		*count_screen;
	mlx_image_t		*text_screen;
	mlx_image_t		*display;
	t_img_info		*img;
	t_map_info		*map;
	mlx_t			*mlx;
	double			enemy_last_move;
	char			*count_char;
	bool			move_right;
	bool			move_down;
	bool			move_left;
	bool			move_up;
}	t_game_info;

/* error */
void			error_in_parsing_map(t_map_info *map);
void			mlx_fail_init(t_game_info *game);
void			bad_map_info(t_map_info *map);
void			bad_arguments(void);
void			bad_path(void);

/* utils */
size_t			ft_len(int n);
char			*ft_strjoin(char *first, char *second);
char			*ft_itoa_count(char *str, int count);
char			*ft_strcopy(char *str);
int				ft_strlen(char *str);
char			*ft_itoa(int n);

/* parsing */
void			map_init(t_map_info *map, char *path);
void			map_parsing(t_map_info *map);
int				map_by_grid_loop(t_map_info *map, int i, int x);
int				get_map_size(t_map_info *map);
int				map_by_grid(t_map_info *map);
int				map_by_line(t_map_info *map);
int				get_player(t_map_info *map);
int				get_enemy(t_map_info *map);
int				next_line_count(char *str);
int				get_index(t_map_info *map);
int				get_exit(t_map_info *map);
int				get_map(t_map_info *map);
int				map_x(t_map_info *map);
int				map_y(t_map_info *map);
int				count_line(char *str);

/* map */
char			**ft_copy_map(t_map_info *map, char **cpy);
void			call_next(t_map_info *map, char **cpy, int y, int x);
int				extract_item(t_map_info *map, int i, int j);
int				is_good_item(t_map_info *map);
int				is_playable(t_map_info *map);
int				check_info(t_map_info *map);
int				is_shaped(t_map_info *map);
int				is_closed(t_map_info *map);
int				scan_map(char **cpy);

/* game */
void			init_game(t_game_info *game, t_map_info *map,
					t_texture_info *textures, t_img_info *img);
void			print_tiles(t_game_info *game, unsigned long ***tiles,
					int nb_frame, int *coor);
void			enemy_can_go_right(t_game_info *game, t_map_info *map, int i);
void			enemy_can_go_left(t_game_info *game, t_map_info *map, int i);
void			enemy_can_go_down(t_game_info *game, t_map_info *map, int i);
void			enemy_can_go_up(t_game_info *game, t_map_info *map, int i);
void			can_go_right_2(t_game_info *game, t_map_info *map);
void			can_go_down_2(t_game_info *game, t_map_info *map);
void			can_go_left_2(t_game_info *game, t_map_info *map);
void			what_put_player(t_game_info *game, int i, int j);
void			can_go_right(t_game_info *game, t_map_info *map);
void			what_put_enemy(t_game_info *game, int i, int j);
void			can_go_down(t_game_info *game, t_map_info *map);
void			can_go_left(t_game_info *game, t_map_info *map);
void			can_go_up_2(t_game_info *game, t_map_info *map);
void			enemy_move(t_game_info *game, t_map_info *map);
void			can_go_up(t_game_info *game, t_map_info *map);
void			what_put(t_game_info *game, int i, int j);
void			game_over(t_game_info *game, char *msg);
void			start_print(t_game_info *game);
void			write_step(t_game_info *game);
void			game_loop(t_map_info *map);
void			key_handler(void *gam);
int				find_frame(t_game_info *game, unsigned long ***tiles,
					int nb_frame);

/* textures */
unsigned long	***alloc_int_tab(unsigned long ***img, int size);
unsigned long	creatergba(int r, int g, int b, int a);
void			assign_texture(mlx_texture_t *texture, unsigned long **img);
void			assign_texture_player(t_game_info *game);
void			assign_texture_object(t_game_info *game);
void			get_object_textures_2(t_game_info *game);
void			assign_texture_enemy(t_game_info *game);
void			assign_texture_exit(t_game_info *game);
void			get_player_textures(t_game_info *game);
void			get_object_textures(t_game_info *game);
void			get_enemy_textures(t_game_info *game);
void			get_exit_textures(t_game_info *game);
void			alloc_textures(t_game_info *game);
void			get_textures(t_game_info *game);

/* free */
void			free_texture(unsigned long ***texture, int z, int y);
void			free_graphics(t_game_info *map);
void			free_img(t_texture_info *imgs);
void			map_free(t_map_info *map);
void			free_tab(char **tab);

#endif