/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:29:03 by srajaoui          #+#    #+#             */
/*   Updated: 2023/07/07 14:46:29 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

void	moove_count(t_game *game)
{
	game->moove_count += 1;
	int_to_print(game->moove_count);
}

void	int_to_print(int moove_count)
{
	int		modulo;
	char	buff[10];
	int		a;

	a = 0;
	if (moove_count == 0)
	{
		write(1, "0", 1);
	}
	while (moove_count != 0)
	{
		modulo = moove_count % 10;
		moove_count = moove_count / 10;
		buff[a++] = "0123456789"[modulo];
	}
	while (--a >= 0)
	{
		write (1, &buff[a], 1);
	}
	write(1, "\n", 1);
}
