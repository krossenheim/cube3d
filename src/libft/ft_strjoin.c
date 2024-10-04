/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 12:12:57 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		size;
	char	*concatenated;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = s1_len + s2_len + 1;
	concatenated = malloc(size * sizeof(char));
	if (concatenated == NULL)
		return (concatenated);
	i = 0;
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			concatenated[i] = s1[i];
		else
			concatenated[i] = s2[i - s1_len];
		i++;
	}
	concatenated[i] = '\0';
	return (concatenated);
}
