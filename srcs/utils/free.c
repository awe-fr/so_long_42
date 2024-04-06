#include "../../headers/major.h"

void	map_free(t_map_info *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
	if (map->map_flat)
		free(map->map_flat);
	i = 0;
	while (i < map->enemy)
	{
		map->enemy_y[i];
		map->enemy_x[i++];
	}
	close(map->map_file);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_graphics(t_game_info *game)
{
	map_free(game->map);
	mlx_delete_image(game->mlx, game->count_screen);
	mlx_delete_image(game->mlx, game->text_screen);
	mlx_delete_image(game->mlx, game->display);
	free_img(game->textures);
	free_texture(game->img->player_front, 3, TEXTURE_SCALE);
	free_texture(game->img->player_right, 3, TEXTURE_SCALE);
	free_texture(game->img->player_back, 3, TEXTURE_SCALE);
	free_texture(game->img->player_left, 3, TEXTURE_SCALE);
	free_texture(game->img->enemy_front, 3, TEXTURE_SCALE);
	free_texture(game->img->enemy_right, 3, TEXTURE_SCALE);
	free_texture(game->img->enemy_back, 3, TEXTURE_SCALE);
	free_texture(game->img->enemy_left, 3, TEXTURE_SCALE);
	free_texture(game->img->object, 24, TEXTURE_SCALE);
	free_texture(game->img->exit, 12, TEXTURE_SCALE);
	free_texture(game->img->floor, 1, TEXTURE_SCALE);
	free_texture(game->img->wall, 1, TEXTURE_SCALE);
	free(game->map->enemy_y);
	free(game->map->enemy_x);
	if (game->count_char)
		free(game->count_char);
	mlx_terminate(game->mlx);
	exit(0);
}

void	free_img(t_texture_info *imgs)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		mlx_delete_texture(imgs->player_front[i]);
		mlx_delete_texture(imgs->player_right[i]);
		mlx_delete_texture(imgs->player_left[i]);
		mlx_delete_texture(imgs->player_back[i]);
		mlx_delete_texture(imgs->enemy_front[i]);
		mlx_delete_texture(imgs->enemy_right[i]);
		mlx_delete_texture(imgs->enemy_left[i]);
		mlx_delete_texture(imgs->enemy_back[i]);
		i++;
	}
	i = 0;
	while (i < 24)
		mlx_delete_texture(imgs->object[i++]);
	i = 0;
	while (i < 12)
		mlx_delete_texture(imgs->exit[i++]);
	mlx_delete_texture(imgs->floor[0]);
	mlx_delete_texture(imgs->wall[0]);
}

void	free_texture(unsigned long ***texture, int z, int y)
{
	y--;
	z--;
	if (texture)
	{
		while (z > -1)
		{
			y = TEXTURE_SCALE - 1;
			while (y > -1)
			{
				free(texture[z][y]);
				y--;
			}
			free(texture[z]);
			z--;
		}
		free(texture);
	}
}
