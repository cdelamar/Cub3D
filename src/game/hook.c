#include "cub3d.h"

int	close_mlx (t_game *game, t_player *player)
{
	(void)player;
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_game(game);
	free(game);
	printf("on sort\n");
	//free(player); pourquoi il en veut pas ?
	exit(0);
}

int quit_game(t_game *game, t_player *player)
{

	printf("test %s", game->file_name);
	close_mlx(game, player);
	return (EXIT_SUCCESS); // on y passe jamais
}

void	ft_mlx(t_game *game, t_player *player, t_ray *ray)
{
	//raycast(game, player, ray);
	(void)player;
	(void)ray;
	mlx_hook(game->win, KeyPress, KeyPressMask, &player_controls, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_mlx, game);
	mlx_hook(game->win, 17, StructureNotifyMask, &quit_game, game);
	//mlx_hook(game->win, 65307, KeyPressMask, ft_quit, game);
	mlx_loop(game->mlx);
}