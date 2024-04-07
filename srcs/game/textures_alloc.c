/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:03:42 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:31:51 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

unsigned long	creatergba(int r, int g, int b, int a)
{
	return (((r & 0xff) << 24) + ((g & 0xff) << 16)
		+ ((b & 0xff) << 8) + (a & 0xff));
}

void	get_textures(t_game_info *game)
{
	game->textures->floor[0] = mlx_load_png("./textures/map/floor.png");
	game->textures->wall[0] = mlx_load_png("./textures/map/wall.png");
	get_player_textures(game);
	get_enemy_textures(game);
	get_object_textures(game);
	get_exit_textures(game);
	alloc_textures(game);
	assign_texture(game->textures->floor[0], game->img->floor[0]);
	assign_texture(game->textures->wall[0], game->img->wall[0]);
	assign_texture_player(game);
	assign_texture_object(game);
	assign_texture_enemy(game);
	assign_texture_exit(game);
}

void	alloc_textures(t_game_info *game)
{
	game->img->player_front = alloc_int_tab(game->img->player_front, 3);
	game->img->player_right = alloc_int_tab(game->img->player_right, 3);
	game->img->player_back = alloc_int_tab(game->img->player_back, 3);
	game->img->player_left = alloc_int_tab(game->img->player_left, 3);
	game->img->enemy_front = alloc_int_tab(game->img->enemy_front, 3);
	game->img->enemy_right = alloc_int_tab(game->img->enemy_right, 3);
	game->img->enemy_back = alloc_int_tab(game->img->enemy_back, 3);
	game->img->enemy_left = alloc_int_tab(game->img->enemy_left, 3);
	game->img->object = alloc_int_tab(game->img->object, 24);
	game->img->exit = alloc_int_tab(game->img->exit, 12);
	game->img->floor = alloc_int_tab(game->img->floor, 1);
	game->img->wall = alloc_int_tab(game->img->wall, 1);
}

unsigned long	***alloc_int_tab(unsigned long ***img, int size)
{
	int	i;
	int	j;

	i = 0;
	img = malloc(size * sizeof(unsigned long **));
	while (i < size)
	{
		j = 0;
		img[i] = malloc(TEXTURE_SCALE * sizeof(unsigned long *));
		while (j < TEXTURE_SCALE)
		{
			img[i][j] = malloc(TEXTURE_SCALE * sizeof(unsigned long));
			j++;
		}
		i++;
	}
	return (img);
}
