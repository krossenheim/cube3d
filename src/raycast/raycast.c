/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/04 15:03:28 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 15:43:15 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

typedef struct s_ray_hit 
{   
    double  camera_x;
    double  ray_dir_x;
    double  ray_dir_y;
    
}   t_ray_hit;

void    calc_cast(t_player *player, t_map_i *map, int col, t_ray_hit *f);
{
    f->camera_x = 2 * col / double(map->cols) - 1;
    f->ray_dir_x = player->dir_x + player->plane_x * f->camera_x;
    f->ray_dir_y = player->dir_y + player->plane_y * f->camera_x;
}

// void calc_cast2()
// {
//  //which box of the map we're in
//       int mapX = int(posX);
//       int mapY = int(posY);

//       //length of ray from current position to next x or y-side
//       double sideDistX;
//       double sideDistY;

//        //length of ray from one x or y-side to next x or y-side
//       double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
//       double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
//       double perpWallDist;

//       //what direction to step in x or y-direction (either +1 or -1)
//       int stepX;
//       int stepY;

//       int hit = 0; //was there a wall hit?
//       int side; //was a NS or a EW wall hit?
// }

void    draw(t_mapi *map, t_player *player)
{
	int	i;

	i = 0;
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