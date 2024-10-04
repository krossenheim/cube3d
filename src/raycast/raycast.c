/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/04 15:03:28 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 18:54:45 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    init_ray(t_player *player, t_map_i *map, int col, t_ray_cast *ray)
{
    ray->camera_x = 2 * col / (double) map->cols - 1;
    ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
    ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
    ray->start_x = player->pos_x;
    ray->start_y = player->pos_y;
    ray->delta_dist_x = ray->dir_x == 0 ? __DBL_MAX__ : fabs(1 / ray->dir_x);
    ray->delta_dist_y = ray->dir_y == 0 ? __DBL_MAX__ : fabs(1 / ray->dir_y);
    ray->hit = 0;
}

void    calc_offset_x_y(t_ray_cast *ray, t_player *player)
{
    if (ray->dir_x < 0)
      {
        ray->step_x = -1;
        ray->side_dist_x = (player->pos_x - ray->start_x) * ray->delta_dist_x;
      }
      else
      {
        ray->step_x = 1;
        ray->side_dist_x = (ray->start_x + 1.0 - player->pos_x) * ray->delta_dist_x;
      }
      if (ray->dir_y < 0)
      {
        ray->step_y = -1;
        ray->side_dist_y = (player->pos_y - ray->start_y) * ray->delta_dist_y;
      }
      else
      {
        ray->step_y = 1;
        ray->side_dist_y = (ray->start_y + 1.0 - player->pos_y) * ray->side_dist_y;
      }
}

void      dda(t_ray_cast *ray, t_map_i *map)
{
          //perform DDA
      while (ray->hit == 0)
      { 
        //jump to next map square, either in x-direction, or in y-direction
        if (ray->side_dist_x < ray->side_dist_y)
        {
          ray->side_dist_x += ray->delta_dist_x;
          ray->start_x += ray->step_x;
          ray->side = 0;
        }
        else
        {
          ray->delta_dist_y += ray->delta_dist_y;
          ray->start_y += ray->step_y;
          ray->side = 1;
        }
        //Check if ray has hit a wall
        if (map->map[ray->start_x][ray->start_y] == 1)
        {
            printf("Ray hit at %d,%d\n",ray->start_x, ray->start_y);
            ray->hit = 1;
        }
      } 
}
// void calc_cast2(t_player *player, t_ray_cast *ray)
// {
    

// //       //length of ray from current position to next x or y-side
// //       double sideDistX;
// //       double sideDistY;

// //        //length of ray from one x or y-side to next x or y-side
// //       double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
// //       double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
// //       double perpWallDist;

// //       //what direction to step in x or y-direction (either +1 or -1)
// //       int stepX;
// //       int stepY;

// //       int hit = 0; //was there a wall hit?
// //       int side; //was a NS or a EW wall hit?
// }

void    draw(t_map_i *map, t_player *player)
{
	int         i;
    t_ray_cast   ray;
    
	i = 0;
	while (map->cols > i)
	{
        init_ray(player, map, i, &ray);
        calc_offset_x_y(&ray, player);
        dda(&ray, map);
        if (ray.hit)
        {
            if(ray.side == 0)
                ray.perpend_dist = (ray.side_dist_x - ray.delta_dist_x);
            else
                ray.perpend_dist = (ray.side_dist_y - ray.delta_dist_y);
            printf("Distance is %f\n", ray.perpend_dist);
        }

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
    // while (prg->draw)
        draw(map, player);
}