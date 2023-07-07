/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:01:28 by srajaoui          #+#    #+#             */
/*   Updated: 2023/06/29 18:50:35 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

void	game_start(t_game *game)
{
	int	size;

	size = 32;
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"./sprite/exit.xpm", &size, &size);
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"./sprite/floor.xpm", &size, &size);
	game->obj = mlx_xpm_file_to_image(game->mlx,
			"./sprite/obj.xpm", &size, &size);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"./sprite/wall.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"./sprite/player.xpm", &size, &size);
}

void	map_init(t_game *game)
{
	int	y;
	int	z;

	y = 0;
	while (game->map[y])
	{
		z = 0;
		while (game->map[y][z])
		{
			map_init_proces(y, z, game);
			z++;
		}
		y++;
	}
}

void	map_init_proces(int y, int z, t_game *game)
{
	if (game->map[y][z] == '0' || game->map [y][z] == '2')
		mlx_put_image_to_window(game->mlx,
			game->win, game->floor, z * LEN, y * LEN);
	else if (game->map[y][z] == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->wall, z * LEN, y * LEN);
	else if (game->map[y][z] == 'p')
		mlx_put_image_to_window(game->mlx,
			game->win, game->player, z * LEN, y * LEN);
	else if (game->map[y][z] == 'c')
		mlx_put_image_to_window(game->mlx,
			game->win, game->obj, z * LEN, y * LEN);
	else if (game->map[y][z] == 'e')
		mlx_put_image_to_window(game->mlx,
			game->win, game->exit, z * LEN, y * LEN);
}
