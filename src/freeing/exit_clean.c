/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_clean.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 16:52:18 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/21 15:24:58 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int    exit_clean(t_program *prog)
{
    if (!prog)
        return (-1);
    mlx_destroy_image(prog->mlx, prog->mlx_img);
    mlx_destroy_window(prog->mlx, prog->mlx_win);
    mlx_destroy_display(prog->mlx);
    free(prog->mlx);
    free(prog->keys);
    free(prog);
    exit(0);
}
