#include "cub3d.h"

void init_player(t_player *player)
{
	player->posX = 22;
	player->posY = 12;
	player->dirX = -1;
	player->dirY = 0;
	player->planeX = 0;
	player->planeY = 0.66;
	player->time = 0;
	player->old_time = 0;
	player->camX = 0;
	player->rayX = 0;
	player->rayY = 0;
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
	t_game		*game;
	t_player 	*player;
	game = malloc(sizeof(t_game));
	player = malloc(sizeof(t_player));
	if (!game || !player)
	{
		ft_putendl_fd("Error\nMemory allocation failed", 2);
		return (EXIT_FAILURE);
	}

	init_game(game);
	init_player(player);
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
		ft_mlx(game, player);
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