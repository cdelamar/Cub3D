#include "cub3d.h"

int render_frame(void *param)
{
	t_game *game = (t_game *)param;
	raycast(game, &game->player, &game->ray);  // Calculer les colonnes et les dessiner

    return (0);  // Retourne 0 pour satisfaire la signature de mlx_loop_hook
}


int	close_mlx (t_game *game)
{
	//(void)player;
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game(game);
	free(game);
	//printf("on sort\n");
	//free(player); pourquoi il en veut pas ?
	exit(0);
}

int quit_game(t_game *game, t_player *player)
{

	printf("test %f", player->dirX);
	close_mlx(game);
	return (EXIT_SUCCESS); // on y passe jamais
}

void ft_mlx(t_game *game)
{
    mlx_loop_hook(game->mlx, &render_frame, game);
    mlx_hook(game->win, KeyPress, KeyPressMask, &player_controls, game);
    mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_mlx, game);
    mlx_hook(game->win, 17, StructureNotifyMask, &quit_game, game);
    mlx_loop(game->mlx);
}

