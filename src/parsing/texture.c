#include "cub3d.h"

int check_texture(t_game *game)
{
    if (!game->textures.north)
    {
        ft_putendl_fd("Error\nMissing north texture (NO).", 2);
        return (EXIT_FAILURE);
    }
    if (!game->textures.south)
    {
        ft_putendl_fd("Error\nMissing south texture (SO).", 2);
        return (EXIT_FAILURE);
    }
    if (!game->textures.east)
    {
        ft_putendl_fd("Error\nMissing east texture (EA).", 2);
        return (EXIT_FAILURE);
    }
    if (!game->textures.west)
    {
        ft_putendl_fd("Error\nMissing west texture (WE).", 2);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int path_texture(char *line, char **texture)
{
    line = skip_spaces(line);

    if (*texture != NULL)
    {
        ft_putendl_fd("Error\nDuplicate texture identifier.", 2);
        return (EXIT_FAILURE);
    }
    *texture = ft_strdup(line);
    if (!(*texture))
    {
        ft_putendl_fd("Error\nMemory allocation failed for texture.", 2);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

int parse_texture(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
        return path_texture(line + 3, &(game->textures.north));
    if (ft_strncmp(line, "SO ", 3) == 0)
        return path_texture(line + 3, &(game->textures.south));
    if (ft_strncmp(line, "WE ", 3) == 0)
        return path_texture(line + 3, &(game->textures.west));
    if (ft_strncmp(line, "EA ", 3) == 0)
        return path_texture(line + 3, &(game->textures.east));
	else
		return(EXIT_SUCCESS);
}