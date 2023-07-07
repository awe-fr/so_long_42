/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:45:55 by srajaoui          #+#    #+#             */
/*   Updated: 2023/07/05 11:25:26 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

void	window_open(char **map)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, axe_z(map), axe_y(map), "so_long");
	mlx_key_hook(game.win, esc_exit, &game);
	mlx_hook(game.win, 17, 1L << 8, free_display, &game);
	game.moove_count = 0;
	game_start(&game);
	map_to_struct(map, &game);
	count_c(&game);
	map_init(&game);
	moove(&game);
	mlx_loop(game.mlx);
}

int	axe_y(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y * LEN);
}

int	axe_z(char **map)
{
	int	z;

	z = 0;
	while (map[0][z])
		z++;
	return (z * LEN);
}
