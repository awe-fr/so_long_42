/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:35:07 by srajaoui          #+#    #+#             */
/*   Updated: 2023/06/22 17:37:42 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

void	flood_fill(char **map, int j, int i, int save_c)
{
	find_p(map, &j, &i);
	livai(map, j, i);
	ft_check_field(map, j, i, save_c);
}

void	find_p(char **map, int *j, int *i)
{
	while (map[*j])
	{
		(*i) = 0;
		while (map[*j][*i])
		{
			if (map[*j][*i] == 'P')
				break ;
			++(*i);
		}
		if (map[*j][*i] == 'P')
			break ;
		++(*j);
	}
}

void	livai(char **map, int j, int i)
{
	change_char(map, j, i);
	if (map[j][i + 1] == '0' || map[j][i + 1] == 'P' ||
		map[j][i + 1] == 'C' || map[j][i + 1] == 'E')
	{
		i++;
		livai(map, j, i);
	}
	if (map[j][i - 1] == '0' || map[j][i - 1] == 'P' ||
		map[j][i - 1] == 'C' || map[j][i - 1] == 'E')
	{
		i--;
		livai(map, j, i);
	}
	if (map[j + 1][i] == '0' || map[j + 1][i] == 'P' ||
		map[j + 1][i] == 'C' || map[j + 1][i] == 'E')
	{
		j++;
		livai(map, j, i);
	}
	if (map[j - 1][i] == '0' || map[j - 1][i] == 'P' ||
		map[j - 1][i] == 'C' || map[j - 1][i] == 'E')
	{
		j--;
		livai(map, j, i);
	}
}

void	change_char(char **map, int j, int i)
{
	if (map[j][i] == '0')
		map[j][i] = '2';
	else if (map[j][i] == 'P')
		map[j][i] = 'p';
	else if (map[j][i] == 'C')
		map[j][i] = 'c';
	else if (map[j][i] == 'E')
		map[j][i] = 'e';
}

void	ft_check_field(char **map, int j, int i, int save_c)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'p')
				p++;
			else if (map[j][i] == 'c')
				c++;
			else if (map[j][i] == 'e')
				e++;
			i++;
		}
		j++;
	}
	if (p != 1 || c != save_c || e != 1)
		wrong_map(map);
}
