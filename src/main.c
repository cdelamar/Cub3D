/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgalloux <lgalloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:43:49 by lgalloux          #+#    #+#             */
/*   Updated: 2025/01/18 16:43:50 by lgalloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_and_parse(t_game **game, int argc, char **argv)
{
	*game = malloc(sizeof(t_game));
	if (!(*game))
	{
		ft_putendl_fd("Error\nMemory allocation failed", 2);
		return (EXIT_FAILURE);
	}
	init_game(*game);
	if (parsing(argc, argv, *game) == false)
	{
		free_game(*game);
		free(*game);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	setup_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_mlx(game);
	if (load_textures(game) == EXIT_FAILURE)
	{
		ft_putendl_fd("Error\nproblem with a texture", 2);
		error_free(game);
	}
	if (find_player_spawn(game, game->map) == EXIT_FAILURE)
		error_free(game);
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	if (!game->win)
		error_win(game);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (init_and_parse(&game, argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (setup_mlx(game) == EXIT_FAILURE)
	{
		free_game(game);
		free(game);
		return (EXIT_FAILURE);
	}
	ft_mlx(game);
	free_game(game);
	free(game);
	return (EXIT_SUCCESS);
}
