/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 12:07:34 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char	is_contained_in_set(char c, char const *set)
{
	int	i;
	int	exists_in_set;

	exists_in_set = 0;
	i = 0;
	while (set[i] != '\0' && exists_in_set == 0)
	{
		if ((char) c == (char) set[i])
			exists_in_set = 1;
		i++;
	}
	return (exists_in_set);
}

static size_t	get_trim_start(char const *s1, char const *set)
{
	int	rv;

	rv = 0;
	while (is_contained_in_set(s1[rv], set))
		rv++;
	return (rv);
}

static size_t	get_trim_end(char const *s1, char const *set)
{
	int	rv;

	rv = 0;
	while (s1[rv] != '\0')
		rv++;
	rv--;
	while (is_contained_in_set(s1[rv], set))
		rv--;
	return (rv);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	length;
	size_t	source_len;

	if (!s1 || !set)
		return (NULL);
	source_len = ft_strlen(s1);
	start = get_trim_start(s1, set);
	length = get_trim_end(s1, set) - start + 1;
	if (length > source_len)
		length = source_len - start;
	return (ft_substr(s1, start, length));
}
