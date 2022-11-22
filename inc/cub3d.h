/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsartral <nsartral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:48:46 by nsartral          #+#    #+#             */
/*   Updated: 2022/11/21 17:38:02 by nsartral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ========================================================================= //
//                                   Library                                 //
// ========================================================================= //

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include "error_msgs.h"

# define ALL_SPACES	" 	\x20\x08\x09\x0a\x0b\x0c\x0d"
# define SPACE_TAB	" 	"

# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD_W_Z	119
# define BACK_S_S		115
# define RIGHT_D_D		100
# define LEFT_A_Q		97
# define BUFFER_SIZE	4096

// ========================================================================= //
//                                Structures                                 //
// ========================================================================= //

typedef struct s_texture
{
	int				texdir;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
}					t_texture;

typedef struct s_ray
{
	double			posx; 
	double			posy; 
	double			dirx; 
	double			diry; 
	double			planx; 
	double			plany; 
	double			raydirx; 
	double			raydiry; 
	double			camerax; 
	int				mapx; 
	int				mapy; 
	double			sidedistx; 
	double			sidedisty; 
	double			deltadistx; 
	double			deltadisty; 
	int				stepx; 
	int				stepy; 
	int				hit; 
	int				side; 
	double			perpwalldist; 
	int				lineheight; 
	int				drawstart; 
	int				drawend; 
	double			movespeed; 
	double			rotspeed; 
	int				x; 
	int				texture; 
}					t_ray;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	t_img			*img;
	t_img			*img2;
	int				*addr;
	int				*addr2;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	int				width;
	int				height;
}					t_data;

typedef struct s_game
{
	char			*map_name;
	char			**my_file;
	char			**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char 			*spr;
	int				ground_color;
	int				sky_color;
	int				rgb[3];
	int				rx;
	int				ry;
	size_t			ylines;
	size_t			xlines;
	char			depart;
	int				dx;
	int				dy;
	int				screenx;
	int				screeny;
	int				count;
	t_texture		t;
	t_ray			ray;
	t_data			data;
	t_data			texture[10];
}					t_game;

// ========================================================================= //
//                                 Parsing                                   //
// ========================================================================= //

void		get_file(t_game *zz);
void		check_info(t_game *zz);
void		get_paths(t_game *zz, char *line);
void		get_colours(t_game *zz, char *line);
void		get_map(t_game *zz, size_t i);
void		check_map(t_game *zz);
void		check_walls(t_game *zz);
void		check_special_case(t_game *zz);
void		launch_game(t_game *zz);
void		init(char **argv, t_game *zz);
void		free_textures(t_game *zz);
void    	free_all_one(t_game *zz);
void    	free_all_two(t_game *zz);
void		good_exit(t_game *zz, char *str);
void		oops_crash(t_game *zz, char *msg);
void		clean_error_exit(t_game *zz, char *line, int fd, char *error_msg);
char		*trim_spaces(char *str);
bool		is_only_blanks(char *str);
size_t		count_chars(char *str, char c);
size_t		skip_blank_lines(char **my_file, size_t	i);
size_t		skip_blanks(char *line, size_t i);
size_t		skip_rev_blanks(char *line, size_t i);
size_t		get_tab_size(char **tab);
size_t		get_max_len(char **tab);
void		free_tab(char **tab);
void		print_tab(char **tab);
int			convert_rgb(int t, int r, int g, int b);


// ========================================================================= //
//                                Executing                                  //
// ========================================================================= //

/* /initing */
void		init_mlx(t_game *zz);
void		init_textures(t_game *zz);

/* /mlx_hooks */
int			cross_exit(int keycode, t_game *zz);
int			exiting(char *str, t_game *zz);
int			keying(int keycode, t_game *zz);
int			releasing(int keycode, t_game *zz);

/* /moving */
void		invisible_move(t_game *zz, char c);
void		updating_movements(t_game *zz);
void		rotate_right(t_game *zz);
void		rotate_left(t_game *zz);

/* /raycasting */
int			raycasting(t_game *zz);
void		reset_ray(t_game *zz);
void		incrementing(t_game *zz, int type);
void		calculating(t_game *zz);

/* /texturing */
void		texturing_environment(t_game *zz);
void		texturing_scene(t_game *zz);
int			print_pov(t_game *zz, int change);
void		print_minimap(t_game *zz);

#endif
