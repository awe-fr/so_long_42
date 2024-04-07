/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:22:35 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:22:59 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

void	what_put(t_game_info *game, int i, int j)
{
	int	coor[2];

	coor[0] = i - game->map->start_index;
	coor[1] = j;
	if (game->map->map[i][j] == '1')
		print_tiles(game, game->img->wall, 1, coor);
	else if (game->map->map[i][j] == '0')
		print_tiles(game, game->img->floor, 1, coor);
	else if (game->map->map[i][j] == 'P' || game->map->map[i][j] == 'O'
		|| game->map->map[i][j] == 'I' || game->map->map[i][j] == 'U')
		what_put_player(game, i, j);
	else if (game->map->map[i][j] == 'M' || game->map->map[i][j] == 'N'
		|| game->map->map[i][j] == 'B' || game->map->map[i][j] == 'V')
		what_put_enemy(game, i, j);
	else if (game->map->map[i][j] == 'C')
		print_tiles(game, game->img->object, 24, coor);
	else if (game->map->map[i][j] == 'E')
		print_tiles(game, game->img->exit, 12, coor);
}

void	what_put_player(t_game_info *game, int i, int j)
{
	int	coor[2];

	coor[0] = i - game->map->start_index;
	coor[1] = j;
	if (game->map->map[i][j] == 'P')
		print_tiles(game, game->img->player_front, 3, coor);
	else if (game->map->map[i][j] == 'O')
		print_tiles(game, game->img->player_back, 3, coor);
	else if (game->map->map[i][j] == 'I')
		print_tiles(game, game->img->player_right, 3, coor);
	else if (game->map->map[i][j] == 'U')
		print_tiles(game, game->img->player_left, 3, coor);
}

void	what_put_enemy(t_game_info *game, int i, int j)
{
	int	coor[2];

	coor[0] = i - game->map->start_index;
	coor[1] = j;
	if (game->map->map[i][j] == 'M')
		print_tiles(game, game->img->enemy_front, 3, coor);
	else if (game->map->map[i][j] == 'N')
		print_tiles(game, game->img->enemy_back, 3, coor);
	else if (game->map->map[i][j] == 'B')
		print_tiles(game, game->img->enemy_right, 3, coor);
	else if (game->map->map[i][j] == 'V')
		print_tiles(game, game->img->enemy_left, 3, coor);
}
