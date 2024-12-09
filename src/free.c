#include "cub3d.h"

void ft_freetab (char **tab)
{
	int i;

	i = 0;

	if(!tab[i])
		return ;
	while(tab[i])
	{
		if (!tab[i])
			return ;
		free (tab[i]);
		i++;
	}
	return ;
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
    if (game->textures.north)
		free(game->textures.north);
    if (game->textures.south)
		free(game->textures.south);
    if (game->textures.west)
		free(game->textures.west);
    if (game->textures.east)
		free(game->textures.east);
    ft_freetab(game->map);
    // ft_freetab(game->map_buffer);
    // ajouter plus tard
}
