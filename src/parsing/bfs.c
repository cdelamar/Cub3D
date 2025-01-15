#include "cub3d.h"

int	init_bfs(t_game *game)
{
	game->visited = init_visited_bigmap(game);
	if (!game->visited)
		return (0);
	game->queue = init_queue();
	if (!game->queue)
	{
		free_visited_bigmap(game->visited, game);
		return (0);
	}
	return (1);
}

void	cleanup_bfs(t_game *game)
{
	free_visited_bigmap(game->visited, game);
	free_queue(game->queue);
}

bool	map_is_closed(t_game *game)
{
	char	**bigmap;
	int		closed;
	int		i;

	closed = 1;
	i = 0;
	bigmap = build_bigmap(game);
	if (!bigmap)
	{
		ft_putendl_fd("Error\nMemory allocation bigmap", 2);
		free(bigmap);
		return (false);
	}
	copy_map_into_bigmap(game, bigmap);
	if (find_player_spawn(game, game->map) == EXIT_FAILURE)
		error_pos(game, bigmap);
	closed = is_closed(bigmap, game->player.pos_y, game->player.pos_x);
	printf("closed vaut %d\n", closed);
	while (bigmap[i])
	{
		free(bigmap[i]);
		i++;
	}
	free(bigmap);
	return (closed);
}
