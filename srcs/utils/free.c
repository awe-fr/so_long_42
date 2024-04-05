#include "../../headers/major.h"

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
	// free les mechant
	// close les fichier
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_graphics(t_game_info *game)
{
	map_free(game->map);


	//delete l'image
	//delete les images
	//delete les texture
	//detele l'instance
	exit(0);
}