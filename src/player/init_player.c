/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/04 14:48:38 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 14:59:22 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    set_pos(t_map_i *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	printf("\n");

	while (map->cols > i)
	{
		j = 0;
		while (map->rows > j)
        {
            if (map->map[i][j] == 1)
            {
                player->pos_x = i;
                player->pos_y = j;
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
    player->dir_x = 0;
    player->dir_y = -1;
    player->plane_x = 0;
    player->plane_y = 2/3;
    return (true);
}