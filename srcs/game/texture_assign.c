/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:04:36 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:31:55 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

void	assign_texture_player(t_game_info *game)
{
	int	i;

	i = -1;
	while (++i < 3)
		assign_texture(game->textures->player_front[i],
			game->img->player_front[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->player_right[i],
			game->img->player_right[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->player_back[i],
			game->img->player_back[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->player_left[i],
			game->img->player_left[i]);
}

void	assign_texture_enemy(t_game_info *game)
{
	int	i;

	i = -1;
	while (++i < 3)
		assign_texture(game->textures->enemy_front[i],
			game->img->enemy_front[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->enemy_right[i],
			game->img->enemy_right[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->enemy_back[i], game->img->enemy_back[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->enemy_left[i], game->img->enemy_left[i]);
}

void	assign_texture_object(t_game_info *game)
{
	int	i;

	i = -1;
	while (++i < 24)
		assign_texture(game->textures->object[i], game->img->object[i]);
}

void	assign_texture_exit(t_game_info *game)
{
	int	i;

	i = -1;
	while (++i < 12)
		assign_texture(game->textures->exit[i], game->img->exit[i]);
}

void	assign_texture(mlx_texture_t *texture, unsigned long **img)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (i < TEXTURE_SCALE)
	{
		j = 0;
		while (j < TEXTURE_SCALE)
		{
			img[i][j] = creatergba((int)texture->pixels[x],
					(int)texture->pixels[x + 1], (int)texture->pixels[x + 2],
					(int)texture->pixels[x + 3]);
			j++;
			x += 4;
		}
		i++;
	}
}
