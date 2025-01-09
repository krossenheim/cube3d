/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/04 15:03:28 by jose-lop      #+#    #+#                 */
/*   Updated: 2025/01/09 18:39:56 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    init_ray(t_player *player, int col, t_ray_cast *ray)
{
    ray->camera_x = 2 * col / ((double) WIN_HORI) -1;
    ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
    ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
    ray->start_x = player->pos_x;
    ray->start_y = player->pos_y;
    ray->delta_dist_x = (ray->dir_x == 0) ? __DBL_MAX__ : fabs(1 / ray->dir_x);
    ray->delta_dist_y = (ray->dir_y == 0) ? __DBL_MAX__ : fabs(1 / ray->dir_y);
	// printf("Dellxy:: %f,%f\n", ray->delta_dist_x, ray->delta_dist_y);
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
            ray->wall_val = map->map[ray->start_x][ray->start_y];
            ray->hit = 1;
        }
      }
}

void    set_perpendicular_distance(t_ray_cast *ray)
{
	if (ray->side == 0)
		ray->perpend_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perpend_dist = (ray->side_dist_y - ray->delta_dist_y);
}

void    calc_lineheight(t_ray_cast *ray)
{
    ray->line_height = (int)(WIN_VERT / ray->perpend_dist);
    ray->draw_start = -ray->line_height / 2 + WIN_VERT / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + WIN_VERT / 2;
    if (ray->draw_end > WIN_VERT)
        ray->draw_end = WIN_VERT -1;
}

void    ver_line(int x, t_ray_cast *ray, t_program *prg)
{
    char    *pixel;
    int     y;

    if(ray->draw_end < ray->draw_start)
    {
        ray->draw_start += ray->draw_end;
        ray->draw_end = ray->draw_start - ray->draw_end;
        ray->draw_start -= ray->draw_end;
    }
    if(ray->draw_end < 0 || ray->draw_start >= WIN_VERT  || x < 0 || x >= WIN_HORI)
		return ;
    if (ray->draw_start < 0)
		ray->draw_start = 0;
	if(ray->draw_end >= WIN_VERT)
		ray->draw_end = WIN_VERT - 1;
    y = ray->draw_start;
    while (y < ray->draw_end)
    {
        // (640, 480, 3)

        // mlx_img.data[0] // pixel 0,0 (R)
        // mlx_img.data[1] // pixel 0,0 (G)
        // mlx_img.data[2] // pixel 0,0 (B)
        // mlx_img.data[3] // pixel 1,0 (R)
        // mlx_img.data[4] // pixel 1,0 (G)
        // mlx_img.data[5] // pixel 1,0 (B)


        // // BYTES_PER_PIXEL = 3 // color
        // // BYTES_PER_PIXEL = 1 // grayscale

        // x = 0
        // y = 1
        // mlx_img.data + y * WIN_HORI + x * 3
        // mlx_img.data + 640 + 0 = 640



        pixel = prg->mlx_img.data
         + y * prg->mlx_img.size_line
         + x * prg->mlx_img.bpp / 8;
		*(int *)pixel = ray->wall_color;
		y++;
    }
    return ;
}
int calls = 0;

void    set_wall_color(t_ray_cast *ray)
{
    ray->wall_color = 0x00FFFF00;
	if (ray->side == 1)
        ray->wall_color *= 0.75;
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
	ft_memset(prg->mlx_img.data, 0, WIN_HORI * WIN_VERT * sizeof(int));
	while (WIN_HORI > i)
	{
        init_ray(player, i, &ray);
        calc_offset_x_y(&ray, player);
        dda(&ray, map);
        set_perpendicular_distance(&ray);
        calc_lineheight(&ray);
        set_wall_color(&ray);
        ver_line(i, &ray, prg);
		i++;
	}
	if (i == 0)
		return ;
	mlx_clear_window(prg->mlx, prg->mlx_win);
    mlx_put_image_to_window(prg->mlx, prg->mlx_win, prg->mlx_img.image, 0, 0);
}



// #include <sys/time.h>
// long	timestamp(void)
// {
// 	struct timeval	t;

// 	gettimeofday(&t, NULL);
// 	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
// }

void    drawdebug(t_program *prg)
{
	int         i;
    char		*pixel;

	i = 0;
	int y = 0;
	ft_memset(prg->mlx_img.data, 0, WIN_HORI * WIN_VERT);
	while (WIN_HORI > i)
	{
		y = 0;
		while (WIN_VERT > y)
		{
		pixel = prg->mlx_img.data + i * prg->mlx_img.size_line + y * prg->mlx_img.bpp / 8;
		if ( y > WIN_VERT * 0.8)
		     *(int *)pixel = 0x00FFF000 + i/2 - y/2;
		else if ( y > WIN_VERT * 0.6)
		     *(int *)pixel = 0x000FF000 + i/2 - y/2;
		else if ( y > WIN_VERT * 0.4)
		     *(int *)pixel = 0x0000FF00 + i/2 - y/2;
		else if ( y > WIN_VERT * 0.2)
		     *(int *)pixel = 0x00F0F0F0 + i/2 - y/2;
		else if ( y > WIN_VERT * 0.1)
		     *(int *)pixel = 0x00F0F00F + i/2 - y/2;
		y++;
		}
		i++;
	}
	if (i == 0)
		return ;
	mlx_clear_window(prg->mlx, prg->mlx_win);
    mlx_put_image_to_window(prg->mlx, prg->mlx_win, prg->mlx_img.image, 0, 0);
	mlx_string_put(prg->mlx, prg->mlx_win, 50, 50, 0x00FFF00, "Top left");
	mlx_string_put(prg->mlx, prg->mlx_win, WIN_HORI - 50, 50, 0x00FFF00, "Top RIGHT");
	mlx_string_put(prg->mlx, prg->mlx_win, WIN_HORI - 50, WIN_VERT - 50, 0x00FFF00, "Bottom Right");
	mlx_string_put(prg->mlx, prg->mlx_win, 50, WIN_VERT - 50, 0x00FFF00, "Bottom left");

}

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
	if (1)
		draw(prg);
	else
		drawdebug(prg);
	calls++;
	printf("%i calls\n", calls);
    return (0);
}
