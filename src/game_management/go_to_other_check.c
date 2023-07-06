/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_other_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:46:44 by srajaoui          #+#    #+#             */
/*   Updated: 2023/07/05 14:57:51 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

void	go_to_other_check_up(t_game *game)
{
	if ((game->map[game->y - 1][game->z] == 'e' ||
	game->map[game->y - 1][game->z] == 'E') && game->c_number == 0)
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->y -= 1;
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
		full_free(game);
	}
}

void	go_to_other_check_right(t_game *game)
{
	if ((game->map[game->y][game->z + 1] == 'e' ||
	game->map[game->y][game->z + 1] == 'E') && game->c_number == 0)
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->z += 1;
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
		full_free(game);
	}
}

void	go_to_other_check_left(t_game *game)
{
	if ((game->map[game->y][game->z - 1] == 'e'||
	game->map[game->y][game->z - 1] == 'E') && game->c_number == 0)
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->z -= 1;
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
		full_free(game);
	}
}

void	go_to_other_check_down(t_game *game)
{
	if ((game->map[game->y + 1][game->z] == 'e'||
	game->map[game->y + 1][game->z] == 'E') && game->c_number == 0)
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->y += 1;
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
		full_free(game);
	}
}
