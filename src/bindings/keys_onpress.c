/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys_onpress.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/21 15:32:33 by jose-lop      #+#    #+#                 */
/*   Updated: 2025/01/23 14:36:14 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		escape_pressed(void *address)
{
    t_program *p;

	printf("Quitting '%s' because escape was pressed.\n", WIN_NAME);
    p = (t_program *) address;
    if (!p)
        return (-1);
    exit_clean(p);
	return (1);
}

double speedmoving = 0.1f;

int		move_forward(void *address)
{
    t_program *p;
	int			**maparray;

    p = (t_program *) address;
    if (!p)
		return (-1);
	maparray = p->map_i->map;
	if (maparray[(int)(p->player.pos_x + p->player.dir_x * speedmoving)][(int)p->player.pos_y] == 0)
		p->player.pos_x += p->player.dir_x * speedmoving;
	if (maparray[(int)p->player.pos_x][(int)(p->player.pos_y + p->player.dir_y * speedmoving)] == 0)
		p->player.pos_y += p->player.dir_y * speedmoving;
	return (1);
}

int		move_back(void *address)
{
    t_program *p;
	int			**maparray;

    p = (t_program *) address;
    if (!p)
		return (-1);
	maparray = p->map_i->map;
	if (maparray[(int)(p->player.pos_x - p->player.dir_x * speedmoving)][(int)p->player.pos_y] == 0)
		p->player.pos_x -= p->player.dir_x * speedmoving;
	if (maparray[(int)p->player.pos_x][(int)(p->player.pos_y - p->player.dir_y * speedmoving)] == 0)
		p->player.pos_y -= p->player.dir_y * speedmoving;
	return (1);
}

int		strafe_left(void *address)
{
    t_program *p;
	int			**maparray;
	// Swap the direction vectors and negate one
    p = (t_program *) address;
    if (!p)
		return (-1);
	maparray = p->map_i->map;
	if (maparray[(int)(p->player.pos_x - p->player.dir_y * speedmoving)][(int)p->player.pos_y] == 0)
		p->player.pos_x -= p->player.dir_x * speedmoving;
	if (maparray[(int)p->player.pos_x][(int)(p->player.pos_y + p->player.dir_x * speedmoving)] == 0)
		p->player.pos_y += p->player.dir_y * speedmoving;
	return (1);
}

int		strafe_right(void *address)
{
    t_program *p;
	int			**maparray;
	// Swap the direction vectors and negate one

    p = (t_program *) address;
    if (!p)
		return (-1);
	maparray = p->map_i->map;
	if (maparray[(int)(p->player.pos_x + p->player.dir_y * speedmoving)][(int)p->player.pos_y] == 0)
		p->player.pos_x += p->player.dir_x * speedmoving;
	if (maparray[(int)p->player.pos_x][(int)(p->player.pos_y - p->player.dir_x * speedmoving)] == 0)
		p->player.pos_y -= p->player.dir_y * speedmoving;
	return (1);
}

int		rotate_left(void *address)
{
    t_program *p;

    p = (t_program *) address;
    if (!p)
        return (-1);
    double speedturning = 0.2;
	double oldx;
	double oldpx;
	oldx = p->player.dir_x;
	p->player.dir_x = p->player.dir_x * cos(speedturning) - p->player.dir_y  * sin(speedturning);
	p->player.dir_y = oldx * sin(speedturning) + p->player.dir_y  * cos(speedturning);
	oldpx = p->player.plane_x;
	p->player.plane_x = p->player.plane_x * cos(speedturning) - p->player.plane_y * sin(speedturning);
	p->player.plane_y = oldpx * sin(speedturning) + p->player.plane_y * cos(speedturning);
	
	p->player.dir_x = (fabs(p->player.dir_x) < 1e-6) ? 0 : p->player.dir_x;
	p->player.dir_y = (fabs(p->player.dir_y) < 1e-6) ? 0 : p->player.dir_y;
	
	p->player.plane_x = (fabs(p->player.plane_x) < 1e-6) ? 0 : p->player.plane_x;
	p->player.plane_y = (fabs(p->player.plane_y) < 1e-6) ? 0 : p->player.plane_y;
	
	return (1);
}

int		rotate_right(void *address)
{
    t_program *p;

    p = (t_program *) address;
    if (!p)
        return (-1);
    double speedturning = -0.2;
	double oldx;
	double oldpx;
	oldx = p->player.dir_x;
	p->player.dir_x = p->player.dir_x * cos(speedturning) - p->player.dir_y  * sin(speedturning);
	p->player.dir_y = oldx * sin(speedturning) + p->player.dir_y  * cos(speedturning);
	oldpx = p->player.plane_x;
	p->player.plane_x = p->player.plane_x * cos(speedturning) - p->player.plane_y * sin(speedturning);
	p->player.plane_y = oldpx * sin(speedturning) + p->player.plane_y * cos(speedturning);
	
	p->player.dir_x = (fabs(p->player.dir_x) < 0.000001) ? 0 : p->player.dir_x;
	p->player.dir_y = (fabs(p->player.dir_y) < 0.000001) ? 0 : p->player.dir_y;
	
	p->player.plane_x = (fabs(p->player.plane_x) < 0.000001) ? 0 : p->player.plane_x;
	p->player.plane_y = (fabs(p->player.plane_y) < 0.000001) ? 0 : p->player.plane_y;
	return (1);
}
