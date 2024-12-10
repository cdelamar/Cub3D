#include "cub3d.h"

int mlx_quit(t_game *game)
{
	printf("test %s", game->file_name);
	close_mlx(game);
	return (EXIT_SUCCESS);
}

void	ft_mlx(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, &player_controls, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_mlx, game);
	mlx_hook(game->win, 17, StructureNotifyMask, &mlx_quit, game);
	//mlx_hook(game->win, 65307, KeyPressMask, ft_quit, game);
	mlx_loop(game->mlx);
}

void init_game(t_game *game)
{
	game->textures.north = NULL;
	game->textures.south = NULL;
	game->textures.west = NULL;
	game->textures.east = NULL;
	game->floor_color[0] = -1;
	game->floor_color[1] = -1;
	game->floor_color[2] = -1;
	game->ceiling_color[0] = -1;
	game->ceiling_color[1] = -1;
	game->ceiling_color[2] = -1;
	game->map = NULL;
	game->map_buffer = NULL;
	game->mlx = NULL;
}

int main (int argc, char **argv)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putendl_fd("Error\nMemory allocation failed", 2);
		return (EXIT_FAILURE);
	}
	init_game(game);
	if(parsing(argc, argv, game) == false)
	{
		free_game(game);
		free(game);
		return(EXIT_FAILURE);
	}

	else
	{
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, 900, 650, "Cub3D");
		ft_mlx(game);
	}

	free_game(game);
	free(game);
	return (EXIT_SUCCESS);
}

	// printf("north : %s\n", game->textures.north);
	// printf("south : %s\n", game->textures.south);
	// printf("east : %s\n", game->textures.east);
	// printf("west : %s\n", game->textures.west);
	// printf("floor : ");
	// print_int_array(game->floor_color, 3);
	// printf("ceiling : ");
	// print_int_array(game->ceiling_color, 3);
	// printf("map :\n\n");
	// print_char_array(game->map);