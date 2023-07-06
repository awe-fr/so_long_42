/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:01:22 by srajaoui          #+#    #+#             */
/*   Updated: 2023/06/20 14:44:54 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_header.h"

int	main(int ac, char **av)
{
	int		map_txt;
	char	**map;

	map_txt = open(av[1], O_RDONLY);
	map = ft_map_to_char(map_txt);
	map_txt = close(map_txt);
	ft_check_correct(map);
	window_open(map);
	free_all(map);
	exit(0);
	ac = ac + 1;
}
