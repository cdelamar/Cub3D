#include "cub3d.h"

bool valid_map_characters(char **map)
{
    int i = 0;
    while (map[i])
	{
        int j = 0;
        while (map[i][j])
		{
            if (map[i][j] != '0' && map[i][j] != '1' &&
                map[i][j] != 'N' && map[i][j] != 'S' &&
                map[i][j] != 'E' && map[i][j] != 'W' &&
                map[i][j] != ' ')
                return (false);
            j++;
        }
        i++;
    }
    return (true);
}

bool map_closed(char **map)
{
    int i;
	int	j;

	i = 0;
	j = 0;
    while (map[i])
	{
        while(map[i][j])
		{
            if ((i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1]) &&
                map[i][j] != '1' && map[i][j] != ' ')
                return (false);
			j++;
        }
        i++;
    }
    return (true);
}

bool valid_map(char **map)
{
    if (map_closed(map) == false)
	{
        ft_putendl_fd(MAP_NOT_CLOSED, 2);
        return (false);
    }
	if (valid_map_characters(map) == false)
	{
		ft_putendl_fd(INVALID_MAP_CHARACTER, 2);
        return (false);
	}
	//if (valid_color())
	//if (valid_texture)
    return (true);
}


// pas sur de celle ci pour l'instant mais a peaufiner
/*
bool parse_cub_file(char *filename, t_game *game)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
	{
        ft_putendl_fd("Error\nCannot open .cub file", 2);
        return (false);
    }

    char *line;
    while ((line = get_next_line(fd)))
	{
        if (ft_strncmp(line, "NO", 2) == 0)
            validate_texture(line, &game->textures.north);
        else if (ft_strncmp(line, "SO", 2) == 0)
            validate_texture(line, &game->textures.south);
        else if (ft_strncmp(line, "WE", 2) == 0)
            validate_texture(line, &game->textures.west);
        else if (ft_strncmp(line, "EA", 2) == 0)
            validate_texture(line, &game->textures.east);
        else if (line[0] == 'F')
            validate_color(line, game->floor_color);
        else if (line[0] == 'C')
            validate_color(line, game->ceiling_color);
        else if (ft_strlen(line) > 0) // La map commence ici
            add_map_line(game, line);
        free(line);
    }
    close(fd);
    return validate_map(game->map);
}*/

