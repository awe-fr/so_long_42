/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:34:44 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:34:59 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/major.h"

int	main(int ac, char **av)
{
	t_map_info	map;

	if (ac != 2)
		bad_arguments();
	map_init(&map, av[1]);
	map_parsing(&map);
	game_loop(&map);
	map_free(&map);
}
