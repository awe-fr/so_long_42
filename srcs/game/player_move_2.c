/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:13:02 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:15:23 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

void	can_go_left(t_game_info *game, t_map_info *map)
{
	if (game->move_left == false)
		return ;
	if (map->map[map->player_y + map->start_index][map->player_x - 1] == 'E'
		&& map->objects == 0)
		game_over(game, "You finish the Game\n");
	if (map->map[map->player_y + map->start_index][map->player_x - 1] == '0'
		|| map->map[map->player_y + map->start_index][map->player_x - 1] == 'E')
	{
		map->map[map->player_y + map->start_index][map->player_x - 1] = 'U';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_x -= 1;
	}
	else
		can_go_left_2(game, map);
	map->move++;
	game->move_left = false;
}

void	can_go_left_2(t_game_info *game, t_map_info *map)
{
	if (map->map[map->player_y + map->start_index][map->player_x - 1] == 'C')
	{
		map->map[map->player_y + map->start_index][map->player_x - 1] = 'U';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_x -= 1;
		map->objects -= 1;
		if (map->objects == 0)
			map->map[map->exit_y + map->start_index][map->exit_x] = 'E';
	}
	else if (map->map[map->player_y + map->start_index][map->player_x
		- 1] == '1')
		map->map[map->player_y + map->start_index][map->player_x] = 'U';
	else if (map->map[map->player_y + map->start_index][map->player_x - 1]
			== 'M' || map->map[map->player_y + map->start_index][map->player_x
				- 1] == 'N' || map->map[map->player_y
					+ map->start_index][map->player_x - 1] == 'B'
						|| map->map[map->player_y
							+ map->start_index][map->player_x - 1] == 'V')
		game_over(game, "Your died\n");
}

void	can_go_up(t_game_info *game, t_map_info *map)
{
	if (game->move_up == false)
		return ;
	if (map->map[map->player_y + map->start_index - 1][map->player_x] == 'E'
		&& map->objects == 0)
		game_over(game, "You finish the Game\n");
	if (map->map[map->player_y + map->start_index - 1][map->player_x] == '0'
		|| map->map[map->player_y + map->start_index - 1][map->player_x] == 'E')
	{
		map->map[map->player_y + map->start_index - 1][map->player_x] = 'O';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_y -= 1;
	}
	else
		can_go_up_2(game, map);
	map->move++;
	game->move_up = false;
}

void	can_go_up_2(t_game_info *game, t_map_info *map)
{
	if (map->map[map->player_y + map->start_index - 1][map->player_x] == 'C')
	{
		map->map[map->player_y + map->start_index - 1][map->player_x] = 'O';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_y -= 1;
		map->objects -= 1;
		if (map->objects == 0)
			map->map[map->exit_y + map->start_index][map->exit_x] = 'E';
	}
	else if (map->map[map->player_y
			+ map->start_index - 1][map->player_x] == '1')
		map->map[map->player_y + map->start_index][map->player_x] = 'O';
	else if (map->map[map->player_y
			+ map->start_index - 1][map->player_x] == 'M'
			|| map->map[map->player_y + map->start_index - 1][map->player_x]
				== 'N' || map->map[map->player_y + map->start_index
					- 1][map->player_x] == 'B' || map->map[map->player_y
						+ map->start_index - 1][map->player_x] == 'V')
		game_over(game, "Your died\n");
}
