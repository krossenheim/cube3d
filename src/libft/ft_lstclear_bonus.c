/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 17:53:45 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 13:51:13 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_node;
	t_list	*prev_node;

	if (lst == NULL || del == NULL)
		return ;
	current_node = *lst;
	while (current_node != NULL)
	{
		prev_node = current_node;
		current_node = current_node->next;
		ft_lstdelone(prev_node, del);
	}
	*lst = NULL;
}
