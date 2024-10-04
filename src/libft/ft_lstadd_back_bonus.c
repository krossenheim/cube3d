/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 17:51:02 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 13:30:50 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (lst == new)
		return ;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
}
