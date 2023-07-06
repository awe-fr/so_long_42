/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_correct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:44:20 by srajaoui          #+#    #+#             */
/*   Updated: 2023/06/21 16:04:16 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

void	ft_check_correct(char **map)
{
	int	i;
	int	j;
	int	save_c;

	i = 0;
	j = 0;
	save_c = ft_check_elements(map, j, i);
	ft_check_rectangle(map, j);
	ft_is_close(map, j, i);
	flood_fill(map, j, i, save_c);
}

int	ft_check_elements(char **map, int j, int i)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				p++;
			else if (map[j][i] == 'C')
				c++;
			else if (map[j][i] == 'E')
				e++;
			i++;
		}
		j++;
	}
	if (p != 1 || c == 0 || e != 1)
		wrong_map(map);
	return (c);
}

void	ft_check_rectangle(char **map, int j)
{
	int	len;
	int	temp;

	temp = 0;
	len = 0;
	len = ft_strlen(map[j]);
	while (map[j])
	{
		temp = ft_strlen(map[j]);
		if (temp != len)
			wrong_map(map);
		j++;
	}
}

void	ft_is_close_startend(char **map, int j, int i, int lenj)
{
	if (j == 0 || j == (lenj - 1))
	{
		while (map[j][i])
		{
			if (map[j][i] != '1')
				wrong_map(map);
			i++;
		}
	}
	return ;
}

void	ft_is_close(char **map, int j, int i)
{
	int	len;
	int	lenj;

	lenj = 0;
	while (map[lenj])
		lenj++;
	while (map[j])
	{
		len = ft_strlen(map[j]);
		i = 0;
		ft_is_close_startend(map, j, i, lenj);
		if (map[j][0] != '1' || map[j][len - 1] != '1')
			wrong_map(map);
		j++;
	}
}
