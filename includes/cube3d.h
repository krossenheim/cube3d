/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 13:53:19 by jose-lop      #+#    #+#                 */
/*   Updated: 2025/01/21 10:10:48 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "mlx.h"
# include "mlx_int.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>
# define BUFFER_SIZE 1
# include "debug.h"
# define WIN_HORI 600//1280
# define WIN_VERT 600//1024
# define WIN_NAME "Cube3D"
# include "keys.h"
# include "libft.h"

typedef struct s_ray_cast 
{   
    double  camera_x;
    double  dir_x;
    double  dir_y;
    int  	start_x;
    int	  	start_y;
    double  side_dist_x;
    double  side_dist_y;
    double  delta_dist_x;
    double  delta_dist_y;
    double  perpend_dist;
    int	    step_x;
    int	    step_y;
    int     hit;
    int     side;
	int		line_height;
	double	draw_start;
	double	draw_end;
	int		wall_val;
	int		wall_color;
}   t_ray_cast;

typedef struct s_player
{
	double			plane_x;
	double			plane_y;
	double			dir_x;
	double			dir_y;
	double			pos_x;
	double			pos_y;
}	t_player;

typedef struct s_map_i
{
	int				**map;
	int				rows;
	int				cols;
}	t_map_i;

typedef struct s_cube3d_program
{
	t_xvar			*mlx;
	t_win_list		*mlx_win;
	t_img			mlx_img;
	t_key_role		*keys;
	t_map_i			*map_i;
	t_player		player;
	bool			draw;
}		t_program;

// Keys
bool    	init_keys(t_program *p);

// Bindings
bool		do_mlx_hooks(t_program *p);

//Initialization
t_program	*initialize_program();
bool		init_keys(t_program *p);

//Freeing
int		    exit_clean(t_program *prog);
void 		free_map(t_map_i *map);

//Libft
char		*ft_itoa(int n);
char		*ft_strdup(const char *s1);

// Keys on-press
int			escape_pressed(void *address);
int			move_forward(void *address);
int			move_back(void *address);
int			rotate_left(void *address);
int			rotate_right(void *address);
int			debug_keypress(void *address, int key);
int			strafe_left(void *address);
int			strafe_right(void *address);
//get_next_line
char		*get_next_line(int fd);

//Parse map
bool		parse_map(t_program *prog);

//debug
int			debug_keypress(void *address, int key);
void		printmap(t_map_i *ma);

// Init player
bool    	init_player(t_program *prg);

//raycast 
int			raycast(t_program *prg);
#endif