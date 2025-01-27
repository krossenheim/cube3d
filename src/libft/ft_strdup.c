/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:46:41 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 03:15:21 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		j;
	int		l;

	j = 0;
	l = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	copy = (void *)malloc(l + 1);
	if (copy == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		copy[j] = s[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
