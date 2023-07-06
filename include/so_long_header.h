/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:54:04 by srajaoui          #+#    #+#             */
/*   Updated: 2023/07/05 11:22:44 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H

# include <stddef.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"

# define LEN 32

typedef struct	s_game
{
	void *mlx;
	void *win;
	void *exit;
	void *floor;
	void *obj;
	void *player;
	void *wall;
	int	y;
	int	z;
	int	mouve_count;
	int	c_number;
	char **map;
}				t_game;

	/*      Map Management     */

char	*get_flat(int map);
char	**ft_map_to_char(int map);
char	*ft_strncpy(char *s1, char *s2, int n);
char	**ft_split(char *s, char c);
char	**st_split(char *s, char c);
char	*word_dup(char *str, int start, int finish);
int		count_words(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
int		ft_check_elements(char **map, int j, int i);
void	ft_check_correct(char **map);
void	wrong_map(char **map);
void	ft_check_rectangle(char **map, int j);
void	free_all(char **map);
void	ft_is_close(char **map, int j, int i);
void	ft_is_close_startend(char **map, int j, int i, int lenj);
void	find_p(char **map, int *j, int *i);
void	flood_fill(char **map, int j, int i, int save_c);
void	livai(char **map, int j, int i);
void	change_char(char **map, int j, int i);
void	ft_check_field(char **map, int j, int i, int save_c);
void	map_to_struct(char **map, t_game *game);
void	count_c(t_game *game);

	/*     Window Management    */

void	window_open(char **map);
int	esc_exit(int keycode, t_game *game);
int	free_display(t_game *game);
int	axe_y(char **map);
int	axe_z(char **map);

	/*      Game Management     */

void	game_start(t_game *game);
void	map_init(t_game *game);
void	map_init_proces(int y, int z, t_game *game);
void	find_player(t_game *game);
void	moove(t_game *game);
int	code_mouve(int Keycode, t_game *game);
void	can_go_up(t_game *game);
void	can_go_right(t_game *game);
void	can_go_left(t_game *game);
void	can_go_down(t_game *game);
void    go_to_other_check_up(t_game *game);
void    go_to_other_check_right(t_game *game);
void    go_to_other_check_left(t_game *game);
void    go_to_other_check_down(t_game *game);
void	full_free(t_game *game);

#endif
