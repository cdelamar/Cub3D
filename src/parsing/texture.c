#include "cub3d.h"

int	check_texture_files(t_textures *textures)
{
	if (!file_exists(textures->north))
	{
		ft_putendl_fd("Error\nNorth texture file not found.", 2);
		return (EXIT_FAILURE);
	}
	if (!file_exists(textures->south))
	{
		ft_putendl_fd("Error\nSouth texture file not found.", 2);
		return (EXIT_FAILURE);
	}
	if (!file_exists(textures->west))
	{
		ft_putendl_fd("Error\nWest texture file not found.", 2);
		return (EXIT_FAILURE);
	}
	if (!file_exists(textures->east))
	{
		ft_putendl_fd("Error\nEast texture file not found.", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_texture(t_game *game)
{
	if (!game->textures.north || !game->textures.south
		|| !game->textures.east || !game->textures.west)
	{
		ft_putendl_fd("Error\nMissing one or more texture paths.", 2);
		return (EXIT_FAILURE);
	}
	if (check_texture_files(&game->textures) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// je crois
	if (valid_texture_file(&game->textures) == false)
		return (EXIT_FAILURE);
	// pas sur
	return (EXIT_SUCCESS);
}

int	path_texture(char *line, char **texture)
{
	line = skip_spaces(line);
	if (*texture != NULL)
	{
		ft_putendl_fd("Error\nDuplicate texture identifier.", 2);
		return (EXIT_FAILURE);
	}
	*texture = copy_gnl_line(line);
	if (!(*texture))
	{
		ft_putendl_fd("Error\nMemory allocation failed for texture.", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_texture(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (path_texture(line + 3, &(game->textures.north)));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (path_texture(line + 3, &(game->textures.south)));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (path_texture(line + 3, &(game->textures.west)));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (path_texture(line + 3, &(game->textures.east)));
	else
		return (EXIT_SUCCESS);
}

int	load_textures(t_game *game)
{
	game->textures.north_img = mlx_xpm_file_to_image(game->mlx,
			game->textures.north, &game->textures.tex_width,
			&game->textures.tex_height);
	if (!game->textures.north_img)
		return (EXIT_FAILURE);
	game->textures.south_img = mlx_xpm_file_to_image(game->mlx,
			game->textures.south, &game->textures.tex_width,
			&game->textures.tex_height);
	if (!game->textures.south_img)
		return (EXIT_FAILURE);
	game->textures.west_img = mlx_xpm_file_to_image(game->mlx,
			game->textures.west, &game->textures.tex_width,
			&game->textures.tex_height);
	if (!game->textures.west_img)
		return (EXIT_FAILURE);
	game->textures.east_img = mlx_xpm_file_to_image(game->mlx,
			game->textures.east, &game->textures.tex_width,
			&game->textures.tex_height);
	if (!game->textures.east_img)
		return (EXIT_FAILURE);
	if (game->textures.tex_width <= 0 || game->textures.tex_height <= 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
