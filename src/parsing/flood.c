#include "cub3d.h"

int	is_open_cell(t_game *game, char **bigmap)
{
	char	cell;

	cell = bigmap[game->bfs_y][game->bfs_x];
	return (cell == '0' || cell == 'N' || cell == 'S'
		|| cell == 'E' || cell == 'W');
}

/*int	process_next_node(t_game *game, char **bigmap)
{
	if (!pop_queue(game->queue, &game->bfs_y, &game->bfs_x))
		return (0);
	if (is_open_cell(game, bigmap))
	{
		//cleanup_bfs(game);
		return (0);
	}
	explore_neighbors(game, bigmap);
	return (1);
}*/

int	process_next_node(t_game *game, char **bigmap)
{
	if (!pop_queue(game->queue, &game->bfs_y, &game->bfs_x))
		return (WALL_SUCCESS);
	if (is_open_cell(game, bigmap))
		return (WALL_FAILURE);
	explore_neighbors(game, bigmap);
	return (WALL_KEEP_SEARCH);
}

int	flood_from_outside(t_game *game, char **bigmap)
{
	int	ret;

	if (!init_bfs(game))
		return (0);
	push_queue(game->queue, 0, 0);
	game->visited[0][0] = 1;
	while (1)
	{
		ret = process_next_node(game, bigmap);
		if (ret == WALL_SUCCESS)
			break ;
		if (ret == WALL_FAILURE)
		{
			cleanup_bfs(game);
			return (0);
		}
	}
	cleanup_bfs(game);
	return (1);
}
