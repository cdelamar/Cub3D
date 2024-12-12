#include "cub3d.h"

void init_game(t_game *game)
{
	game->textures.north = NULL;
	game->textures.south = NULL;
	game->textures.west = NULL;
	game->textures.east = NULL;
	game->floor_color[0] = -1;
	game->floor_color[1] = -1;
	game->floor_color[2] = -1;
	game->ceiling_color[0] = -1;
	game->ceiling_color[1] = -1;
	game->ceiling_color[2] = -1;
	game->map = NULL;
	game->map_buffer = NULL;
	game->mlx = NULL;
}

void init_player(t_player *player)
{
	player->posX = 22;
	player->posY = 12;
	player->dirX = -1;
	player->dirY = 0;
	player->time = 0;
	player->old_time = 0;
}

/*
void init_ray(t_ray *ray)
{
	ray->camX = 0;
	ray->rayX = 0;
	ray->rayY = 0;
	ray->sideDistX = 0;
	ray->sideDistY = 0;
	ray->deltaDistX = 0;
	ray->deltaDistY = 0;
	ray->perpWallDist = 0;
	ray->stepX = 0;
	ray->stepY = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->planeX = 0;
	ray->planeY = 0.66;
}
*/

void init_ray(t_ray *ray)
{
    // Initialisation des valeurs par défaut
    ray->camX = 0;              // Coordonnée X dans l'espace caméra (départ à 0)
    ray->rayX = 0;              // Direction du rayon sur l'axe X
    ray->rayY = 0;              // Direction du rayon sur l'axe Y
    ray->sideDistX = 0;         // Distance initiale jusqu'à la première intersection sur X
    ray->sideDistY = 0;         // Distance initiale jusqu'à la première intersection sur Y
    ray->deltaDistX = 0;        // Distance entre deux intersections consécutives sur X
    ray->deltaDistY = 0;        // Distance entre deux intersections consécutives sur Y
    ray->perpWallDist = 0;      // Distance perpendiculaire jusqu'au mur (à calculer)
    ray->stepX = 0;             // Direction à prendre sur l'axe X (1 ou -1)
    ray->stepY = 0;             // Direction à prendre sur l'axe Y (1 ou -1)
    ray->hit = 0;               // Indique si un mur a été touché (0 ou 1)
    ray->side = 0;              // Côté du mur touché (0 = NS, 1 = EW)
    ray->planeX = 0;            // Valeur par défaut du plan caméra X
    ray->planeY = 0.66;         // Valeur par défaut du plan caméra Y
    ray->drawStart = 0;         // Position de départ de la colonne à dessiner
    ray->drawEnd = 0;           // Position de fin de la colonne à dessiner
}
