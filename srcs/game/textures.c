#include "../../headers/major.h"

unsigned long	creatergba(int r, int g, int b, int a)
{
	return (((r & 0xff) << 24) + ((g & 0xff) << 16)
		+ ((b & 0xff) << 8) + (a & 0xff));
}

void	get_textures(t_game_info *game)
{
	game->textures->floor[0] = mlx_load_png("./textures/map/floor.png");
	game->textures->wall[0] = mlx_load_png("./textures/map/wall.png");
	get_player_textures(game);
	get_enemy_textures(game);
	get_object_textures(game);
	get_exit_textures(game);
	alloc_textures(game);
	assign_texture(game->textures->floor[0], game->img->floor[0]);
	assign_texture(game->textures->wall[0], game->img->wall[0]);
	assign_texture_player(game);
	assign_texture_object(game);
	assign_texture_enemy(game);
	assign_texture_exit(game);
}

void	alloc_textures(t_game_info *game)
{
	game->img->player_front = alloc_int_tab(game->img->player_front, 3);
	game->img->player_right = alloc_int_tab(game->img->player_right, 3);
	game->img->player_back = alloc_int_tab(game->img->player_back, 3);
	game->img->player_left = alloc_int_tab(game->img->player_left, 3);
	game->img->enemy_front = alloc_int_tab(game->img->enemy_front, 3);
	game->img->enemy_right = alloc_int_tab(game->img->enemy_right, 3);
	game->img->enemy_back = alloc_int_tab(game->img->enemy_back, 3);
	game->img->enemy_left = alloc_int_tab(game->img->enemy_left, 3);
	game->img->object = alloc_int_tab(game->img->object, 24);
	game->img->exit = alloc_int_tab(game->img->exit, 12);
	game->img->floor = alloc_int_tab(game->img->floor, 1);
	game->img->wall = alloc_int_tab(game->img->wall, 1);
}

unsigned long ***alloc_int_tab(unsigned long ***img, int size)
{
	int	i;
	int	j;

	i = 0;
	img = malloc(size * sizeof(unsigned long int **));
	while(i < size)
	{
		j = 0;
		img[i] = malloc(TEXTURE_SCALE * sizeof(unsigned long int *));
		while(j < TEXTURE_SCALE)
		{
			img[i][j] = malloc(TEXTURE_SCALE * sizeof(unsigned long int));
			j++;
		}
		i++;
	}
	return (img);
}

