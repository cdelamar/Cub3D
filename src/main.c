#include "cub3d.h"

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
}

void free_game(t_game *game)
{
    if (game->textures.north)
		free(game->textures.north);
    if (game->textures.south)
		free(game->textures.south);
    if (game->textures.west)
		free(game->textures.west);
    if (game->textures.east)
		free(game->textures.east);
    // ajouter plus tard
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

  printf("north : %s\n", game->textures.north);
  printf("south : %s\n", game->textures.south);
  printf("east : %s\n", game->textures.east);
  printf("west : %s\n", game->textures.west);
  printf("floor : ");
  print_int_array(game->floor_color, 3);
  printf("ceiling : ");
  print_int_array(game->ceiling_color, 3);

	free_game(game);
	free(game);
  printf("ok\n");
	return (EXIT_SUCCESS);
}