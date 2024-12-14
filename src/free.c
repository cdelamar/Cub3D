#include "cub3d.h"

void free_textures(t_textures *textures, void *mlx)
{
    if (textures->north_img)
        mlx_destroy_image(mlx, textures->north_img);
    if (textures->south_img)
        mlx_destroy_image(mlx, textures->south_img);
    if (textures->west_img)
        mlx_destroy_image(mlx, textures->west_img);
    if (textures->east_img)
        mlx_destroy_image(mlx, textures->east_img);
}

void ft_freetab (char **tab)
{
    int i;

    i = 0;
    if (!tab)
        return;
    while (tab[i] != NULL)
    {
        free(tab[i]);
        tab[i] = NULL;
        i++;
    }
    free(tab);
    tab = NULL;
}

void *ft_realloc(void *ptr, size_t new_size)
{
    void *new_ptr;

    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    if (!ptr)
        return malloc(new_size);
    new_ptr = malloc(new_size);
    if (!new_ptr)
        return NULL;
    ft_memcpy(new_ptr, ptr, new_size);
    free(ptr);
    return new_ptr;
}

void free_game(t_game *game)
{
    free_textures(&game->textures, game->mlx);
    /*if (game->textures.north)
		free(game->textures.north);
    if (game->textures.south)
		free(game->textures.south);
    if (game->textures.west)
		free(game->textures.west);
    if (game->textures.east)
		free(game->textures.east);*/
    ft_freetab(game->map);
    // ft_freetab(game->map_buffer);
    // ajouter plus tard
}
