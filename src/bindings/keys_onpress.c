/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys_onpress.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/21 15:32:33 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/21 16:03:24 by jose-lop      ########   odam.nl         */
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

int		debug_keypress(void *address, int key)
{
 	char		*str;
	t_program *p;

	if (!address)
		return (-1);
	p = (t_program *) address;
	str = ft_itoa(key);
	mlx_clear_window(p->mlx, p->mlx_win);
	mlx_string_put(p->mlx, p->mlx_win, WIN_HORI/2, WIN_VERT/2, 0xFF00, str);
	free(str);
    return (1);
}
