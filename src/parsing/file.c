#include "cub3d.h"

int parse_line(char *line, t_game *game)
{
	line = skip_spaces(line);
	if (*line == '\0')
		return (EXIT_SUCCESS);

	if (parse_texture(line, game) == EXIT_FAILURE)
		return(EXIT_FAILURE);

	if (parse_color(line, game) == EXIT_FAILURE)
		return(EXIT_FAILURE);

	return (EXIT_SUCCESS);
}

int check_texture_colors(t_game *game)
{
	char *line;

	while ((line = get_next_line(game->fd)))
	{
		if (parse_line(line, game) == EXIT_FAILURE)
		{
			free(line);
			close(game->fd);
			return (false);
		}
		free(line);
	}
	if (check_texture(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (check_color(game) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(line);
	return (EXIT_SUCCESS);
}

int parse_file(char *file_name, t_game *game)
{
	// partie parsing textures / couleurs
	game->fd = open(file_name, O_RDONLY);

	if(check_texture_colors(game) == EXIT_FAILURE)
	{
		close(game->fd);
		return (EXIT_FAILURE);
	}
	close (game->fd);

	// partie parsing de map
	game->map_fd = open(file_name, O_RDONLY);

	if (check_map(game) == EXIT_FAILURE)
	{
		close(game->map_fd);
		return (EXIT_FAILURE);
	}
	close(game->map_fd);

	return (true);
}
