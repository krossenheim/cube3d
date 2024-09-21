/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 13:53:19 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/21 15:33:05 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "mlx.h"
# include "mlx_int.h"
# include <stdbool.h>
# include <unistd.h>

# include "debug.h"
# define WIN_HORI 400//1280
# define WIN_VERT 300//1024
# define WIN_NAME "Cube3D"
# include "keys.h"

typedef struct s_cube3d_program
{
	t_xvar			*mlx;
	t_win_list		*mlx_win;
	t_img			*mlx_img;
	t_key_role		*keys;
}		t_program;

// Keys
bool    init_keys(t_program *p);

// Bindings
bool		do_mlx_hooks(t_program *p);

//Initialization
t_program	*initialize_program();
bool		init_keys(t_program *p);

//Freeing
int		    exit_clean(t_program *prog);

//Libft
char		*ft_itoa(int n);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);

// Keys on-press
int		escape_pressed(void *address);

#endif