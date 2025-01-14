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

/*int	map_is_closed(t_game *game)
{
	char	**bigmap;
	int		closed;
	int		i;

	bigmap = build_bigmap(game);
	if (!bigmap)
	{
		ft_putendl_fd("Error\nMemory allocation bigmap", 2);
		return (0);
	}
	copy_map_into_bigmap(game, bigmap);
	closed = flood_from_outside(game, bigmap);
	if (!closed)
		return(0);
	{
		i = 0;
		while (bigmap[i])
		{
			free(bigmap[i]);
			i++;
		}
		free(bigmap);
	}
	return (closed);
}*/

int	map_is_closed(t_game *game)
{
	char	**bigmap;
	int		closed;
	int		i;

	bigmap = build_bigmap(game);
	if (!bigmap)
	{
		ft_putendl_fd("Error\nMemory allocation bigmap", 2);
		return (0);
	}
	copy_map_into_bigmap(game, bigmap);

	closed = flood_from_outside(game, bigmap);

	// Libération SYSTÉMATIQUE de la bigmap
	i = 0;
	while (bigmap[i])
	{
		free(bigmap[i]);
		i++;
	}
	free(bigmap);

	// On retourne la valeur de closed
	return (closed);
}

