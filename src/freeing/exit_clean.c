/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_clean.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 16:52:18 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 14:00:17 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void free_map(t_map_i *map)
{
    int i;
    
    i = 0;
    if (!map)
        return ;
    while (i < map->rows)
        {
            free(map->map[i]);
            i++;
        }
    free(map->map);
    free(map);
}

int    exit_clean(t_program *prog)
{
    if (!prog)
        return (-1);
    free_map(prog->map_i);
    mlx_destroy_image(prog->mlx, prog->mlx_img);
    mlx_destroy_window(prog->mlx, prog->mlx_win);
    mlx_destroy_display(prog->mlx);
    free(prog->mlx);
    free(prog->keys);
    free(prog);
    exit(0);
}
