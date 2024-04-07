/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 00:32:18 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 00:38:37 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

void	bad_arguments(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	write(2, "Wrong number of arguments\n",
		ft_strlen("Wrong number of arguments\n"));
	exit(1);
}

void	bad_path(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	write(2, "Wrong map path\n", ft_strlen("Wrong map path\n"));
	exit(1);
}

void	error_in_parsing_map(t_map_info *map)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	write(2, "Map parsing problem\n", ft_strlen("Map parsing problem\n"));
	map_free(map);
	exit(1);
}

void	bad_map_info(t_map_info *map)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	write(2, "Map norm problem\n", ft_strlen("Map norm problem\n"));
	map_free(map);
	exit(1);
}

void	mlx_fail_init(t_game_info *game)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	write(2, "MLX failed to initialize\n",
		ft_strlen("MLX failed to initialize\n"));
	map_free(game->map);
	exit(1);
}
