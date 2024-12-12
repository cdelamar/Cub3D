#include "cub3d.h"

void draw_vertical_line(t_game *game, t_ray *ray,int x, int color)
{
    int y = ray->drawStart;

    while (y <= ray->drawEnd)
    {
        mlx_pixel_put(game->mlx, game->win, x, y, color);
        y++;
    }
}


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

		// le while (hit) :
		// complete la logique  Digital Differential Analysis (DDA)

		ray->hit = 0;
		while (ray->hit == 0)
		{
			// Avancer vers la prochaine case de la grille (map)
			if (ray->sideDistX < ray->sideDistY)
			{
				ray->sideDistX += ray->deltaDistX;
				game->mapX += ray->stepX;
				ray->side = 0; // Mur NS touché
			}
			else
			{
				ray->sideDistY += ray->deltaDistY;
				game->mapY += ray->stepY;
				ray->side = 1; // Mur EW touché
			}

			// Vérifier si le rayon frappe un mur
			if (game->map[game->mapY][game->mapX] > 0)
				ray->hit = 1;
		}

		// Calcul de 'perpWallDist' (distance au mur) + dessiner la colonne
		if (ray->side == 0)
			ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
		else
			ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);

		// calcul de la hauteur de la colonne
		int lineHeight = (int)(SCREEN_HEIGHT / ray->perpWallDist);

		// definir les pixels a dessiner pour la colonne

		ray->drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (ray->drawStart < 0)
			ray->drawStart = 0;

		ray->drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (ray->drawEnd >= SCREEN_HEIGHT)
			ray->drawEnd = SCREEN_HEIGHT - 1;

		//dessiner la colonne
		// color blanc ou gris (temporaire, a refaire pour les texutres)
		int color = (ray->side == 0) ? RGB_RED : RGB_BLUE;
        draw_vertical_line(game, ray, x, color);

		// suite du raycasting
        x++;
	}
}