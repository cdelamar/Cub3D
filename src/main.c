#include "cub3d.h"

int main (int argc, char **argv)
{
	t_game		*game;
	t_player 	*player;
	t_ray		*ray;
	game = malloc(sizeof(t_game));
	player = malloc(sizeof(t_player));
	ray = malloc(sizeof(t_ray));
	if (!game || !player)
	{
		ft_putendl_fd("Error\nMemory allocation failed", 2);
		return (EXIT_FAILURE);
	}

	init_game(game);
	init_player(player);
	init_ray(ray);

	printf("%f player\n", player->dirX);

	if(parsing(argc, argv, game) == false)
	{
		free_game(game);
		free(game);
		free(player);
		return(EXIT_FAILURE);
	}

	else
	{
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
		ft_mlx(game, player, ray);
	}

	free_game(game);
	free(game);
	free(player);
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