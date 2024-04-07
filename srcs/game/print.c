/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:16:56 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:18:21 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

void	start_print(t_game_info *game)
{
	int	i;
	int	j;

	i = game->map->start_index;
	while (i < game->map->start_index + game->map->size_y)
	{
		j = 0;
		while (j < game->map->size_x)
		{
			what_put(game, i, j);
			j++;
		}
		i++;
	}
}

void	print_tiles(t_game_info *game, unsigned long ***tiles,
	int nb_frame, int *coor)
{
	int	frame;
	int	i;
	int	j;

	frame = 0;
	i = 0;
	if (nb_frame != 1)
		frame = find_frame(game, tiles, nb_frame);
	while (i < TEXTURE_SCALE)
	{
		j = 0;
		while (j < TEXTURE_SCALE)
		{
			mlx_put_pixel(game->display, j * 2 + (coor[1] * SCALE * 2), i * 2
				+ (coor[0] * SCALE * 2), tiles[frame][i][j]);
			mlx_put_pixel(game->display, j * 2 + 1 + (coor[1] * SCALE * 2), i
				* 2 + (coor[0] * SCALE * 2), tiles[frame][i][j]);
			mlx_put_pixel(game->display, j * 2 + (coor[1] * SCALE * 2), i * 2
				+ 1 + (coor[0] * SCALE * 2), tiles[frame][i][j]);
			mlx_put_pixel(game->display, j * 2 + 1 + (coor[1] * SCALE * 2), i
				* 2 + 1 + (coor[0] * SCALE * 2), tiles[frame][i][j]);
			j++;
		}
		i++;
	}
}

int	find_frame(t_game_info *game, unsigned long ***tiles, int nb_frame)
{
	double	select;
	double	rest;

	if (tiles == game->img->exit && game->map->objects != 0)
		return (0);
	else if (tiles == game->img->exit)
		nb_frame--;
	select = mlx_get_time();
	if (nb_frame >= 20)
	{
		rest = select - (int)select;
		select = (int)select % 3;
		select += rest;
		select *= nb_frame / 3;
	}
	else
	{
		select -= (int)select;
		select *= nb_frame;
	}
	if (tiles == game->img->exit)
		return (select + 1);
	return (select);
}

void	write_step(t_game_info *game)
{
	static int	last_count = 0;

	if (last_count != game->map->move)
	{
		mlx_delete_image(game->mlx, game->count_screen);
		free(game->count_char);
		game->count_char = ft_itoa(game->map->move);
		game->count_screen = mlx_put_string(game->mlx, game->count_char,
				135, 5);
		last_count = game->map->move;
	}
}
