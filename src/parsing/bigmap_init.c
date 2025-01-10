#include "cub3d.h"

char	*allocate_bigmap_row(int width)
{
	char	*row;
	int		i;

	i = 0;
	row = malloc(sizeof(char) * (width + 1));
	if (!row)
		return (NULL);
	while (i < width)
	{
		row[i] = ' ';
		i++;
	}
	row[i] = '\0';
	return (row);
}

char	**allocate_bigmap_memory(int total_height)
{
	char	**bigmap;

	bigmap = malloc(sizeof(char *) * (total_height + 1));
	if (!bigmap)
		return (NULL);
	bigmap[total_height] = NULL;
	return (bigmap);
}

void	copy_map_into_bigmap(t_game *game, char **bigmap)
{
	int	y_map;
	int	x_map;
	int	len;

	y_map = 0;
	while (y_map < game->map_height)
	{
		x_map = 0;
		len = ft_strlen(game->map[y_map]);
		while (x_map < len)
		{
			bigmap[y_map + 1][x_map + 1] = game->map[y_map][x_map];
			x_map++;
		}
		y_map++;
	}
}
