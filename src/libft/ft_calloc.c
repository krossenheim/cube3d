/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 11:59:44 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*p;
	unsigned int	total_bytes;

	total_bytes = nmemb * size;
	p = malloc(total_bytes);
	if (p == NULL)
		return (p);
	ft_bzero(p, total_bytes);
	return (p);
}
