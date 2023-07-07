/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:08:39 by srajaoui          #+#    #+#             */
/*   Updated: 2023/07/05 11:26:18 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

void	count_c(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	game->c_number = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (game->map[a][b] == 'c' ||
			game->map[a][b] == 'C')
				game->c_number += 1;
			b++;
		}
		a++;
	}
}
