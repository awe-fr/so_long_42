/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_mouve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:41:11 by srajaoui          #+#    #+#             */
/*   Updated: 2023/07/04 18:41:14 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

void	can_go_up(t_game *game)
{
	if (game->map[game->y - 1][game->z] == '0' ||
	game->map[game->y - 1][game->z] == '2')
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->y -= 1;
		moove_count(game);
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
	}
	else if (game->map[game->y - 1][game->z] == 'c'||
	game->map[game->y - 1][game->z] == 'C')
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->y -= 1;
		moove_count(game);
		game->map[game->y][game->z] = '0';
		game->c_number -= 1;
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
	}
	else
		go_to_other_check_up(game);
}

void	can_go_right(t_game *game)
{
	if (game->map[game->y][game->z + 1] == '0' ||
	game->map[game->y][game->z + 1] == '2')
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->z += 1;
		moove_count(game);
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
	}
	else if (game->map[game->y][game->z + 1] == 'c' ||
	game->map[game->y][game->z + 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->z += 1;
		moove_count(game);
		game->map[game->y][game->z] = '0';
		game->c_number -= 1;
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
	}
	else
		go_to_other_check_right(game);
}

void	can_go_left(t_game *game)
{
	if (game->map[game->y][game->z - 1] == '0'||
	game->map[game->y][game->z - 1] == '2')
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->z -= 1;
		moove_count(game);
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
	}
	else if (game->map[game->y][game->z - 1] == 'c'||
	game->map[game->y][game->z - 1] == 'C')
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->z -= 1;
		moove_count(game);
		game->map[game->y][game->z] = '0';
		game->c_number -= 1;
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
	}
	else
		go_to_other_check_left(game);
}

void	can_go_down(t_game *game)
{
	if (game->map[game->y + 1][game->z] == '0'||
	game->map[game->y + 1][game->z] == '2')
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->y += 1;
		moove_count(game);
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
	}
	else if (game->map[game->y + 1][game->z] == 'c'||
	game->map[game->y + 1][game->z] == 'C')
	{
		mlx_put_image_to_window(game->mlx,
		game->win, game->floor, game->z * LEN, game->y * LEN);
		game->y += 1;
		moove_count(game);
		game->map[game->y][game->z] = '0';
		game->c_number -= 1;
		mlx_put_image_to_window(game->mlx,
		game->win, game->player, game->z * LEN, game->y * LEN);
	}
	else
		go_to_other_check_down(game);
}
