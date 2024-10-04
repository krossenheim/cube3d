/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 17:53:12 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_list	*ft_lstmap(t_list *lst, void*(*f)(void *), void (*del)(void *))
{
	t_list	*rv_head;

	if (lst == NULL)
		return (NULL);
	rv_head = ft_lstnew(f(lst->content));
	if (rv_head == NULL)
	{
		ft_lstclear(&rv_head, del);
		return (NULL);
	}
	rv_head->next = ft_lstmap(lst->next, f, del);
	return (rv_head);
}
