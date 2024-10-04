/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 10:50:44 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;

	i = 0;
	while (s[i] != '\0' || (char) c == '\0')
	{
		if ((char) s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
