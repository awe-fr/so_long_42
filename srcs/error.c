#include "../headers/major.h"

void	bad_arguments()
{
	write(2, "Error\n", ft_strlen("Error\n"));
	write(2, "Wrong number of file\n", strlen("Wrong number of file\n"));
	exit(1);
}

void	bad_path()
{
	write(2, "Error\n", ft_strlen("Error\n"));
	write(2, "Wrong map path\n", strlen("Wrong map path\n"));
	exit(1);
}