#include "cub3d.h"

void raycast(t_game *game, t_player *player, t_ray *ray)
{
	(void)game;
	int	x;

	x = 0;
	while(x < SCREEN_WIDTH)
	{
		ray->camX = 2 * x / (double)SCREEN_WIDTH - 1;
		ray->rayX = player->dirX + ray->planeX * ray->camX;
		ray->rayY = player->dirY + ray->planeY * ray->camX;
		printf("Ray %d: DirX = %f, DirY = %f\n", x, ray->rayX, ray->rayY);

		// postition de depart du rayon dans la map
		game->mapX = (int)player->posX;
		game->mapY = (int)player->posY;

		if (ray->rayX == 0)
			ray->deltaDistX = 1e30; // Valeur infinie pour éviter la division par zéro
		else
			ray->deltaDistX = fabs(1 / ray->rayX);

		if (ray->rayY == 0)
			ray->deltaDistY = 1e30; // Valeur infinie pour éviter la division par zéro
		else
			ray->deltaDistY = fabs(1 / ray->rayY);

		// calcul des distances initiales pour sideDixstX/Y

		if (ray->rayX < 0)
		{
            ray->stepX = -1;
            ray->sideDistX = (player->posX - game->mapX) * ray->deltaDistX;
        }

		else
		{
            ray->stepX = 1;
            ray->sideDistX = (game->mapX + 1.0 - player->posX) * ray->deltaDistX;
        }

        if (ray->rayY < 0)
		{
            ray->stepY = -1;
            ray->sideDistY = (player->posY - game->mapY) * ray->deltaDistY;
        }

		else
		{
            ray->stepY = 1;
            ray->sideDistY = (game->mapY + 1.0 - player->posY) * ray->deltaDistY;
        }

		// suite du raycasting
        x++;
	}
}