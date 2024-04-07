/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:39:28 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:31:21 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

void	map_parsing(t_map_info *map)
{
	map->map_file = open(map->map_path, O_RDONLY);
	if (get_map(map) == -1)
		bad_path();
	if (get_map_size(map) == -1)
		bad_map_info(map);
	if (check_info(map) == -1)
		bad_map_info(map);
	if (get_enemy(map) == -1)
		bad_map_info(map);
}

int	map_x(t_map_info *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i++][0] == '1')
			return (ft_strlen(map->map[i - 1]));
	}
	return (0);
}

int	map_y(t_map_info *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		if (map->map[i++][0] == '1')
			count++;
	}
	return (count);
}

int	get_map(t_map_info *map)
{
	char	*flat_map;

	if (map->map_file == -1)
		return (-1);
	if (map_by_line(map) == -1)
		error_in_parsing_map(map);
	if (map_by_grid(map) == -1)
		error_in_parsing_map(map);
	return (0);
}

void	map_init(t_map_info *map, char *path)
{
	map->map_path = path;
	map->map_flat = NULL;
	map->enemy_y = NULL;
	map->enemy_x = NULL;
	map->map = NULL;
	map->playable = false;
	map->player = false;
	map->closed = false;
	map->shape = false;
	map->exit = false;
	map->start_index = 0;
	map->map_file = 0;
	map->player_x = 0;
	map->player_y = 0;
	map->objects = 0;
	map->exit_x = 0;
	map->exit_y = 0;
	map->size_x = 0;
	map->size_y = 0;
	map->enemy = 0;
	map->move = 0;
}
