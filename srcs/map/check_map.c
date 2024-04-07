/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:39:31 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:34:24 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

int	check_info(t_map_info *map)
{
	if (is_shaped(map) == -1)
		return (-1);
	if (is_closed(map) == -1)
		return (-1);
	if (is_good_item(map) == -1)
		return (-1);
	if (is_playable(map) == -1)
		return (-1);
	return (0);
}

int	is_good_item(t_map_info *map)
{
	int	i;
	int	j;

	i = map->start_index;
	while (i < map->start_index + map->size_y)
	{
		j = 0;
		while (j < map->size_x)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'C' && map->map[i][j] != 'E'
					&& map->map[i][j] != 'P' && map->map[i][j] != 'M')
				return (-1);
			if (extract_item(map, i, j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (map->player != true || map->exit != true || map->objects < 1)
		return (-1);
	return (0);
}

int	extract_item(t_map_info *map, int i, int j)
{
	bool	good;

	good = false;
	if (map->map[i][j] == 'P' && map->player == false)
		map->player = true;
	else if (map->map[i][j] == 'P' && map->player == true)
		good = true;
	else if (map->map[i][j] == 'E' && map->exit == false)
		map->exit = true;
	else if (map->map[i][j] == 'E' && map->exit == true)
		good = true;
	else if (map->map[i][j] == 'C')
		map->objects++;
	else if (map->map[i][j] == 'M')
		map->enemy++;
	if (good == true)
		return (-1);
	return (0);
}

int	is_closed(t_map_info *map)
{
	int	i;
	int	j;

	i = map->start_index + 1;
	j = 0;
	while (j < map->size_x)
	{
		if (map->map[map->start_index][j++] != '1')
			return (-1);
	}
	j = 0;
	while (j < map->size_x)
	{
		if (map->map[map->start_index + map->size_y - 1][j++] != '1')
			return (-1);
	}
	while (i < map->start_index + map->size_y - 1)
	{
		if (map->map[i][0] != '1' || map->map[i][map->size_x - 1] != '1')
			return (-1);
		i++;
	}
	map->closed = true;
	return (0);
}

int	is_shaped(t_map_info *map)
{
	int	i;

	i = map->start_index;
	while (i < map->start_index + map->size_y)
	{
		if (ft_strlen(map->map[i++]) != map->size_x)
			return (-1);
	}
	map->shape = true;
	return (0);
}
