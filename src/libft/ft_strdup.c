/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/21 13:43:54 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/21 13:44:07 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*p;
	int		i;

	size = 1;
	if (s1 != NULL)
		size += ft_strlen(s1);
	p = malloc(sizeof(char) * size);
	if (p == NULL)
		return (p);
	i = 0;
	while (i < size - 1)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
