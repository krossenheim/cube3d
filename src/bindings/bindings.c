/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bindings.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 13:55:46 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/21 15:33:32 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	exec_key_func(int key, void *params)
{
	int	i;
	t_program *p;

	p = (t_program *) params;
	if (!p)
		return;
	i = 0;
	while (i < N_KEYS_MAPPED)
	{
		if (key == (p->keys + i)->key && (p->keys + i)->func)
			((p->keys + i)->func)(params);
		i++;
	}
}

static int	key_down(int key, void *params)
{
	t_program *p;
	char		*str;
	
	if (!params)
		return (-1);
	p = (t_program *) params;
	exec_key_func(key, params);
	str = ft_itoa(key);
	mlx_clear_window(p->mlx, p->mlx_win);
	mlx_string_put(p->mlx, p->mlx_win, WIN_HORI/2, WIN_VERT/2, 0xFF00, str);
	free(str);
	return (0);
}

bool	do_mlx_hooks(t_program *prg)
{
	if (!prg)
		return (false);
	mlx_hook(prg->mlx_win, DestroyNotify, 0, exit_clean, prg);
	mlx_hook(prg->mlx_win, KeyPress, 1, key_down, prg);
	return (true);
}