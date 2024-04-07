/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:15:57 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:16:10 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

void	enemy_move(t_game_info *game, t_map_info *map)
{
	int	move;
	int	i;

	i = 0;
	if (game->enemy_last_move + 1 > mlx_get_time())
		return ;
	game->enemy_last_move = mlx_get_time();
	while (i < map->enemy)
	{
		move = rand() % 4;
		if (move == 0)
			enemy_can_go_right(game, map, i);
		else if (move == 1)
			enemy_can_go_left(game, map, i);
		else if (move == 2)
			enemy_can_go_down(game, map, i);
		else if (move == 3)
			enemy_can_go_up(game, map, i);
		i++;
	}
}

void	enemy_can_go_right(t_game_info *game, t_map_info *map, int i)
{
	if (map->enemy_y[i] == map->exit_y && map->enemy_x[i] + 1 == map->exit_x)
		return ;
	if (map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] + 1]
		== '0')
	{
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] + 1] = 'B';
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i]] = '0';
		map->enemy_x[i] += 1;
	}
	else if (map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] + 1]
			== 'P' || map->map[map->enemy_y[i]
				+ map->start_index][map->enemy_x[i] + 1] == 'O'
					|| map->map[map->enemy_y[i]
						+ map->start_index][map->enemy_x[i] + 1] == 'I'
							|| map->map[map->enemy_y[i]
								+ map->start_index][map->enemy_x[i] + 1] == 'U')
		game_over(game, "Your died\n");
}

void	enemy_can_go_left(t_game_info *game, t_map_info *map, int i)
{
	if (map->enemy_y[i] == map->exit_y && map->enemy_x[i] - 1 == map->exit_x)
		return ;
	if (map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] - 1]
		== '0')
	{
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] - 1] = 'V';
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i]] = '0';
		map->enemy_x[i] -= 1;
	}
	else if (map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] - 1]
			== 'P' || map->map[map->enemy_y[i]
				+ map->start_index][map->enemy_x[i] - 1] == 'O'
					|| map->map[map->enemy_y[i]
						+ map->start_index][map->enemy_x[i] - 1] == 'I'
							|| map->map[map->enemy_y[i]
								+ map->start_index][map->enemy_x[i] - 1] == 'U')
		game_over(game, "Your died\n");
}

void	enemy_can_go_down(t_game_info *game, t_map_info *map, int i)
{
	if (map->enemy_y[i] + 1 == map->exit_y && map->enemy_x[i] == map->exit_x)
		return ;
	if (map->map[map->enemy_y[i] + map->start_index + 1][map->enemy_x[i]]
		== '0')
	{
		map->map[map->enemy_y[i] + map->start_index + 1][map->enemy_x[i]] = 'M';
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i]] = '0';
		map->enemy_y[i] += 1;
	}
	else if (map->map[map->enemy_y[i] + map->start_index + 1][map->enemy_x[i]]
			== 'P' || map->map[map->enemy_y[i] + map->start_index
				+ 1][map->enemy_x[i]] == 'O' || map->map[map->enemy_y[i]
					+ map->start_index + 1][map->enemy_x[i]] == 'I'
						|| map->map[map->enemy_y[i] + map->start_index
							+ 1][map->enemy_x[i]] == 'U')
		game_over(game, "Your died\n");
}

void	enemy_can_go_up(t_game_info *game, t_map_info *map, int i)
{
	if (map->enemy_y[i] - 1 == map->exit_y && map->enemy_x[i] == map->exit_x)
		return ;
	if (map->map[map->enemy_y[i] + map->start_index - 1][map->enemy_x[i]]
		== '0')
	{
		map->map[map->enemy_y[i] + map->start_index - 1][map->enemy_x[i]] = 'N';
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i]] = '0';
		map->enemy_y[i] -= 1;
	}
	else if (map->map[map->enemy_y[i] + map->start_index - 1][map->enemy_x[i]]
			== 'P' || map->map[map->enemy_y[i] + map->start_index
				- 1][map->enemy_x[i]] == 'O' || map->map[map->enemy_y[i]
					+ map->start_index - 1][map->enemy_x[i]] == 'I'
						|| map->map[map->enemy_y[i] + map->start_index
							- 1][map->enemy_x[i]] == 'U')
		game_over(game, "Your died\n");
}
