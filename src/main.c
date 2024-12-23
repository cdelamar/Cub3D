#include "cub3d.h"
    // printf("--- parsing output --- \n");
    // printf("textures \n");
    // printf ("north texture :%s\n",game->textures.north);
    // printf ("south texture :%s\n",game->textures.south);
    // printf ("east texture :%s\n",game->textures.east);
    // printf ("west texture :%s\n",game->textures.west);
    // printf("colors \n");
    // printf ("floor : %d, %d, %d \n", game->floor_color[0], game->floor_color[1], game->floor_color[2]);
    // printf ("ceiling : %d, %d, %d \n", game->ceiling_color[0], game->ceiling_color[1], game->ceiling_color[2]);
    // printf("map \n");
    // print_char_array(game->map);

    // printf("END : \n\n\n");

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
        error_mlx(game);

    // Charger les textures après l'initialisation de MiniLibX
    if (load_textures(game) == EXIT_FAILURE)
        error_free(game);
    if (find_player_spawn(game, game->map) == EXIT_FAILURE)
        error_free(game);

    // Création de la fenêtre
    game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
    if (!game->win)
        error_win(game);

    // Lancer la boucle principale
    ft_mlx(game);
    free_game(game);
    free(game);
    return (EXIT_SUCCESS);
}
