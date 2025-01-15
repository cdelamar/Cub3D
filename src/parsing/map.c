#include "cub3d.h"

int	check_map_borders(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1'
			|| game->map[game->map_height - 1][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1'
			|| game->map[i][game->map_width - 1] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	compute_map_dimensions(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	game->map_height = 0;
	game->map_width = 0;
	while (game->map[i])
	{
		len = ft_strlen(game->map[i]);
		if (len > game->map_width)
			game->map_width = len;
		i++;
	}
	game->map_height = i;
	printf("le nombre de ligne est %d\n", game->map_height);
}

int	count_map_lines(int fd)
{
	char	*line;
	int		line_count;

	line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	return (line_count);
}

bool	is_valid_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_valid_map_char(line[i]) && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

int	check_map(t_game *game, char *file_name)
{
	if (parse_map(game, file_name) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	compute_map_dimensions(game);
	if (map_is_closed(game) == false)
	{
		ft_putendl_fd("Error\nMap is not closed.", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
