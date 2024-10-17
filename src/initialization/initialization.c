/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 14:04:40 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/18 00:34:47 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool    initialize_mlx(t_program *prg)
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
		return (false);
    }
	prg->img.mlx_img = mlx_new_image(prg->mlx, WIN_HORI, WIN_VERT);
    if (!prg->img.mlx_img)
    {
        write(1, "Failed to create a new image\n", 30);
        free(prg->mlx);
		return (false);
    }
	prg->img.addr = mlx_get_data_addr(prg->img.mlx_img,
                            &prg->img.bpp, &prg->img.line_len, &prg->img.endian);
    if (!prg->img.addr)
    {
        write(1, "Failed to allocate memory for image data\n", 42);
        free(prg->mlx);
		return (false);
    }
    mlx_loop_hook(prg->mlx, raycast, prg);
    do_mlx_hooks(prg);
    mlx_loop(prg->mlx);
    return (true);
}

static t_program    *_initialize_program()
{
    t_program   *mainprogram;
    mainprogram = malloc(sizeof(t_program));
    if (!mainprogram)
        write(1, "Insuficcient memory!!!\n", 24);
    if (!mainprogram)
        return (NULL);
    return (mainprogram);
}

t_program    *initialize_program()
{
    t_program   *mainprogram;

    mainprogram = _initialize_program();
    if (!mainprogram)
        return (NULL);
    if (!init_keys(mainprogram))
    {
        free(mainprogram);
        return (NULL);
    }
    if (!parse_map(mainprogram))
    {
        free(mainprogram->keys);
        free(mainprogram);
        return (NULL);
    }
    if (!init_player(mainprogram))
    {
        free(mainprogram->keys);
        free(mainprogram);
        return (NULL);
    }
    if (!initialize_mlx(mainprogram))
    {
        free(mainprogram->keys);
        free(mainprogram);
        return (NULL);
    }
    return (mainprogram);
}