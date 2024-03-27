#include "../headers/major.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		bad_arguments();
	map_parsing(av[1]);
}