/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:55:07 by srajaoui          #+#    #+#             */
/*   Updated: 2023/07/05 16:27:16 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

void	full_free(t_game *game)
{
	free_all(game->map);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->obj);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_window(game->mlx , game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (0);
}
