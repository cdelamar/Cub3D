/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:42:50 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:42:51 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	valid_texture_file(t_textures *textures)
{
	if (rev_strncmp(textures->north, ".xpm", 4))
	{
		ft_putendl_fd("Error\nInvalid file for north texture", 2);
		return (false);
	}
	if (rev_strncmp(textures->south, ".xpm", 4))
	{
		ft_putendl_fd("Error\nInvalid file for south texture", 2);
		return (false);
	}
	if (rev_strncmp(textures->west, ".xpm", 4))
	{
		ft_putendl_fd("Error\nInvalid file for west texture", 2);
		return (false);
	}
	if (rev_strncmp(textures->east, ".xpm", 4))
	{
		ft_putendl_fd("Error\nInvalid file for east texture", 2);
		return (false);
	}
	return (true);
}

bool	file_exists(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	close(fd);
	return (true);
}

bool	valid_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd(INVALID_ARGC, 2);
		return (false);
	}
	if (rev_strncmp(argv[1], ".cub", 4) != 0)
	{
		ft_putendl_fd(FILE_NOT_FOUND, 2);
		return (false);
	}
	if (file_exists(argv[1]) == false)
	{
		ft_putendl_fd(FILE_NOT_FOUND, 2);
		return (false);
	}
	return (true);
}

bool	parsing(int argc, char **argv, t_game *game)
{
	if (valid_args(argc, argv) == false)
		return (false);
	if (parse_file(argv[1], game) == false)
		return (false);
	return (true);
}
