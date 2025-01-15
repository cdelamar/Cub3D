#include "cub3d.h"

void	error_free(t_game *game)
{
	free_textures(game);
	mlx_destroy_display(game->mlx);
	ft_freetab(game->map);
	free_path_textures(game);
	free(game->mlx);
	free(game);
	exit(0);
}

void	error_pos(t_game *game, char **bigmap)
{
	int	y;

	y = 0;
	free_game(game);
	while (bigmap[y])
	{
		free(bigmap[y]);
		y++;
	}
	free(bigmap);
	free(game);
	exit(0);
}

void	error_mlx(t_game *game)
{
	ft_putendl_fd("Error\nMiniLibX initialization failed", 2);
	free_game(game);
	free(game);
	exit(0);
}

void	error_win(t_game *game)
{
	ft_putendl_fd("Error\nWindow creation failed", 2);
	free_game(game);
	free(game);
	exit(0);
}
