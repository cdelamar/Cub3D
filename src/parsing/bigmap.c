#include "cub3d.h"

char	**build_bigmap(t_game *game)
{
	char	**bigmap;
	int		total_height;
	int		y;

	y = 0;
	total_height = game->map_height + 2;
	bigmap = allocate_bigmap_memory(total_height);
	if (!bigmap)
		return (NULL);
	while (y < total_height)
	{
		bigmap[y] = allocate_bigmap_row(game->map_width + 2);
		if (!bigmap[y])
			return (NULL);
		y++;
	}
	return (bigmap);
}

int	**init_visited_bigmap(t_game *game)
{
	int	**visited;
	int	y;
	int	width;

	visited = malloc(sizeof(int *) * (game->map_height + 2));
	if (!visited)
		return (NULL);
	y = 0;
	while (y < game->map_height + 2)
	{
		width = game->map_width + 2;
		visited[y] = ft_calloc(width, sizeof(int));
		if (!visited[y])
			return (NULL);
		y++;
	}
	return (visited);
}

void	free_visited_bigmap(int **visited, t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map_height + 2)
	{
		free (visited[y]);
		y++;
	}
	free (visited);
}
