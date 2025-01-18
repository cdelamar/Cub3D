/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:43:34 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:43:35 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_game *game)
{
	if (game->textures.north_img)
		mlx_destroy_image(game->mlx, game->textures.north_img);
	if (game->textures.south_img)
		mlx_destroy_image(game->mlx, game->textures.south_img);
	if (game->textures.west_img)
		mlx_destroy_image(game->mlx, game->textures.west_img);
	if (game->textures.east_img)
		mlx_destroy_image(game->mlx, game->textures.east_img);
}

void	free_path_textures(t_game *game)
{
	if (game->textures.north)
	{
		free(game->textures.north);
		game->textures.north = NULL;
	}
	if (game->textures.south)
	{
		free(game->textures.south);
		game->textures.south = NULL;
	}
	if (game->textures.west)
	{
		free(game->textures.west);
		game->textures.west = NULL;
	}
	if (game->textures.east)
	{
		free(game->textures.east);
		game->textures.east = NULL;
	}
}

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

void	free_game(t_game *game)
{
	free_textures(game);
	if (game->textures.north)
		free(game->textures.north);
	if (game->textures.south)
		free(game->textures.south);
	if (game->textures.west)
		free(game->textures.west);
	if (game->textures.east)
		free(game->textures.east);
	ft_freetab(game->map);
}
