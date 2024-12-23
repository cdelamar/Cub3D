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

    printf("--- parsing output --- \n");
    printf("textures \n");
    printf ("north texture :%s\n",game->textures.north);
    printf ("south texture :%s\n",game->textures.south);
    printf ("east texture :%s\n",game->textures.east);
    printf ("west texture :%s\n",game->textures.west);
    printf("colors \n");
    printf ("floor : %d, %d, %d \n", game->floor_color[0], game->floor_color[1], game->floor_color[2]);
    printf ("ceiling : %d, %d, %d \n", game->ceiling_color[0], game->ceiling_color[1], game->ceiling_color[2]);
    printf("map \n");
    print_char_array(game->map);

    printf("END : \n\n\n");

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
   if (load_textures(game) == EXIT_FAILURE)
    {
        printf("deload texture\n\n");
        free_textures(game);
        // mlx_clear_window(game->mlx, game->win);
        // mlx_destroy_window(game->mlx, game->win);
        mlx_destroy_display(game->mlx);
        ft_freetab(game->map);
        free_path_textures(game);
        free(game->mlx);
        free(game);
        exit(0);
   }
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
    find_player_spawn(game, game->map);
    printf("direction du joueur :\n");
    printf("x : %f, y : %f\n", game->player.posX, game->player.posY);
    ft_mlx(game);

    free_game(game);
    free(game);
    return (EXIT_SUCCESS);
}
