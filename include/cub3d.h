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
# include <ctype.h>
# include <stdarg.h>
# include <math.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "libft.h"

# define RGB_RED	0xFF0000
# define RGB_GREEN	0x008000
# define RGB_BLUE	0x0000FF
# define RGB_WHITE	0xFFFFFF
# define RGB_BLACK	0x000000

# define WRONG_COLOR_VALUE		"Error\nColor values must be between 0 and 255"
# define MISSING_TEXTURE        "Error\nMissing one or more textures"
# define INVALID_MAP_CHARACTER 	"Error\nInvalid map character"
# define INVALID_TEXTURE		"Error\nInvalid texture path"
# define INVALID_COLOR			"Error\nInvalid color format"
# define INVALID_ARGC    		"Error\nInvalid or wrong number of arguments"
# define INCORRECT_VALUE		"Error\nincorrect value"
# define NOT_A_RECTANGLE 		"Error\nMap is not a rectangle"
# define FILE_NOT_FOUND  		"Error\nFile not found or not a .cub file"
# define MAP_NOT_CLOSED  		"Error\nMap is not closed"
# define MAP_IS_EMPTY    		"Error\nMap is empty"
# define FD_ERROR        		"Error\nCannot open the file"

# define SCREEN_WIDTH			1640
# define SCREEN_HEIGHT			800

# define WIN_WIDTH				1640
# define WIN_HEIGHT				800

# define ARROW_UP  				65362
# define ARROW_DOWN  			65364
# define ARROW_LEFT  			65361
# define ARROW_RIGHT 			65363

# define KEY_Q					113
# define KEY_ESCAPE  			65307
# define DESTROY_NOTIFY			17

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE		5
# endif

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	void	*north_img;
	void	*south_img;
	void	*west_img;
	void	*east_img;
	int		tex_width;
	int		tex_height;
}	t_textures;

typedef struct s_draw
{
	int		start;
	int		end;
	int		height;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	char	*texture_data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_draw;

typedef struct s_ray
{
	double	cam_x;
	double	ray_x;
	double	ray_y;

	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_walldist;

	int		step_x;
	int		step_y;
	int		hit;
	int		side;

	double	plane_x;
	double	plane_y;

	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	time;
	double	old_time;
}	t_player;

typedef struct s_game
{
	t_textures	textures;
	t_player	player;
	t_ray		ray;
	char		*file_name;

	int			fd;
	int			map_fd;

	int			floor_color[3];
	int			ceiling_color[3];

	char		**map;
	char		**map_buffer;
	int			map_x;
	int			map_y;

	int			map_height;
	int			map_width;

	void		*mlx;
	void		*win;
}	t_game;

// ---> free.c
void	free_path_textures(t_game *game);
void	free_textures(t_game *game);
void	ft_freetab(char **tab);
void	*ft_realloc(void *ptr, size_t new_size);
void	free_game(t_game *game);

// ---> gnl.c
char	*get_next_line(int fd);

// ---> init.c
void	init_game(t_game *game);
void	init_player(t_player *player);
void	init_ray(t_ray *ray);

// ---> str.c
char	*copy_gnl_line(char *line);
int		rev_strncmp(char *s1, char *s2, size_t n);
void	print_int_array(int *array, int size);
void	print_char_array(char **array);
void	free_split(char **tab);

// ---> utils.c
bool	is_empty_line(char *line);
bool	is_numbr(char *str);
bool	is_rgb(int c);
char	*skip_spaces(char *line);

// ---> args.c
bool	file_exists(char *filename);
bool	valid_args(int argc, char **argv);
bool	parsing(int argc, char**argv, t_game *game);

// ---> color.c
int		three_colors(char **values);
int		rgb_color(char *value, int *color);
int		check_color(t_game *game);
int		path_color(char *line, int color[3]);
int		parse_color(char *line, t_game *game);

// ---> file.c
int		parse_line(char *line, t_game *game);
bool	parse_file(char *file_name, t_game *game);

// ---> map.c
bool	first_map_line(char *line);
int		parse_map(t_game *game, char *file_name);
int		check_map(t_game *game, char *file_name);

// ---> texture.c
int		check_texture_files(t_textures *textures);
int		check_texture(t_game *game);
int		path_texture(char *line, char **texture);
int		parse_texture(char *line, t_game *game);
int		load_textures(t_game *game);

// --- GAME ---

// ---> player_spawn.c
int		find_player_spawn(t_game *game, char **map);
void	set_player_direction(t_game *game, char spawn);

// ---> hook.c

int		render_frame(void *param);
int		close_mlx(t_game *game);
void	ft_mlx(t_game *game);

char	*get_texture_addr(void *img, int *bpp, int *size_line, int *endian);
void	draw_floor_and_ceiling(t_game *game, void *img);
void	cast_ray(t_game *game, void *img, int x);
void	raycaster(t_game *game);

// ---> maths.c

void	draw_pixel(void *data_addr, int x, int y, int color);
void	calc_step(t_game *game, t_ray *ray, int *map_x, int *map_y);
void	dda(t_game *game, t_ray *ray, int *map_x, int *map_y);

// ---> player_control.c

void	move_player(t_game *game, double move_speed);
void	strafe_player(t_game *game, double move_speed);
void	rotate_player(t_game *game, double rot_speed);
int		player_controls(int keycode, t_game *game);

// ---> error.c

void	error_free(t_game *game);
void	error_mlx(t_game *game);
void	error_win(t_game *game);

// ---> direction.c

void	set_player_direction(t_game *game, char spawn);

// ---> draw.c

char	*select_texture_data(t_game *game, int *bpp, int *sl, int *end);
void	compute_line_dimensions(t_game *game, t_draw *d);
void	draw_column(t_game *game, void *img, int x, t_draw *d);
void	calc_wall_dist(t_game *game);
void	compute_wallx_and_texx(t_game *game, t_draw *d);

#endif