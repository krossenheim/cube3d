/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 17:55:50 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_lstsize(t_list *list)
{
	int		rv;
	t_list	*node;

	if (list == NULL)
		return (0);
	rv = 0;
	node = list;
	while (node != NULL)
	{
		node = node->next;
		rv++;
	}
	return (rv);
}
