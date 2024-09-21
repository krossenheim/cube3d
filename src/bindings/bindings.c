/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bindings.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 13:55:46 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/21 16:08:35 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	exec_key_func(int key, void *params)
{
	int	i;
	t_program *p;

	p = (t_program *) params;
	if (!p)
		return (1);
	i = 0;
	while (i < N_KEYS_MAPPED)
	{
		if (key == (p->keys + i)->key && (p->keys + i)->func)
			((p->keys + i)->func)(params, key);
		i++;
	}
	return (0);
}

bool	do_mlx_hooks(t_program *prg)
{
	if (!prg)
		return (false);
	mlx_hook(prg->mlx_win, DestroyNotify, 0, exit_clean, prg);
	mlx_hook(prg->mlx_win, KeyPress, 1, exec_key_func, prg);
	return (true);
}
