/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 17:51:19 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastnode;

	if (lst == NULL)
		return (NULL);
	lastnode = lst;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	return (lastnode);
}
