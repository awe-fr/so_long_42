#include "../../headers/major.h"

void	game_loop(t_map_info *map)
{
	t_texture_info	textures;
	t_game_info 	game;
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
	return;
}

void	init_game(t_game_info *game, t_map_info *map, t_texture_info *textures, t_img_info *img)
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

	game->mlx = mlx_init((32 * map->size_x) * 2, (32 * map->size_y) * 2, "so_long", false);

	if (!game->mlx)
		mlx_fail_init(game);
	game->display = mlx_new_image(game->mlx, (SCALE * map->size_x) * 2, (SCALE * map->size_y) * 2);
	game->text_screen = mlx_put_string(game->mlx, "Step count : ", 8, 4);
	game->count_screen = mlx_put_string(game->mlx, game->count_char, 135, 5);
	get_textures(game);
}

void	key_handler(void *gam)
{
	t_game_info *game;

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

void write_step(t_game_info *game)
{
	static int	last_count = 0;

	if (last_count != game->map->move)
	{
		mlx_delete_image(game->mlx, game->count_screen);
		free(game->count_char);
		game->count_char = ft_itoa(game->map->move);
		game->count_screen = mlx_put_string(game->mlx, game->count_char, 135, 5);
		last_count = game->map->move;
	}
}

void	enemy_move(t_game_info *game, t_map_info *map)
{
	int	move;
	int	i;
	
	i = 0;
	if (game->enemy_last_move + 1 > mlx_get_time())
		return;
	game->enemy_last_move = mlx_get_time();
	while(i < map->enemy)
	{
		move = rand() % 4;
		if (move == 0)
			enemy_can_go_right(game, map, i);
		else if(move == 1)
			enemy_can_go_left(game, map, i);
		else if(move == 2)
			enemy_can_go_down(game, map, i);
		else if(move == 3)
			enemy_can_go_up(game, map, i);
		i++;
	}
}

void	enemy_can_go_right(t_game_info *game, t_map_info *map, int i)
{
	if (map->enemy_y[i] == map->exit_y && map->enemy_x[i] + 1 == map->exit_x)
		return;
	if (map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] + 1] == '0')
	{
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] + 1] = 'B';
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i]] = '0';
		map->enemy_x[i] += 1;
	}
	else if (map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] + 1] == 'P' || map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] + 1] == 'O' || map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] + 1] == 'I' || map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] + 1] == 'U')
		game_over(game, "Your died\n");
}

void	enemy_can_go_left(t_game_info *game, t_map_info *map, int i)
{
	if (map->enemy_y[i] == map->exit_y && map->enemy_x[i] - 1 == map->exit_x)
		return;
	if (map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] - 1] == '0')
	{
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] - 1] = 'V';
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i]] = '0';
		map->enemy_x[i] -= 1;
	}
	else if (map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] - 1] == 'P' || map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] - 1] == 'O' || map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] - 1] == 'I' || map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i] - 1] == 'U')
		game_over(game, "Your died\n");
}

void	enemy_can_go_down(t_game_info *game, t_map_info *map, int i)
{
	if (map->enemy_y[i] + 1 == map->exit_y && map->enemy_x[i] == map->exit_x)
		return;
	if (map->map[map->enemy_y[i] + map->start_index + 1][map->enemy_x[i]] == '0')
	{
		map->map[map->enemy_y[i] + map->start_index + 1][map->enemy_x[i]] = 'M';
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i]] = '0';
		map->enemy_y[i] += 1;
	}
	else if (map->map[map->enemy_y[i] + map->start_index + 1][map->enemy_x[i]] == 'P' || map->map[map->enemy_y[i] + map->start_index + 1][map->enemy_x[i]] == 'O' || map->map[map->enemy_y[i] + map->start_index + 1][map->enemy_x[i]] == 'I' || map->map[map->enemy_y[i] + map->start_index + 1][map->enemy_x[i]] == 'U')
		game_over(game, "Your died\n");
}

