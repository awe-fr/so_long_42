#include "../headers/major.h"

void	map_free(t_map_info *map)
{
	int	i;

	i = 0;
	if (map->map) 
	{
		while(map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	if (map->map_flat)
		free(map->map_flat);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
		free(tab[i++]);
	free(tab);
}