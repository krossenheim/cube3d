/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 14:05:03 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_p;
	unsigned char	byte;

	byte = (unsigned char) c;
	s_p = (unsigned char *) s;
	while (n > 0)
	{
		if (*s_p == byte)
			return (s_p);
		s_p++;
		n--;
	}
	return (0);
}
