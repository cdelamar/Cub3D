#include "cub3d.h"

int quit_game(t_game *game, t_player *player)
{

	printf("test %s", game->file_name);
	close_mlx(game, player);
	return (EXIT_SUCCESS); // on y passe jamais
}

void raycast(t_game *game, t_player *player)
{
	(void)game;
	int	x;

	x = 0;
	while(x < SCREEN_WIDTH)
	{
		player->camX = 2 * x / (double)SCREEN_WIDTH - 1;
		player->rayX = player->dirX + player->planeX * player->camX;
		player->rayY = player->dirY + player->planeY * player->camX;

		// suite du raycasting

		printf("Ray %d: DirX = %f, DirY = %f\n", x, player->rayX, player->rayY);
        x++;
	}
}

void	ft_mlx(t_game *game, t_player *player)
{
	raycast(game, player);
	(void)player;
	mlx_hook(game->win, KeyPress, KeyPressMask, &player_controls, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &close_mlx, game);
	mlx_hook(game->win, 17, StructureNotifyMask, &quit_game, game);
	//mlx_hook(game->win, 65307, KeyPressMask, ft_quit, game);
	mlx_loop(game->mlx);
}