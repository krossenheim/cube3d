/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys_onpress.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/21 15:32:33 by jose-lop      #+#    #+#                 */
/*   Updated: 2025/01/04 23:09:25 by jose-lop      ########   odam.nl         */
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

double speedmoving = 0.03;

int		move_forward(void *address)
{
    t_program *p;

    p = (t_program *) address;
    if (!p)
        return (-1);
    p->player.pos_x += p->player.dir_x * speedmoving;
    p->player.pos_y += p->player.dir_y * speedmoving;
	return (1);
}

int		move_back(void *address)
{
    t_program *p;

    p = (t_program *) address;
    if (!p)
        return (-1);
    p->player.pos_x -= p->player.dir_x * speedmoving;
    p->player.pos_y -= p->player.dir_y * speedmoving;
	return (1);
}


int		rotate_left(void *address)
{
    t_program *p;

    p = (t_program *) address;
    if (!p)
        return (-1);
    p->player.pos_y++;
    double speedturning = 0.00002;
	double oldx;
	double oldpx;
	oldx = p->player.dir_x;
	p->player.dir_x = p->player.dir_x * cos(speedturning) - p->player.dir_y  * sin(speedturning);
	p->player.dir_y = oldx * sin(speedturning) + p->player.dir_y  * cos(speedturning);
	oldpx = p->player.plane_x;
	p->player.plane_x = p->player.plane_x * cos(speedturning) - p->player.plane_y * sin(speedturning);
	p->player.plane_y = oldpx * sin(speedturning) + p->player.plane_y * cos(speedturning);
	return (1);
}

int		rotate_right(void *address)
{
    t_program *p;

    p = (t_program *) address;
    if (!p)
        return (-1);
    p->player.pos_y--;
	return (1);
}
