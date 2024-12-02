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

# define INVALID_ARGC    	"invalid or wrong number of arguments"
# define FILE_NOT_FOUND  	"file not found or not a .ber file"
# define MAP_IS_EMPTY    	"map is empty"
# define NOT_A_RECTANGLE 	"map is not a rectangle"
# define FD_ERROR        	"cannot open the file"
# define MAP_NOT_CLOSED  	"map is not closed"
# define INCORRECT_VALUE		"incorrect value"
# define GAME_EXIT			"incorrect exit ('E') value"
# define GAME_PLAYER			"incorrect player ('P') value"
# define GAME_COLLECTIBLE	"incorrect collectible ('C') value"
# define CANT_REACH			"cant reach exit or collectible"

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


#endif