#include "../headers/major.h"

int map_parsing(t_map_info *map)
{
	map->map_file = open(map->map_path, O_RDONLY);
	if (get_map(map) == -1)
		bad_path();
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
	map->map = NULL;
	map->map_flat = NULL;
	map->playable = false;
	map->player = false;
	map->closed = false;
	map->shape = false;
	map->exit = false;
	map->map_file = 0;
	map->objects = 0;
}