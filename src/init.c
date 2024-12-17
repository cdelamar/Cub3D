#include "cub3d.h"


void init_player(t_player *player)
{
	player->posX = -1;
	player->posY = -1;
	player->dirX = -1;
	player->dirY = 0;
	player->time = 0;
	player->old_time = 0;
}

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
    ray->drawStart = 0;
    ray->drawEnd = 0;
}

void init_game(t_game *game)
{
    game->textures.north = NULL;
    game->textures.south = NULL;
    game->textures.west = NULL;
    game->textures.east = NULL;

    game->textures.north_img = NULL;
    game->textures.south_img = NULL;
    game->textures.west_img = NULL;
    game->textures.east_img = NULL;

    game->textures.tex_width = 0;
    game->textures.tex_height = 0;

    game->floor_color[0] = -1;
    game->floor_color[1] = -1;
    game->floor_color[2] = -1;
    game->ceiling_color[0] = -1;
    game->ceiling_color[1] = -1;
    game->ceiling_color[2] = -1;

    game->map = NULL;
    game->map_buffer = NULL;
    game->mlx = NULL;
    init_player(&game->player);
    init_ray(&game->ray);
}
