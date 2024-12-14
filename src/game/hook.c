#include "cub3d.h"

int render_frame(void *param)
{
	t_game *game;

	game = (t_game *)param;
	raycaster(game);
	return (0);
}


int	close_mlx (t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_textures(game);
	ft_freetab(game->map);
	// free_game(game);
	free(game->mlx);
	free(game);
	exit(0);
}

int quit_game(t_game *game)
{
	close_mlx(game);
	return (EXIT_SUCCESS); // on y passe jamais
}

void ft_mlx(t_game *game)
{
	mlx_loop_hook(game->mlx, &render_frame, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &player_controls, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_mlx, game);
	mlx_loop(game->mlx);
}

/*void ft_mlx(t_game *game)
{
    mlx_loop_hook(game->mlx, &render_frame, game);
    mlx_hook(game->win, KeyPress, KeyPressMask, &player_controls, game);
    mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_mlx, game);
    mlx_hook(game->win, 17, StructureNotifyMask, &quit_game, game);
    mlx_loop(game->mlx);
}*/