void	enemy_can_go_up(t_game_info *game, t_map_info *map, int i)
{
	if (map->enemy_y[i] - 1 == map->exit_y && map->enemy_x[i] == map->exit_x)
		return;
	if (map->map[map->enemy_y[i] + map->start_index - 1][map->enemy_x[i]] == '0')
	{
		map->map[map->enemy_y[i] + map->start_index - 1][map->enemy_x[i]] = 'N';
		map->map[map->enemy_y[i] + map->start_index][map->enemy_x[i]] = '0';
		map->enemy_y[i] -= 1;
	}
	else if (map->map[map->enemy_y[i] + map->start_index - 1][map->enemy_x[i]] == 'P' || map->map[map->enemy_y[i] + map->start_index - 1][map->enemy_x[i]] == 'O' || map->map[map->enemy_y[i] + map->start_index - 1][map->enemy_x[i]] == 'I' || map->map[map->enemy_y[i] + map->start_index - 1][map->enemy_x[i]] == 'U')
		game_over(game, "Your died\n");
}

void	game_over(t_game_info *game, char *msg)
{
	write(1, msg, ft_strlen(msg));
	free_graphics(game);
}

void	can_go_right(t_game_info *game, t_map_info *map)
{
	if (game->move_right == false)
		return;
	if(map->map[map->player_y + map->start_index][map->player_x + 1] == 'E' && map->objects == 0)
		game_over(game, "You finish the Game\n");
	if(map->map[map->player_y + map->start_index][map->player_x + 1] == '0' || map->map[map->player_y + map->start_index][map->player_x + 1] == 'E')
	{
		map->map[map->player_y + map->start_index][map->player_x + 1] = 'I';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_x += 1;
	}
	else if(map->map[map->player_y + map->start_index][map->player_x + 1] == 'C')
	{
		map->map[map->player_y + map->start_index][map->player_x + 1] = 'I';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_x += 1;
		map->objects -= 1;
		if (map->objects == 0)
			map->map[map->exit_y + map->start_index][map->exit_x] = 'E';
	}
	else if(map->map[map->player_y + map->start_index][map->player_x + 1] == '1')
		map->map[map->player_y + map->start_index][map->player_x] = 'I';
	else if(map->map[map->player_y + map->start_index][map->player_x + 1] == 'M' || map->map[map->player_y + map->start_index][map->player_x + 1] == 'N' || map->map[map->player_y + map->start_index][map->player_x + 1] == 'B' || map->map[map->player_y + map->start_index][map->player_x + 1] == 'V')
		game_over(game, "Your died\n");
	map->move++;
	game->move_right = false;
}

void	can_go_down(t_game_info *game, t_map_info *map)
{
	if (game->move_down == false)
		return;
	if((map->map[map->player_y + map->start_index + 1][map->player_x] == 'E' && map->objects == 0))
		game_over(game, "You finish the Game\n");
	if(map->map[map->player_y + map->start_index + 1][map->player_x] == '0' || map->map[map->player_y + map->start_index + 1][map->player_x] == 'E')
	{
		map->map[map->player_y + map->start_index + 1][map->player_x] = 'P';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_y += 1;
	}
	else if(map->map[map->player_y + map->start_index + 1][map->player_x] == 'C')
	{
		map->map[map->player_y + map->start_index + 1][map->player_x] = 'P';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_y += 1;
		map->objects -= 1;
		if (map->objects == 0)
			map->map[map->exit_y + map->start_index][map->exit_x] = 'E';
	}
	else if(map->map[map->player_y + map->start_index + 1][map->player_x] == '1')
		map->map[map->player_y + map->start_index][map->player_x] = 'P';
	else if(map->map[map->player_y + map->start_index + 1][map->player_x] == 'M', map->map[map->player_y + map->start_index + 1][map->player_x] == 'N' || map->map[map->player_y + map->start_index + 1][map->player_x] == 'B' || map->map[map->player_y + map->start_index + 1][map->player_x] == 'V')
		game_over(game, "Your died\n");
	map->move++;
	game->move_down = false;
}

