/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:29:10 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:33:03 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

int	get_map_size(t_map_info *map)
{
	map->start_index = get_index(map);
	map->size_x = map_x(map);
	map->size_y = map_y(map);
	if (map->size_x == 0 || map->size_y == 0)
		return (-1);
	if (get_player(map) == -1)
		return (-1);
	if (get_exit(map) == -1)
		return (-1);
	return (0);
}

int	get_enemy(t_map_info *map)
{
	int	i;
	int	j;
	int	x;

	i = map->start_index;
	x = 0;
	map->enemy_x = malloc((map->enemy) * sizeof(int));
	map->enemy_y = malloc((map->enemy) * sizeof(int));
	if (!map->enemy_x || !map->enemy_y)
		return (-1);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'M')
			{
				map->enemy_x[x] = j;
				map->enemy_y[x++] = i - map->start_index;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	get_player(t_map_info *map)
{
	int	i;
	int	j;

	i = map->start_index;
	j = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i - map->start_index;
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

int	get_exit(t_map_info *map)
{
	int	i;
	int	j;

	i = map->start_index;
	j = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'E')
			{
				map->exit_x = j;
				map->exit_y = i - map->start_index;
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

int	get_index(t_map_info *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i++][0] == '1')
			return (i - 1);
	}
	return (0);
}
