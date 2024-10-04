/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/04 15:03:28 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 22:22:14 by jose-lop      ########   odam.nl         */
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
        if (map->map[ray->start_x][ray->start_y] > 0)
        {
            printf("Ray hit at %d,%d\n",ray->start_x, ray->start_y);
            ray->wall_val = map->map[ray->start_x][ray->start_y];
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

void    set_perpendicular_distance(t_ray_cast *ray)
{
    if (ray->hit)
    {
        if(ray->side == 0)
            ray->perpend_dist = (ray->side_dist_x - ray->delta_dist_x);
        else
            ray->perpend_dist = (ray->side_dist_y - ray->delta_dist_y);
    }
}

void    calc_lineheight(t_ray_cast *ray)
{
    ray->lineHeight = (int)(HEIGHT_SCALE / ray->perpend_dist);
    ray->draw_start = -ray->lineHeight / 2 + HEIGHT_SCALE / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + HEIGHT_SCALE / 2;
    if (ray->draw_end > HEIGHT_SCALE)
        ray->draw_end = HEIGHT_SCALE -1;
}

void    ver_line(int x, t_ray_cast *ray, t_map_i *map)
{
    if(ray->draw_end < ray->draw_start) 
    {
        ray->draw_start += ray->draw_end;
        ray->draw_end = ray->draw_start - ray->draw_end;
        ray->draw_start -= ray->draw_end;
    }
    if(ray->draw_end < 0 || ray->draw_start >= HEIGHT_SCALE  || x < 0 || x >= map->cols)
        return ;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    if(ray->draw_end >= map->cols)
        ray->draw_end = HEIGHT_SCALE - 1;
  return ;
}

void    set_wall_color(t_ray_cast *ray)
{
    int     color_count = 5;
    int		colors[color_count] = {BBLK, BRED, BGRN, BYEL, BBLU};
    int     picked_color;
    while (ray->wall_val < 0)
        ray->wall_val += color_count - 1;
    while (ray->wall_val > color_count)
        ray->wall_val -= color_count - 1;
    picked_color = colors[ray->wall_val];
    if (ray->side == 1)
        picked_color /= 2;
    ray->wall_color = picked_color;
}

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
        set_perpendicular_distance(&ray);
        calc_lineheight(&ray);
        set_wall_color(&ray);
        ver_line(i, &ray, map);
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