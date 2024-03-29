#include "../headers/major.h"

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
	int i;
	int j;

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
				if (cpy[i + 1][j] != '2' && cpy[i - 1][j] != '2' && cpy[i][j + 1] != '2' && cpy[i][j - 1] != '2')
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
	if (cpy[y + 1][x] != '1' && cpy[y + 1][x] != 'E' && cpy[y + 1][x] != '2')
		call_next(map, cpy, y + 1, x);
	if (cpy[y - 1][x] != '1' && cpy[y - 1][x] != 'E' && cpy[y - 1][x] != '2')
		call_next(map, cpy, y - 1, x);
	if (cpy[y][x + 1] != '1' && cpy[y][x + 1] != 'E' && cpy[y][x + 1] != '2')
		call_next(map, cpy, y, x + 1);
	if (cpy[y][x - 1] != '1' && cpy[y][x - 1] != 'E' && cpy[y][x - 1] != '2')
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
	while(j < map->size_y && ++i != -1)
	{
		x = 0;
		cpy[j] =  malloc((map->size_x + 1) * sizeof(char));
		if (!cpy[j])
			return (NULL);
		while(map->map[i][x])
		{
			cpy[j][x] = map->map[i][x];
			x++;
		}
		cpy[j++][x] = '\0';
	}
	cpy[j] = '\0';
	return (cpy);
}

int	is_good_item(t_map_info *map)
{
	int	i;
	int	j;

	i = map->start_index;
	while(i < map->start_index + map->size_y)
	{
		j = 0;
		while(j < map->size_x)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != 'C' && map->map[i][j] != 'E' && map->map[i][j] != 'P' && map->map[i][j] != 'M')
				return (-1);
			if (extract_item(map, i, j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (map->player != true || map->exit != true || map->objects < 1)
		return(-1);
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
	while(j < map->size_x)
	{
		if (map->map[map->start_index][j++] != '1')
			return (-1);
	}
	j = 0;
	while(j < map->size_x)
	{
		if (map->map[map->start_index + map->size_y - 1][j++] != '1')
			return (-1);
	}
	while(i < map->start_index + map->size_y - 1)
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
	while(i < map->start_index + map->size_y)
	{
		if (ft_strlen(map->map[i++]) != map->size_x)
			return (-1);
	}
	map->shape = true;
	return (0);
}