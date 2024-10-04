/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 12:00:19 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length_to_match;

	length_to_match = ft_strlen(little);
	if (length_to_match == 0)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[j])
		{
			j++;
			i++;
			if (length_to_match == j)
				return ((char *) &big[i - j]);
			continue ;
		}
		i = (i - j) + 1;
		j = 0;
	}
	return (NULL);
}
