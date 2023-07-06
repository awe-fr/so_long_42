/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_mouve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:23:30 by srajaoui          #+#    #+#             */
/*   Updated: 2023/07/01 16:23:33 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_header.h"

int	code_mouve(int keycode, t_game *game)
{
	if (keycode == 119)
		can_go_up(game);
	else if (keycode == 100)
		can_go_right(game);
	else if (keycode == 97)
		can_go_left(game);
	else if (keycode == 115)
		can_go_down(game);
	else if (keycode == 65307)
		esc_exit(keycode, game);
}
