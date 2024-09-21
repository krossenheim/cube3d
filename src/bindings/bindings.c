/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bindings.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 13:55:46 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/21 13:49:28 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	key_down(int key, void *cnt)
{
	t_program *p;
	char		*str;
	
	if (!cnt)
		return (-1);
	p = (t_program *) cnt;
	str = ft_itoa(key);
	mlx_clear_window(p->mlx, p->mlx_win);
	mlx_string_put(p->mlx, p->mlx_win, WIN_HORI/2, WIN_VERT/2, 0xFF00, str);
	free(str);
	return (0);
}

bool	bind_keys(t_program *prg)
{
	if (!prg)
		return (false);
	mlx_hook(prg->mlx_win, DestroyNotify, 0, exit_clean, prg);
	mlx_hook(prg->mlx_win, KeyPress, 1, key_down, prg);
	return (true);
}