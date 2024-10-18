/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/04 15:03:28 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/18 11:48:14 by jose-lop      ########   odam.nl         */
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
    ray->line_height = (int)(HEIGHT_SCALE / ray->perpend_dist);
    ray->draw_start = -ray->line_height / 2 + HEIGHT_SCALE / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + HEIGHT_SCALE / 2;
    if (ray->draw_end > HEIGHT_SCALE)
        ray->draw_end = HEIGHT_SCALE -1;
}

void    ver_line(int x, t_ray_cast *ray, t_map_i *map, t_program *prg)
{
    char    *pixel;
    int     y;
    
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
    y = ray->draw_start;
    while (y <= ray->draw_end)
    {
        pixel = prg->mlx_img.data
         + y++ * prg->mlx_img.size_line 
         + x * (prg->mlx_img.bpp / 8);
        *(int *)pixel = ray->wall_color;
    }
    return ;
}

void    set_wall_color(t_ray_cast *ray)
{
    int     maxindex = 4;
    int     colors[] = {255, 65280, 1677214, 1671100, 825000};
    int     picked_color;

    while (ray->wall_val < 0)
        ray->wall_val += maxindex;
    while (ray->wall_val > maxindex)
        ray->wall_val -= maxindex;
    picked_color = (int) colors[ray->wall_val];
    if (ray->side == 1)
        picked_color /= 2;
    ray->wall_color = picked_color;
}

void    draw(t_program *prg)
{
	int         i;
    t_ray_cast   ray;
    t_map_i     *map;
    t_player    *player;

    map = prg->map_i;
    player = &prg->player;
	i = 0;
	while (map->cols > i)
	{
        init_ray(player, map, i, &ray);
		printf("%f,%f,%f,%d,%d\n\n",
		 ray.camera_x, ray.dir_x, ray.delta_dist_x, ray.hit, ray.start_x);


        calc_offset_x_y(&ray, player);
        dda(&ray, map);
        set_perpendicular_distance(&ray);
        calc_lineheight(&ray);
        set_wall_color(&ray);
        ver_line(i, &ray, map, prg);
		i++;
	}
	if (i == 0)
		return ;
    mlx_clear_window(prg->mlx, prg->mlx_win);
    mlx_put_image_to_window(
		prg->mlx,

	 prg->mlx_win, 

	 prg->mlx_img.image, 

	 0, 
	 
	 0);
    printf("Drawing done\n\n");
}

int calls = 0;

int    raycast(t_program *prg)
{
    t_map_i     *map;
    t_player    *player;

    map = prg->map_i;
    player = &prg->player;
    if (!map || !player)
    {
        write(1, "Superfatal error 4\n", 20);
        return (1);
    }
	printf("DRAWING FOR THE %d time\n", calls + 1);
    draw(prg);
	calls++;
    return (0);
}