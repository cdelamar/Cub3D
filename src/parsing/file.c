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

int parse_file(char *file_name, t_game *game)
{
    char *line;
    int map_start;
    //int line_num = 0;


    game->fd = open(file_name, O_RDONLY);
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

    close (game->fd);

    game->map_fd = open(file_name, O_RDONLY);
    map_start = find_map_start(game->map_fd);
    if (map_start == -1)
    {
        ft_putendl_fd("Error\nNo valid map found in file.", 2);
        close(game->map_fd);
        return (false);
    }

    close(game->map_fd);
    return (true);
}
