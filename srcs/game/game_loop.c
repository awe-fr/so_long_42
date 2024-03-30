#include "../../headers/major.h"

void	game_loop(t_map_info *map)
{
	t_game_info game;

	game.map = map;
	game.mlx = mlx_init((SCALE * map->size_x), (SCALE * map->size_y), "so_long", false);
	if (!game.mlx)
		mlx_fail_init(&game);
	// game.img = mlx_new_image(game.mlx, (SCALE * map->player_x), (SCALE * map->player_y));
	// if (!game.img || (mlx_image_to_window(game.mlx, game.img, 0, 0) < 0))
	//     mlx_fail_init();
	mlx_loop_hook(game.mlx, key_handler, &game);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return;
}

void	key_handler(void *gam)
{
	t_game_info *game;

	game = gam;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		free_graphics(game);

}