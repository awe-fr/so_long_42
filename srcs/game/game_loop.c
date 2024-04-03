#include "../../headers/major.h"

void	game_loop(t_map_info *map)
{
	t_texture_info	textures;
	t_game_info 	game;
	t_img_info		img;

	game.textures = &textures;
	game.img = &img;
	game.map = map;
	game.mlx = mlx_init((SCALE * map->size_x) * 2, (SCALE * map->size_y) * 2, "so_long", false);
	if (!game.mlx)
		mlx_fail_init(&game);
	game.display = mlx_new_image(game.mlx, (SCALE * map->size_x) * 2, (SCALE * map->size_y) * 2);
	get_textures(&game);
	start_print(&game);
	mlx_image_to_window(game.mlx, game.display, 0, 0);
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
	start_print(game);
}

// void	get_img(t_game_info *game)
// {
// 	get_player_img(game);
// 	get_object_img(game);
// 	game->img->floor = mlx_texture_to_image(game->mlx, game->textures->floor);
// 	game->img->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
// }

void	start_print(t_game_info *game)
{
	int	i;
	int	j;

	i = game->map->start_index;
	while(i < game->map->start_index + game->map->size_y)
	{
		j = 0;
		while(j < game->map->size_x)
		{
			what_put(game, i, j);
			j++;
		}
		i++;
	}
}

void	what_put(t_game_info *game, int i, int j)
{
	int	coor[2];

	coor[0] = i - game->map->start_index;
	coor[1] = j;
	if (game->map->map[i][j] == '1')
		print_tiles(game, game->img->wall, 1, coor);
	else if (game->map->map[i][j] == '0')
		print_tiles(game, game->img->floor, 1, coor);
	else if (game->map->map[i][j] == 'P')
		print_tiles(game, game->img->player_front, 3, coor);
	else if (game->map->map[i][j] == 'M')
		print_tiles(game, game->img->enemy_front, 3, coor);
	else if (game->map->map[i][j] == 'C')
		print_tiles(game, game->img->object, 24, coor);
	else if (game->map->map[i][j] == 'E')
		print_tiles(game, game->img->exit, 12, coor);
}

void	print_tiles(t_game_info *game, unsigned long int ***tiles, int nb_frame, int *coor)
{
	int	frame;
	int	i;
	int	j;

	frame = 0;
	i = 0;
	if (nb_frame != 1)
		frame = find_frame(game, tiles, nb_frame);
	while(i < TEXTURE_SCALE)
	{
		j = 0;
		while(j < TEXTURE_SCALE)
		{
			mlx_put_pixel(game->display, j * 2 + (coor[1] * SCALE * 2), i * 2 + (coor[0] * SCALE * 2), tiles[frame][i][j]);
			mlx_put_pixel(game->display, j * 2 + 1 + (coor[1] * SCALE * 2), i * 2 + (coor[0] * SCALE * 2), tiles[frame][i][j]);
			mlx_put_pixel(game->display, j * 2 + (coor[1] * SCALE * 2), i * 2 + 1 + (coor[0] * SCALE * 2), tiles[frame][i][j]);
			mlx_put_pixel(game->display, j * 2 + 1 + (coor[1] * SCALE * 2), i * 2 + 1 + (coor[0] * SCALE * 2), tiles[frame][i][j]);
			j++;
		}
		i++;
	}
}

int find_frame(t_game_info *game, unsigned long ***tiles, int nb_frame)
{
	double	select;
	double	rest;

	if (tiles == game->img->exit && game->map->objects != 0)
		return 0;
	else if (tiles == game->img->exit)
		nb_frame--;
	select = mlx_get_time();
	if (nb_frame >= 20){
		rest = select - (int)select;
		select = (int)select % 3;
		select += rest;
		select *= nb_frame / 3;
	}
	else{
		select -= (int)select;
		select *= nb_frame;
	}
	if (tiles == game->img->exit)
		return (select + 1);
	return select;
}