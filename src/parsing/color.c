/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:43:04 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:43:05 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_color(char *value, int *color)
{
	if (is_numbr(value) == false)
	{
		ft_putendl_fd("Error\nInvalid character in color value.", 2);
		return (EXIT_FAILURE);
	}
	*color = ft_atoi(value);
	if (is_rgb(*color) == false)
	{
		ft_putendl_fd("Error\nPlease enter proper Color value (0-255).", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_color(t_game *game)
{
	if (game->floor_color[0] == -1 || game->floor_color[1] == -1
		|| game->floor_color[2] == -1)
	{
		ft_putendl_fd("Error\nMissing floor color (F).", 2);
		return (EXIT_FAILURE);
	}
	if (game->ceiling_color[0] == -1 || game->ceiling_color[1] == -1
		|| game->ceiling_color[2] == -1)
	{
		ft_putendl_fd("Error\nMissing ceiling color (C).", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_color(char *line, t_game *game)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		return (path_color(line + 2, game->floor_color));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (path_color(line + 2, game->ceiling_color));
	else
		return (EXIT_SUCCESS);
}
