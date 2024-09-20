/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 14:04:40 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/20 16:40:23 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void    placeholder(void *ptr)
{
    t_program *program;

    program = (t_program *) ptr;
    if ( 0 && program)
        exit(1);
    printf("Recevedd\n");
}

bool    initialize_mlx(t_program *prg)
{
    prg->mlx = mlx_init();
	if (prg->mlx == NULL)
		write(1, "Failed to initialize library 'mlx_init'\n", 41);
	if (prg->mlx == NULL)
		return (false);
	prg->mlx_win = mlx_new_window(prg->mlx, WIN_HORI, WIN_VERT, WIN_NAME);
	if (prg->mlx_win == NULL)
    {
        write(1, "Failed to create a new window\n", 31);
        free(prg->mlx);
		return (-1);
    }
	prg->mlx_img = mlx_new_image(prg->mlx, WIN_HORI, WIN_VERT);
	prg->mlx_img->data = mlx_get_data_addr(prg->mlx_img, &prg->mlx_img->bpp,
			&prg->mlx_img->size_line, &prg->mlx_img->image->byte_order);
	mlx_hook(prg->mlx_win, DestroyNotify, 0, NULL, prg);
	mlx_hook(prg->mlx_win, KeyPress, 1, NULL, prg);
	mlx_loop(prg->mlx_win);
    return (true);
}