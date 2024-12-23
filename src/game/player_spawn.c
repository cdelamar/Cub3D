#include "cub3d.h"
void set_player_direction(t_game *game, char spawn)
{
    if (spawn == 'N')
    {
        game->player.dirX = 0;
        game->player.dirY = -1;      // Direction vers le nord
        game->ray.planeX = 0.66;     // Plan caméra (pour un FOV de 66°)
        game->ray.planeY = 0;
    }
    else if (spawn == 'S')
    {
        game->player.dirX = 0;
        game->player.dirY = 1;       // Direction vers le sud
        game->ray.planeX = -0.66;
        game->ray.planeY = 0;
    }
    else if (spawn == 'E')
    {
        game->player.dirX = 1;
        game->player.dirY = 0;       // Direction vers l'est
        game->ray.planeX = 0;
        game->ray.planeY = 0.66;
    }
    else if (spawn == 'W')
    {
        game->player.dirX = -1;
        game->player.dirY = 0;       // Direction vers l'ouest
        game->ray.planeX = 0;
        game->ray.planeY = -0.66;
    }
}

int find_player_spawn(t_game *game, char **map)
{
    int y = 0;
    int x;

    game->player.posX = -1;
    game->player.posY = -1;
    for (y = 0; map[y]; y++)
    {
        for (x = 0; map[y][x]; x++)
        {
            if (ft_strchr("NSEW", map[y][x]))  // Trouver le spawn
            {
                if (game->player.posX != -1) // Erreur si plusieurs spawns
                {
					ft_putendl_fd("Error\nMultiple spawn points found\n", 2);
					return(EXIT_FAILURE);
				}
				game->player.posX = x + 0.5;     // Position centrée dans la case
                game->player.posY = y + 0.5;
                set_player_direction(game, map[y][x]);
                map[y][x] = '0';  // Remplacer par un espace vide
            }
        }
    }
    if (game->player.posX == -1)
	{
		ft_putendl_fd("Error\nNo spawn point found on the map\n", 2);
		return(EXIT_FAILURE);
	}
    return (EXIT_SUCCESS);
}
