/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/21 14:02:25 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/21 16:11:47 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool malloced_for_keys(int num, t_program *p)
{
    p->keys = malloc(sizeof(t_key_role) * num);
    if (!p->keys)
        return (false);
    return (true);
}

bool	init_keys(t_program *p)
{
	int i;

	if (!p || !malloced_for_keys(N_KEYS_MAPPED, p))
		return (false);
	i = 0;
	while (i < N_KEYS_MAPPED)
	{
		(p->keys + i)->key = (MAPPED_KEYS + i)->key;
		if ((MAPPED_KEYS + i)->func == NULL)
			{
			printf("Warning key %d(%d) has no function attached.\n",
				i,
				(MAPPED_KEYS + i)->key);
				(p->keys + i)->func = debug_keypress;
			}
		else
			(p->keys + i)->func = (MAPPED_KEYS + i)->func;
		i++;
	}
	return (true);
}