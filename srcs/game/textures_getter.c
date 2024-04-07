/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_getter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:07:26 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:31:49 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

void	get_object_textures(t_game_info *game)
{
	game->textures->object[0]
		= mlx_load_png("./textures/objects/crystal_1.png");
	game->textures->object[1]
		= mlx_load_png("./textures/objects/crystal_2.png");
	game->textures->object[2]
		= mlx_load_png("./textures/objects/crystal_3.png");
	game->textures->object[3]
		= mlx_load_png("./textures/objects/crystal_4.png");
	game->textures->object[4]
		= mlx_load_png("./textures/objects/crystal_5.png");
	game->textures->object[5]
		= mlx_load_png("./textures/objects/crystal_6.png");
	game->textures->object[6]
		= mlx_load_png("./textures/objects/crystal_7.png");
	game->textures->object[7]
		= mlx_load_png("./textures/objects/crystal_8.png");
	game->textures->object[8]
		= mlx_load_png("./textures/objects/crystal_9.png");
	game->textures->object[9]
		= mlx_load_png("./textures/objects/crystal_10.png");
	game->textures->object[10]
		= mlx_load_png("./textures/objects/crystal_11.png");
	game->textures->object[11]
		= mlx_load_png("./textures/objects/crystal_12.png");
	get_object_textures_2(game);
}

void	get_object_textures_2(t_game_info *game)
{
	game->textures->object[12]
		= mlx_load_png("./textures/objects/crystal_13.png");
	game->textures->object[13]
		= mlx_load_png("./textures/objects/crystal_14.png");
	game->textures->object[14]
		= mlx_load_png("./textures/objects/crystal_15.png");
	game->textures->object[15]
		= mlx_load_png("./textures/objects/crystal_16.png");
	game->textures->object[16]
		= mlx_load_png("./textures/objects/crystal_17.png");
	game->textures->object[17]
		= mlx_load_png("./textures/objects/crystal_18.png");
	game->textures->object[18]
		= mlx_load_png("./textures/objects/crystal_19.png");
	game->textures->object[19]
		= mlx_load_png("./textures/objects/crystal_20.png");
	game->textures->object[20]
		= mlx_load_png("./textures/objects/crystal_21.png");
	game->textures->object[21]
		= mlx_load_png("./textures/objects/crystal_22.png");
	game->textures->object[22]
		= mlx_load_png("./textures/objects/crystal_23.png");
	game->textures->object[23]
		= mlx_load_png("./textures/objects/crystal_24.png");
}

void	get_player_textures(t_game_info *game)
{
	game->textures->player_front[0]
		= mlx_load_png("./textures/main_character/front_idle_1.png");
	game->textures->player_front[1]
		= mlx_load_png("./textures/main_character/front_idle_2.png");
	game->textures->player_front[2]
		= mlx_load_png("./textures/main_character/front_idle_3.png");
	game->textures->player_right[0]
		= mlx_load_png("./textures/main_character/right_idle_1.png");
	game->textures->player_right[1]
		= mlx_load_png("./textures/main_character/right_idle_2.png");
	game->textures->player_right[2]
		= mlx_load_png("./textures/main_character/right_idle_3.png");
	game->textures->player_back[0]
		= mlx_load_png("./textures/main_character/back_idle_1.png");
	game->textures->player_back[1]
		= mlx_load_png("./textures/main_character/back_idle_2.png");
	game->textures->player_back[2]
		= mlx_load_png("./textures/main_character/back_idle_3.png");
	game->textures->player_left[0]
		= mlx_load_png("./textures/main_character/left_idle_1.png");
	game->textures->player_left[1]
		= mlx_load_png("./textures/main_character/left_idle_2.png");
	game->textures->player_left[2]
		= mlx_load_png("./textures/main_character/left_idle_3.png");
}

void	get_enemy_textures(t_game_info *game)
{
	game->textures->enemy_front[0]
		= mlx_load_png("./textures/main_character/m_front_idle_1.png");
	game->textures->enemy_front[1]
		= mlx_load_png("./textures/main_character/m_front_idle_2.png");
	game->textures->enemy_front[2]
		= mlx_load_png("./textures/main_character/m_front_idle_3.png");
	game->textures->enemy_right[0]
		= mlx_load_png("./textures/main_character/m_right_idle_1.png");
	game->textures->enemy_right[1]
		= mlx_load_png("./textures/main_character/m_right_idle_2.png");
	game->textures->enemy_right[2]
		= mlx_load_png("./textures/main_character/m_right_idle_3.png");
	game->textures->enemy_back[0]
		= mlx_load_png("./textures/main_character/m_back_idle_1.png");
	game->textures->enemy_back[1]
		= mlx_load_png("./textures/main_character/m_back_idle_2.png");
	game->textures->enemy_back[2]
		= mlx_load_png("./textures/main_character/m_back_idle_3.png");
	game->textures->enemy_left[0]
		= mlx_load_png("./textures/main_character/m_left_idle_1.png");
	game->textures->enemy_left[1]
		= mlx_load_png("./textures/main_character/m_left_idle_2.png");
	game->textures->enemy_left[2]
		= mlx_load_png("./textures/main_character/m_left_idle_3.png");
}

void	get_exit_textures(t_game_info *game)
{
	game->textures->exit[0] = mlx_load_png("./textures/exit/exit_0.png");
	game->textures->exit[1] = mlx_load_png("./textures/exit/exit_1.png");
	game->textures->exit[2] = mlx_load_png("./textures/exit/exit_2.png");
	game->textures->exit[3] = mlx_load_png("./textures/exit/exit_3.png");
	game->textures->exit[4] = mlx_load_png("./textures/exit/exit_4.png");
	game->textures->exit[5] = mlx_load_png("./textures/exit/exit_5.png");
	game->textures->exit[6] = mlx_load_png("./textures/exit/exit_6.png");
	game->textures->exit[7] = mlx_load_png("./textures/exit/exit_7.png");
	game->textures->exit[8] = mlx_load_png("./textures/exit/exit_8.png");
	game->textures->exit[9] = mlx_load_png("./textures/exit/exit_9.png");
	game->textures->exit[10] = mlx_load_png("./textures/exit/exit_10.png");
	game->textures->exit[11] = mlx_load_png("./textures/exit/exit_11.png");
}
