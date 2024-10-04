/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 14:05:03 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_memcmp(const void *p1, const void *p2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_p1;
	unsigned char	*ptr_p2;

	ptr_p2 = (unsigned char *) p2;
	ptr_p1 = (unsigned char *) p1;
	i = 0;
	while (n > i)
	{
		if (ptr_p1[i] != ptr_p2[i])
			return (ptr_p1[i] - ptr_p2[i]);
		i++;
	}
	return (0);
}
