/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_good.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:04:12 by srajaoui          #+#    #+#             */
/*   Updated: 2023/06/20 17:50:25 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

char	*get_flat(int map)
{
	char	*map_flat;
	char	*buff;
	int		zero;

	map_flat = (char *)malloc(1 * sizeof(char));
	buff = (char *)malloc(sizeof(char) * 2);
	if (!(buff || map))
		return (NULL);
	map_flat[0] = '\0';
	zero = 1;
	while (zero != 0)
	{
		zero = read(map, buff, zero);
		buff[zero] = '\0';
		map_flat = ft_strjoin(map_flat, buff);
	}
	free(buff);
	return (map_flat);
}

char	**ft_map_to_char(int map)
{
	char	**map_plan;
	char	*map_flat;

	if (map < 0)
		exit(0);
	map_flat = get_flat(map);
	map_plan = ft_split(map_flat, '\n');
	free(map_flat);
	return (map_plan);
}
