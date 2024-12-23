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
}

int	count_map_lines(int fd)
{
	char	*line;
	int		line_count;

	line_count = 0;
	while ((line = get_next_line(fd)))
	{
		line_count++;
		free(line);
	}
	return (line_count);
}

int	parse_map(t_game *game, char *file_name)
{
	char	*line;
	int		map_fd_copy;
	int		line_count;
	int		i;

	i = 0;
	map_fd_copy = open(file_name, O_RDONLY);
	if (map_fd_copy < 0)
		return (EXIT_FAILURE);
	line_count = count_map_lines(map_fd_copy);
	close(map_fd_copy);
	game->map = malloc(sizeof(char *) * (line_count + 1));
	if (!game->map)
		return (EXIT_FAILURE);
	while ((line = get_next_line(game->map_fd)))
	{
		if (line && (is_empty_line(line) == false)
			&& first_map_line(skip_spaces(line)))
		{
			while (line && i < line_count)
			{
				game->map[i] = ft_strdup(line);
				if (!game->map[i])
				{
					free(line);
					return (EXIT_FAILURE);
				}
				if (game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
					game->map[i][ft_strlen(game->map[i]) - 1] = '\0';
				i++;
				free(line);
				line = get_next_line(game->map_fd);
			}
			game->map[i] = NULL;
			free(line);
			return (EXIT_SUCCESS);
		}
		free(line);
	}
	ft_putendl_fd("Error\n Proper map unsettled\n", 2);
	return (EXIT_FAILURE);
}

int	check_map(t_game *game, char *file_name)
{
	if (parse_map(game, file_name) == -1)
		return (EXIT_FAILURE);
	compute_map_dimensions(game);
	if (check_map_borders(game) == EXIT_FAILURE)
	{
		ft_putendl_fd("Error\nMap borders are not all '1'.", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
