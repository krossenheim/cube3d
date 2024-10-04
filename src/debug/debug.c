/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/04 14:15:50 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 14:44:35 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		debug_keypress(void *address, int key)
{
 	char		*str;
	t_program *p;

	if (!address)
		return (-1);
	p = (t_program *) address;
	printmap(p->map_i);
	str = ft_itoa(key);
	mlx_clear_window(p->mlx, p->mlx_win);
    mlx_string_put(p->mlx, p->mlx_win, WIN_HORI/3, WIN_VERT/3, 0xFF00, "KEY UNBOUND");
	mlx_string_put(p->mlx, p->mlx_win, WIN_HORI/2, WIN_VERT/2, 0xFF00, str);
	free(str);
    return (1);
}

void	printmap(t_map_i *ma)
{
	int	i;
	int	j;

	i = 0;
	printf("\n");

	while (ma->cols > i)
	{
		j = 0;
		while (ma->rows > j)
			{
				printf("%d", ma->map[i][j]);
				j++;
			}
		printf("\n");
		i++;
	}
	printf("\n");

}