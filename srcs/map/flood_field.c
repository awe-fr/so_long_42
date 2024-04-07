/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:34:14 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:34:35 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

int	is_playable(t_map_info *map)
{
	char	**cpy;

	cpy = NULL;
	cpy = ft_copy_map(map, cpy);
	if (cpy == NULL)
		return (-1);
	call_next(map, cpy, map->player_y, map->player_x);
	if (scan_map(cpy) == -1)
	{
		free_tab(cpy);
		return (-1);
	}
	free_tab(cpy);
	return (0);
}

int	scan_map(char **cpy)
{
	int	i;
	int	j;

	i = 0;
	while (cpy[i])
	{
		j = 0;
		while (cpy[i][j])
		{
			if (cpy[i][j] == 'C')
				return (-1);
			if (cpy[i][j] == 'E')
			{
				if (cpy[i + 1][j] != '2' && cpy[i - 1][j] != '2'
					&& cpy[i][j + 1] != '2' && cpy[i][j - 1] != '2')
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	call_next(t_map_info *map, char **cpy, int y, int x)
{
	cpy[y][x] = '2';
	if (cpy[y + 1][x] != '1' && cpy[y + 1][x] != '2')
		call_next(map, cpy, y + 1, x);
	if (cpy[y - 1][x] != '1' && cpy[y - 1][x] != '2')
		call_next(map, cpy, y - 1, x);
	if (cpy[y][x + 1] != '1' && cpy[y][x + 1] != '2')
		call_next(map, cpy, y, x + 1);
	if (cpy[y][x - 1] != '1' && cpy[y][x - 1] != '2')
		call_next(map, cpy, y, x - 1);
}

char	**ft_copy_map(t_map_info *map, char **cpy)
{
	int	i;
	int	j;
	int	x;

	i = map->start_index - 1;
	j = 0;
	cpy = malloc((map->size_y + 1) * sizeof(char *));
	if (!cpy)
		return (NULL);
	while (j < map->size_y && ++i != -1)
	{
		x = 0;
		cpy[j] = malloc((map->size_x + 1) * sizeof(char));
		if (!cpy[j])
			return (NULL);
		while (map->map[i][x])
		{
			cpy[j][x] = map->map[i][x];
			x++;
		}
		cpy[j++][x] = '\0';
	}
	cpy[j] = '\0';
	return (cpy);
}
