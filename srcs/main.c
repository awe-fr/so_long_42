#include "../headers/major.h"

int	main(int ac, char **av)
{
	t_map_info	map;

	if (ac != 2)
		bad_arguments();
	map_init(&map, av[1]);
	map_parsing(&map);
	map_free(&map);
}