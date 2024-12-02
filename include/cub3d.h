/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelamar <cdelamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:51:42 by cdelamar          #+#    #+#             */
/*   Updated: 2024/05/13 17:19:23 by cdelamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <stdarg.h>
# include <math.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "libft.h"

# define WRONG_COLOR_VALUE		"Color values must be between 0 and 255"
# define INVALID_MAP_CHARACTER 	"Invalid map character"
# define INVALID_TEXTURE		"Invalid texture path"
# define INVALID_COLOR			"Invalid color format"
# define INVALID_ARGC    		"Invalid or wrong number of arguments"
# define INCORRECT_VALUE		"incorrect value"
# define NOT_A_RECTANGLE 		"Map is not a rectangle"
# define FILE_NOT_FOUND  		"File not found or not a .cub file"
# define MAP_NOT_CLOSED  		"Map is not closed"
# define MAP_IS_EMPTY    		"Map is empty"
# define FD_ERROR        		"Cannot open the file"

# define DESTROY_NOTIFY		17

# define ARROW_UP  				65362
# define ARROW_DOWN  			65364
# define ARROW_LEFT  			65361
# define ARROW_RIGHT 			65363

# define KEY_Q					113
# define KEY_ESCAPE  			65307

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE		5
# endif

typedef struct s_textures
{
    char *north;
    char *south;
    char *west;
    char *east;
}	t_textures;

typedef struct s_game
{
    t_textures textures;
    int floor_color[3];		// Couleurs RGB sol
    int ceiling_color[3];	// Couleurs RGB plafond
    char **map;				// Tableau 2D de map
} t_game;


//______PARSING______
// ---> args_checker.c
bool	valid_args(int argc, char **argv);
bool	valid_setup(int argc, char **argv);

// ---> map_checker.c


// ---> str_manager.c
int	rev_strncmp(char *s1, char *s2, size_t n);

// ---> gnl.c
char	*get_next_line(int fd);



#endif