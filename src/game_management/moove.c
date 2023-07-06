/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:10:16 by srajaoui          #+#    #+#             */
/*   Updated: 2023/07/01 16:10:18 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

void	moove(t_game *game)
{	
	game->y = 0;
	game->z = 0;
	find_player(game);
	mlx_key_hook(game->win, code_mouve, game);
}

void	find_player(t_game *game)
{
	while (game->map[game->y])
	{
		(game->z) = 0;
		while (game->map[game->y][game->z])
		{
			if (game->map[game->y][game->z] == 'p')
				break ;
			++(game->z);
		}
		if (game->map[game->y][game->z] == 'p')
			break ;
		++(game->y);
	}
}
