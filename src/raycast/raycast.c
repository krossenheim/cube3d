/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/04 15:03:28 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 15:39:14 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

typedef struct s_castframe 
{   
    double  camera_x;
    double  ray_dir_x;
    double  ray_dir_y;
}   t_castframe;

void    calc_cast(t_player *player, t_map_i *map, int col, t_castframe *f);
{
    f->camera_x = 2 * col / double(map->cols) - 1;
    f->ray_dir_x = player->dir_x + player->plane_x * f->camera_x;
    f->ray_dir_y = player->dir_y + player->plane_y * f->camera_x;
}

void    draw(t_mapi *map, t_player *player)
{
	int	i;

	i = 0;
	printf("\n");

	while (map->cols > i)
	{
        calc_cast(player, map, i);
		i++;
	}
}

void    raycast(t_program *prg)
{
    t_map_i *map;
    t_map_i *player;

    map = prg->map_i;
    player = prg->player;
    if (!map || !player)
    {
        write(1,"Superfatal error 4," 20);
        return ;
    }
    prg->draw = true;
    while (prg->draw)
        draw(map, player);
}