#include "cub3d.h"

static void	set_north(t_game *game)
{
	game->player.dirX = 0;
	game->player.dirY = -1;
	game->ray.planeX = 0.66;
	game->ray.planeY = 0;
}

static void	set_south(t_game *game)
{
	game->player.dirX = 0;
	game->player.dirY = 1;
	game->ray.planeX = -0.66;
	game->ray.planeY = 0;
}

static void	set_east(t_game *game)
{
	game->player.dirX = 1;
	game->player.dirY = 0;
	game->ray.planeX = 0;
	game->ray.planeY = 0.66;
}

static void	set_west(t_game *game)
{
	game->player.dirX = -1;
	game->player.dirY = 0;
	game->ray.planeX = 0;
	game->ray.planeY = -0.66;
}

void	set_player_direction(t_game *game, char spawn)
{
	if (spawn == 'N')
		set_north(game);
	else if (spawn == 'S')
		set_south(game);
	else if (spawn == 'E')
		set_east(game);
	else if (spawn == 'W')
		set_west(game);
}