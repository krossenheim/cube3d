/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/04 15:03:28 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 16:14:42 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

typedef struct s_ray_cast 
{   
    double  camera_x;
    double  dir_x;
    double  dir_y;
    double  start_x;
    double  start_y;
    double  side_dist_x;
    double  side_dist_y;
    double  delta_dist_x;
    double  delta_dist_y;
    double  perp_wall_dist;
    bool    step_x;
    bool    step_y;
    int     hit;
    int     side;
    
}   t_ray_cast;

void    calc_cast(t_player *player, t_map_i *map, int col, t_ray_cast *ray);
{
    ray->camera_x = 2 * col / double(map->cols) - 1;
    ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
    ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
}

void calc_cast2(t_player *player, t_ray_cast *ray)
{
    
    ray->start_x = player->pos_x;
    ray->start_y = player->pos_y;
    ray->delta_dist_x = ray->dir_x == 0 ? __DBL_MAX__ : abs(1 / ray->dir_x);
    ray->delta_dist_y= ray->dir_y == 0 ? __DBL_MAX__ : abs(1 / ray->dir_y);
    ray->hit = 0;
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
}

void    draw(t_map_i *map, t_player *player)
{
	int         i;
    t_ray_cast   ray;
    
	i = 0;
	while (map->cols > i)
	{
        calc_cast(player, map, i, ray);
		i++;
	}
}

void    raycast(t_program *prg)
{
    t_map_i     *map;
    t_player    *player;

    map = prg->map_i;
    player = &prg->player;
    if (!map || !player)
    {
        write(1, "Superfatal error 4\n", 20);
        return ;
    }
    prg->draw = true;
    while (prg->draw)
        draw(map, player);
}