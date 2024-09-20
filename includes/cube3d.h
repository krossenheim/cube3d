/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 13:53:19 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/20 16:54:49 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "debug.h"
# include "mlx.h"
# include "mlx_int.h"
# define WIN_HORI 1280
# define WIN_VERT 1024
# define WIN_NAME "Cube3D"
# include <stdbool.h>
# include <unistd.h>

typedef struct s_cube3d_program
{
	t_xvar		*mlx;
	t_win_list	*mlx_win;
	t_img		*mlx_img;
}		t_program;

// Bindings
bool	bind_keys();

//Initialization
t_program	*initialize_program();

//Freeing
void    exit_clean(t_program *prog);

#endif