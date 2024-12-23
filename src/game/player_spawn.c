#include "cub3d.h"

static int	set_spawn(t_game *game, char c, int x, int y)
{
	if (game->player.posX != -1)
	{
		ft_putendl_fd("Error\nMultiple spawn points found\n", 2);
		return (EXIT_FAILURE);
	}
	game->player.posX = x + 0.5;
	game->player.posY = y + 0.5;
	set_player_direction(game, c);
	return (EXIT_SUCCESS);
}

static int	find_spawn_in_line(t_game *game, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (ft_strchr("NSEW", line[x]))
		{
			if (set_spawn(game, line[x], x, y) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			line[x] = '0';
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

int	find_player_spawn(t_game *game, char **map)
{
	int	y;

	y = 0;
	game->player.posX = -1;
	game->player.posY = -1;
	while (map[y])
	{
		if (find_spawn_in_line(game, map[y], y) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		y++;
	}
	if (game->player.posX == -1)
	{
		ft_putendl_fd("Error\nNo spawn point found on the map\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
