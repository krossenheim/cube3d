/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/04 14:48:38 by jose-lop      #+#    #+#                 */
/*   Updated: 2025/01/23 12:14:00 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    set_pos(t_map_i *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map->cols > i)
	{
		j = 0;
		while (map->rows > j)
        {
            if (map->map[i][j] == 0)
            {
                player->pos_x = (double) i;
                player->pos_y = (double) j;
                printf("Player placed at %f,%f", player->pos_x, player->pos_y);
                return ;
            }
            j++;
        }
		i++;
	}
}

bool    init_player(t_program *prg)
{
    t_map_i     *map;
    t_player    *player;

    map = prg->map_i;
    player = &(prg->player);
    if (!map || !player)
    {
        write(1, "Megafatal error\n", 17);
        return (false);
    }
    set_pos(map, player);
    player->dir_x = -1.0;
    player->dir_y = 0.0;
    player->plane_x = 0.0;
    player->plane_y = 0.66;
    return (true);
}