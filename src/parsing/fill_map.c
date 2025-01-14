#include "cub3d.h"

char	*remove_spaces(const char *line)
{
	char	*new_line;
	int		i;
	int		j;

	if (!line)
		return (NULL);
	new_line = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			new_line[j] = line[i];
			j++;
		}
		i++;
	}
	new_line[j] = '\0';
	return (new_line);
}

int	fill_map_block(t_game *game, char **line, int line_count, int *i)
{
	while (*line && *i < line_count)
	{
		if (process_line(game, line, i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	game->map[*i] = NULL;
	free(*line);
	return (EXIT_SUCCESS);
}

int	fill_map(t_game *game, int line_count)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(game->map_fd);
	while (line)
	{
		if (!is_empty_line(line)
			&& first_map_line(skip_spaces(line)))
		{
			if (fill_map_block(game, &line, line_count, &i) == EXIT_SUCCESS)
				return (EXIT_SUCCESS);
			else
				return (EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(game->map_fd);
	}
	return (EXIT_FAILURE);
}

int	parse_map(t_game *game, char *file_name)
{
	int	map_fd_copy;
	int	line_count;
	int	i;

	map_fd_copy = open(file_name, O_RDONLY);
	if (map_fd_copy < 0)
		return (EXIT_FAILURE);
	line_count = count_map_lines(map_fd_copy);
	close(map_fd_copy);
	game->map = malloc(sizeof(char *) * (line_count + 1));
	if (!game->map)
		return (EXIT_FAILURE);
	i = 0;
	while (i <= line_count)
	{
		game->map[i] = NULL;
		i++;
	}
	if (fill_map(game, line_count) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
	{
		ft_putendl_fd(MAP_FORMAT_CHAR, 2);
		return (EXIT_FAILURE);
	}
}
