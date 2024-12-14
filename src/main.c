#include "cub3d.h"

int main(int argc, char **argv)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    if (!game)
    {
        ft_putendl_fd("Error\nMemory allocation failed", 2);
        return (EXIT_FAILURE);
    }

    init_game(game); // Initialisation de toutes les structures

    if (parsing(argc, argv, game) == false)
    {
        free_game(game);
        free(game);
        return (EXIT_FAILURE);
    }

    // Initialisation de MiniLibX
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        ft_putendl_fd("Error\nMiniLibX initialization failed", 2);
        free_game(game);
        free(game);
        return (EXIT_FAILURE);
    }

    // Charger les textures après l'initialisation de MiniLibX
    load_textures(game);

    // Vérifiez que toutes les textures sont bien chargées
    if (!game->textures.north_img || !game->textures.south_img ||
        !game->textures.west_img || !game->textures.east_img)
    {
        free_game(game);
        free(game);
        return (EXIT_FAILURE);
    }

    // Création de la fenêtre
    game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
    if (!game->win)
    {
        ft_putendl_fd("Error\nWindow creation failed", 2);
        free_game(game);
        free(game);
        return (EXIT_FAILURE);
    }

    // Lancer la boucle principale
    ft_mlx(game);

    free_game(game);
    free(game);
    return (EXIT_SUCCESS);
}