void	can_go_left(t_game_info *game, t_map_info *map)
{
	if (game->move_left == false)
		return;
	if(map->map[map->player_y + map->start_index][map->player_x - 1] == 'E' && map->objects == 0)
		game_over(game, "You finish the Game\n");
	if(map->map[map->player_y + map->start_index][map->player_x - 1] == '0' || map->map[map->player_y + map->start_index][map->player_x - 1] == 'E')
	{
		map->map[map->player_y + map->start_index][map->player_x - 1] = 'U';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_x -= 1;
	}
	else if(map->map[map->player_y + map->start_index][map->player_x - 1] == 'C')
	{
		map->map[map->player_y + map->start_index][map->player_x - 1] = 'U';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_x -= 1;
		map->objects -= 1;
		if (map->objects == 0)
			map->map[map->exit_y + map->start_index][map->exit_x] = 'E';
	}
	else if(map->map[map->player_y + map->start_index][map->player_x - 1] == '1')
		map->map[map->player_y + map->start_index][map->player_x] = 'U';
	else if(map->map[map->player_y + map->start_index][map->player_x - 1] == 'M' || map->map[map->player_y + map->start_index][map->player_x - 1] == 'N' || map->map[map->player_y + map->start_index][map->player_x - 1] == 'B' || map->map[map->player_y + map->start_index][map->player_x - 1] == 'V')
		game_over(game, "Your died\n");
	map->move++;
	game->move_left = false;
}

void	can_go_up(t_game_info *game, t_map_info *map)
{
	if (game->move_up == false)
		return;
	if(map->map[map->player_y + map->start_index - 1][map->player_x] == 'E' && map->objects == 0)
		game_over(game, "You finish the Game\n");
	if(map->map[map->player_y + map->start_index - 1][map->player_x] == '0' || map->map[map->player_y + map->start_index - 1][map->player_x] == 'E')
	{
		map->map[map->player_y + map->start_index - 1][map->player_x] = 'O';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_y -= 1;
	}
	else if(map->map[map->player_y + map->start_index - 1][map->player_x] == 'C')
	{
		map->map[map->player_y + map->start_index - 1][map->player_x] = 'O';
		map->map[map->player_y + map->start_index][map->player_x] = '0';
		map->player_y -= 1;
		map->objects -= 1;
		if (map->objects == 0)
			map->map[map->exit_y + map->start_index][map->exit_x] = 'E';

	}
	else if(map->map[map->player_y + map->start_index - 1][map->player_x] == '1')
		map->map[map->player_y + map->start_index][map->player_x] = 'O';
	else if(map->map[map->player_y + map->start_index - 1][map->player_x] == 'M' || map->map[map->player_y + map->start_index - 1][map->player_x] == 'N' || map->map[map->player_y + map->start_index - 1][map->player_x] == 'B' || map->map[map->player_y + map->start_index - 1][map->player_x] == 'V')
		game_over(game, "Your died\n");
	map->move++;
	game->move_up = false;
}

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
	else if (game->map->map[i][j] == 'P' || game->map->map[i][j] == 'O' || game->map->map[i][j] == 'I' || game->map->map[i][j] == 'U')
		what_put_player(game, i, j);
	else if (game->map->map[i][j] == 'M' || game->map->map[i][j] == 'N' || game->map->map[i][j] == 'B' || game->map->map[i][j] == 'V')
		what_put_enemy(game, i, j);
	else if (game->map->map[i][j] == 'C')
		print_tiles(game, game->img->object, 24, coor);
	else if (game->map->map[i][j] == 'E')
		print_tiles(game, game->img->exit, 12, coor);
}

void	what_put_player(t_game_info *game, int i, int j)
{
	int	coor[2];

	coor[0] = i - game->map->start_index;
	coor[1] = j;
	if (game->map->map[i][j] == 'P')
		print_tiles(game, game->img->player_front, 3, coor);
	else if (game->map->map[i][j] == 'O')
		print_tiles(game, game->img->player_back, 3, coor);
	else if (game->map->map[i][j] == 'I')
		print_tiles(game, game->img->player_right, 3, coor);
	else if (game->map->map[i][j] == 'U')
		print_tiles(game, game->img->player_left, 3, coor);
}

void	what_put_enemy(t_game_info *game, int i, int j)
{
	int	coor[2];

	coor[0] = i - game->map->start_index;
	coor[1] = j;
	if (game->map->map[i][j] == 'M')
		print_tiles(game, game->img->enemy_front, 3, coor);
	else if (game->map->map[i][j] == 'N')
		print_tiles(game, game->img->enemy_back, 3, coor);
	else if (game->map->map[i][j] == 'B')
		print_tiles(game, game->img->enemy_right, 3, coor);
	else if (game->map->map[i][j] == 'V')
		print_tiles(game, game->img->enemy_left, 3, coor);
}

void	print_tiles(t_game_info *game, unsigned long ***tiles, int nb_frame, int *coor)
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