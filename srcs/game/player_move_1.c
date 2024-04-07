/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:11:28 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 03:03:13 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

void	can_go_right(t_game_info *game, t_map_info *map)
{
	if (game->move_right == false)
		return ;
	if (map->map[map->player_y + map->start_index][map->player_x + 1] == 'E'
		&& map->objects == 0)
		game_over(game, "You finish the Game\n");
	if (map->map[map->player_y + map->start_index][map->player_x + 1] == '0'
		|| map->map[map->player_y + map->start_index][map->player_x + 1] == 'E')
	{
		map->map[map->player_y + map->start_index][map->player_x + 1] = 'I';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_x += 1;
	}
	else
		can_go_right_2(game, map);
	map->move++;
	game->move_right = false;
}

void	can_go_right_2(t_game_info *game, t_map_info *map)
{
	if (map->map[map->player_y + map->start_index][map->player_x + 1] == 'C')
	{
		map->map[map->player_y + map->start_index][map->player_x + 1] = 'I';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_x += 1;
		map->objects -= 1;
		if (map->objects == 0)
			map->map[map->exit_y + map->start_index][map->exit_x] = 'E';
	}
	else if (map->map[map->player_y + map->start_index][map->player_x + 1]
			== '1')
		map->map[map->player_y + map->start_index][map->player_x] = 'I';
	else if (map->map[map->player_y + map->start_index][map->player_x + 1]
			== 'M' || map->map[map->player_y + map->start_index][map->player_x
				+ 1] == 'N' || map->map[map->player_y
					+ map->start_index][map->player_x + 1] == 'B'
						|| map->map[map->player_y
							+ map->start_index][map->player_x + 1] == 'V')
		game_over(game, "Your died\n");
}

void	can_go_down(t_game_info *game, t_map_info *map)
{
	if (game->move_down == false)
		return ;
	if ((map->map[map->player_y + map->start_index + 1][map->player_x] == 'E'
		&& map->objects == 0))
		game_over(game, "You finish the Game\n");
	if (map->map[map->player_y + map->start_index + 1][map->player_x] == '0'
		|| map->map[map->player_y + map->start_index + 1][map->player_x] == 'E')
	{
		map->map[map->player_y + map->start_index + 1][map->player_x] = 'P';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_y += 1;
	}
	else
		can_go_down_2(game, map);
	map->move++;
	game->move_down = false;
}

void	can_go_down_2(t_game_info *game, t_map_info *map)
{
	if (map->map[map->player_y + map->start_index + 1][map->player_x] == 'C')
	{
		map->map[map->player_y + map->start_index + 1][map->player_x] = 'P';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_y += 1;
		map->objects -= 1;
		if (map->objects == 0)
			map->map[map->exit_y + map->start_index][map->exit_x] = 'E';
	}
	else if (map->map[map->player_y + map->start_index + 1][map->player_x]
		== '1')
		map->map[map->player_y + map->start_index][map->player_x] = 'P';
	else if (map->map[map->player_y + map->start_index + 1][map->player_x]
			== 'M' || map->map[map->player_y + map->start_index
				+ 1][map->player_x] == 'N' || map->map[map->player_y
					+ map->start_index + 1][map->player_x] == 'B'
						|| map->map[map->player_y + map->start_index
							+ 1][map->player_x] == 'V')
		game_over(game, "Your died\n");
}
