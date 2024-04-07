/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 01:53:09 by srajaoui          #+#    #+#             */
/*   Updated: 2024/04/07 02:23:12 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/major.h"

void	game_loop(t_map_info *map)
{
	t_texture_info	textures;
	t_game_info		game;
	t_img_info		img;

	init_game(&game, map, &textures, &img);
	start_print(&game);
	mlx_image_to_window(game.mlx, game.display, 0, 0);
	mlx_image_to_window(game.mlx, game.count_screen, 135, 5);
	mlx_image_to_window(game.mlx, game.text_screen, 8, 4);
	mlx_set_icon(game.mlx, game.textures->player_front[0]);
	mlx_loop_hook(game.mlx, key_handler, &game);
	mlx_loop(game.mlx);
	game_over(&game, "See you later\n");
	return ;
}

void	init_game(t_game_info *game, t_map_info *map, t_texture_info *textures,
	t_img_info *img)
{
	srand(time(NULL));
	game->textures = textures;
	game->img = img;
	game->map = map;
	game->enemy_last_move = 0;
	game->move_right = true;
	game->move_down = true;
	game->move_left = true;
	game->move_up = true;
	game->count_char = ft_itoa(map->move);
	game->mlx = mlx_init((SCALE * map->size_x) * 2, (SCALE * map->size_y)
			* 2, "so_long", false);
	if (!game->mlx)
		mlx_fail_init(game);
	game->display = mlx_new_image(game->mlx, (SCALE * map->size_x) * 2,
			(SCALE * map->size_y) * 2);
	game->text_screen = mlx_put_string(game->mlx, "Step count : ", 8, 4);
	game->count_screen = mlx_put_string(game->mlx, game->count_char, 135, 5);
	get_textures(game);
}

void	key_handler(void *gam)
{
	t_game_info	*game;

	game = gam;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		game_over(game, "See you later\n");
	if (game->map->enemy != 0)
		enemy_move(game, game->map);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		can_go_down(game, game->map);
	else
		game->move_down = true;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		can_go_right(game, game->map);
	else
		game->move_right = true;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		can_go_left(game, game->map);
	else
		game->move_left = true;
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		can_go_up(game, game->map);
	else
		game->move_up = true;
	write_step(game);
	start_print(game);
}

void	game_over(t_game_info *game, char *msg)
{
	write(1, msg, ft_strlen(msg));
	free_graphics(game);
}
