/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 13:53:19 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 15:15:28 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "mlx.h"
# include "mlx_int.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif 
# include "debug.h"
# define WIN_HORI 400//1280
# define WIN_VERT 300//1024
# define WIN_NAME "Cube3D"
# include "keys.h"
# include "libft.h"

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
	t_img			*mlx_img;
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
int			debug_keypress(void *address, int key);

//get_next_line
char		*get_next_line(int fd);

//Parse map
bool		parse_map(t_program *prog);

//debug
int			debug_keypress(void *address, int key);
void		printmap(t_map_i *ma);

// Init player
bool    	init_player(t_program *prg);

#endif