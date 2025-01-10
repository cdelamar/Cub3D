#include "cub3d.h"

void	explore_up(t_game *game, char **bigmap, int y, int x)
{
	if (y > 0 && !game->visited[y - 1][x] && bigmap[y - 1][x] != '1')
	{
		push_queue(game->queue, y - 1, x);
		game->visited[y - 1][x] = 1;
	}
}

void	explore_down(t_game *game, char **bigmap, int y, int x)
{
	if (y + 1 < game->map_height + 2
		&& !game->visited[y + 1][x]
		&& bigmap[y + 1][x] != '1')
	{
		push_queue(game->queue, y + 1, x);
		game->visited[y + 1][x] = 1;
	}
}

void	explore_left(t_game *game, char **bigmap, int y, int x)
{
	if (x > 0 && !game->visited[y][x - 1] && bigmap[y][x - 1] != '1')
	{
		push_queue(game->queue, y, x - 1);
		game->visited[y][x - 1] = 1;
	}
}

void	explore_right(t_game *game, char **bigmap, int y, int x)
{
	if (x + 1 < game->map_width + 2
		&& !game->visited[y][x + 1]
		&& bigmap[y][x + 1] != '1')
	{
		push_queue(game->queue, y, x + 1);
		game->visited[y][x + 1] = 1;
	}
}

void	explore_neighbors(t_game *game, char **bigmap)
{
	int	y;
	int	x;

	y = game->bfs_y;
	x = game->bfs_x;
	explore_up(game, bigmap, y, x);
	explore_down(game, bigmap, y, x);
	explore_left(game, bigmap, y, x);
	explore_right(game, bigmap, y, x);
}
