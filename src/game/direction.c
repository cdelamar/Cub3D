#include "cub3d.h"

static void	set_north(t_game *game)
{
	game->player.dir_x = 0;
	game->player.dir_y = -1;
	game->ray.plane_x = 0.66;
	game->ray.plane_y = 0;
}

static void	set_south(t_game *game)
{
	game->player.dir_x = 0;
	game->player.dir_y = 1;
	game->ray.plane_x = -0.66;
	game->ray.plane_y = 0;
}

static void	set_east(t_game *game)
{
	game->player.dir_x = 1;
	game->player.dir_y = 0;
	game->ray.plane_x = 0;
	game->ray.plane_y = 0.66;
}

static void	set_west(t_game *game)
{
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->ray.plane_x = 0;
	game->ray.plane_y = -0.66;
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
