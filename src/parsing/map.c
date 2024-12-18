#include "cub3d.h"

void compute_map_dimensions(t_game *game)
{
    int i;
    int len;

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

bool first_map_line(char *line)
{
	int i;

	line = skip_spaces(line);
	i = 0;
	while (line [i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}

#include "cub3d.h"

int count_map_lines(int fd)
{
    char *line;
    int line_count = 0;

    while ((line = get_next_line(fd)))
    {
            line_count++;
            free(line);
    }
    return line_count;
}

int parse_map(t_game *game,char *file_name)
{
    char *line;
    //int line_num = 0;
    int i = 0;

    // Compter les lignes nécessaires
    int map_fd_copy = open(file_name, O_RDONLY);
    if (map_fd_copy < 0)
        return (EXIT_FAILURE);
    int line_count = count_map_lines(map_fd_copy);
	printf("line count : %d\n", line_count);
    close(map_fd_copy);

    // Allouer mémoire pour la carte
    game->map = malloc(sizeof(char *) * (line_count + 1));
    if (!game->map)
        return (EXIT_FAILURE);

    // Copier les lignes
    while ((line = get_next_line(game->map_fd)))
    {
        if (line && (is_empty_line(line) == false) && first_map_line(skip_spaces(line)))
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

int check_map(t_game *game, char *file_name)
{
	if (parse_map(game, file_name) == -1)
		return (EXIT_FAILURE);
    compute_map_dimensions(game);
	// ici on rajoutera tous les prerequis
	// pour bien verifier la map :
	//. les bordures a 1
	//. ft_strchr ("01NSEW", map[i][j])
	//. etc
	return(EXIT_SUCCESS);
}