void	assign_texture_player(t_game_info *game)
{
	int	i;

	i = -1;
	while (++i < 3)
		assign_texture(game->textures->player_front[i], game->img->player_front[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->player_right[i], game->img->player_right[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->player_back[i], game->img->player_back[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->player_left[i], game->img->player_left[i]);
}

void	assign_texture_enemy(t_game_info *game)
{
	int	i;

	i = -1;
	while (++i < 3)
		assign_texture(game->textures->enemy_front[i], game->img->enemy_front[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->enemy_right[i], game->img->enemy_right[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->enemy_back[i], game->img->enemy_back[i]);
	i = -1;
	while (++i < 3)
		assign_texture(game->textures->enemy_left[i], game->img->enemy_left[i]);
}

void	assign_texture_object(t_game_info *game)
{
	int	i;

	i = -1;
	while (++i < 24)
		assign_texture(game->textures->object[i], game->img->object[i]);
}

void	assign_texture_exit(t_game_info *game)
{
	int	i;

	i = -1;
	while (++i < 12)
		assign_texture(game->textures->exit[i], game->img->exit[i]);
}

void	assign_texture(mlx_texture_t *texture, unsigned long **img)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while(i < TEXTURE_SCALE)
	{
		j = 0;
		while(j < TEXTURE_SCALE)
		{	
			img[i][j] = creatergba((int)texture->pixels[x], (int)texture->pixels[x + 1], (int)texture->pixels[x + 2], (int)texture->pixels[x + 3]);
			j++;
			x += 4;
		}
		i++;
	}
}

void	get_object_textures(t_game_info *game)
{
	game->textures->object[0] = mlx_load_png("./textures/objects/crystal_1.png");
	game->textures->object[1] = mlx_load_png("./textures/objects/crystal_2.png");
	game->textures->object[2] = mlx_load_png("./textures/objects/crystal_3.png");
	game->textures->object[3] = mlx_load_png("./textures/objects/crystal_4.png");
	game->textures->object[4] = mlx_load_png("./textures/objects/crystal_5.png");
	game->textures->object[5] = mlx_load_png("./textures/objects/crystal_6.png");
	game->textures->object[6] = mlx_load_png("./textures/objects/crystal_7.png");
	game->textures->object[7] = mlx_load_png("./textures/objects/crystal_8.png");
	game->textures->object[8] = mlx_load_png("./textures/objects/crystal_9.png");
	game->textures->object[9] = mlx_load_png("./textures/objects/crystal_10.png");
	game->textures->object[10] = mlx_load_png("./textures/objects/crystal_11.png");
	game->textures->object[11] = mlx_load_png("./textures/objects/crystal_12.png");
	game->textures->object[12] = mlx_load_png("./textures/objects/crystal_13.png");
	game->textures->object[13] = mlx_load_png("./textures/objects/crystal_14.png");
	game->textures->object[14] = mlx_load_png("./textures/objects/crystal_15.png");
	game->textures->object[15] = mlx_load_png("./textures/objects/crystal_16.png");
	game->textures->object[16] = mlx_load_png("./textures/objects/crystal_17.png");
	game->textures->object[17] = mlx_load_png("./textures/objects/crystal_18.png");
	game->textures->object[18] = mlx_load_png("./textures/objects/crystal_19.png");
	game->textures->object[19] = mlx_load_png("./textures/objects/crystal_20.png");
	game->textures->object[20] = mlx_load_png("./textures/objects/crystal_21.png");
	game->textures->object[21] = mlx_load_png("./textures/objects/crystal_22.png");
	game->textures->object[22] = mlx_load_png("./textures/objects/crystal_23.png");
	game->textures->object[23] = mlx_load_png("./textures/objects/crystal_24.png");
}

void	get_player_textures(t_game_info *game)
{
	game->textures->player_front[0] = mlx_load_png("./textures/main_character/front_idle_1.png");
	game->textures->player_front[1] = mlx_load_png("./textures/main_character/front_idle_2.png");
	game->textures->player_front[2] = mlx_load_png("./textures/main_character/front_idle_3.png");
	game->textures->player_right[0] = mlx_load_png("./textures/main_character/right_idle_1.png");
	game->textures->player_right[1] = mlx_load_png("./textures/main_character/right_idle_2.png");
	game->textures->player_right[2] = mlx_load_png("./textures/main_character/right_idle_3.png");
	game->textures->player_back[0] = mlx_load_png("./textures/main_character/back_idle_1.png");
	game->textures->player_back[1] = mlx_load_png("./textures/main_character/back_idle_2.png");
	game->textures->player_back[2] = mlx_load_png("./textures/main_character/back_idle_3.png");
	game->textures->player_left[0] = mlx_load_png("./textures/main_character/left_idle_1.png");
	game->textures->player_left[1] = mlx_load_png("./textures/main_character/left_idle_2.png");
	game->textures->player_left[2] = mlx_load_png("./textures/main_character/left_idle_3.png");
}

void	get_enemy_textures(t_game_info *game)
{
	game->textures->enemy_front[0] = mlx_load_png("./textures/main_character/m_front_idle_1.png");
	game->textures->enemy_front[1] = mlx_load_png("./textures/main_character/m_front_idle_2.png");
	game->textures->enemy_front[2] = mlx_load_png("./textures/main_character/m_front_idle_3.png");
	game->textures->enemy_right[0] = mlx_load_png("./textures/main_character/m_right_idle_1.png");
	game->textures->enemy_right[1] = mlx_load_png("./textures/main_character/m_right_idle_2.png");
	game->textures->enemy_right[2] = mlx_load_png("./textures/main_character/m_right_idle_3.png");
	game->textures->enemy_back[0] = mlx_load_png("./textures/main_character/m_back_idle_1.png");
	game->textures->enemy_back[1] = mlx_load_png("./textures/main_character/m_back_idle_2.png");
	game->textures->enemy_back[2] = mlx_load_png("./textures/main_character/m_back_idle_3.png");
	game->textures->enemy_left[0] = mlx_load_png("./textures/main_character/m_left_idle_1.png");
	game->textures->enemy_left[1] = mlx_load_png("./textures/main_character/m_left_idle_2.png");
	game->textures->enemy_left[2] = mlx_load_png("./textures/main_character/m_left_idle_3.png");
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