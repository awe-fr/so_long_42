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

int	get_map_size(t_map_info *map)
{
	map->start_index = get_index(map);
	map->size_x = map_x(map);
	map->size_y = map_y(map);
	if(map->size_x == 0 || map->size_y == 0)
		return (-1);
	if (get_player(map) == -1)
		return (-1);
	if (get_exit(map) == -1)
		return (-1);
	return 0;
}

int	get_enemy(t_map_info *map)
{
	int i;
	int j;
	int	x;

	i = map->start_index;
	x = 0;
	map->enemy_x = malloc((map->enemy) * sizeof(int));
	map->enemy_y = malloc((map->enemy) * sizeof(int));
	if (!map->enemy_x || !map->enemy_y)
		return (-1);
	while(map->map[i])
	{
		j = 0;
		while(map->map[i][j])
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
	int i;
	int j;

	i = map->start_index;
	j = 0;
	while(map->map[i])
	{
		while(map->map[i][j])
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
	int i;
	int j;

	i = map->start_index;
	j = 0;
	while(map->map[i])
	{
		while(map->map[i][j])
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
	int i;

	i = 0;
	while(map->map[i])
	{
		if (map->map[i++][0] == '1')
			return(i - 1);
	}
	return (0);
}

int	map_x(t_map_info *map)
{
	int i; 

	i = 0;
	while(map->map[i])
	{
		if (map->map[i++][0] == '1')
			return (ft_strlen(map->map[i - 1]));
	}
	return (0);
}

int	map_y(t_map_info *map)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while(map->map[i])
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
		return -1;
	if (map_by_line(map) == -1)
		error_in_parsing_map(map);
	if (map_by_grid(map) == -1)
		error_in_parsing_map(map);
	return (0);
}

int	map_by_grid(t_map_info *map)
{
	int	line;
	int	i;
	int x;

	line = count_line(map->map_flat);
	i = 0;
	x = 0;
	map->map = malloc((line + 1) * sizeof(char *));
	if(!map->map)
		return(-1);
	while(i < line)
		map_by_grid_loop(map, i++, x);
	map->map[i] = NULL;
	return (0);
}

int	map_by_grid_loop(t_map_info *map, int i, int x)
{
	static int	j = 0;
	int next_line;

	next_line = next_line_count(map->map_flat);
	map->map[i] = malloc((next_line + 2) * sizeof(char));
	if(!map->map[i])
		return(-1);
	while(x < next_line - 1) {
		map->map[i][x++] = map->map_flat[j++];
	}
	j++;
	map->map[i][x] = '\0';
}

int	count_line(char *str)
{
	int line;
	int	i;

	line = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			line++;
		i++;
	}
	line++;
	return (line);
}

int	next_line_count(char *str)
{
	static int	start = 0;
	int count;

	count = 0;
	while (str[start] != '\0' && str[start] != '\n')
	{
		start++;
		count++;
	}
	if (str[start] == '\n')
		start++;
	return (count + 1);
}

int	map_by_line(t_map_info *map)
{
	int		count;
	char	*buff;

	count = 10001;
	while(count >= 1000)
	{
		buff = malloc((1000 + 1) * sizeof(char));
		if (!buff)
			return(-1);
		count = read(map->map_file, buff, 1000);
		if (count == -1)
		{
			free(buff);
			return (-1);
		}
		buff[count] = '\0';
		map->map_flat = ft_strjoin(map->map_flat, buff);
	}
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