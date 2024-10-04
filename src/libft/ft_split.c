/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 12:14:18 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	count_words(char const *s, char c)
{
	const char	*ptr;
	int			rv;
	int			counting;

	ptr = s;
	rv = 0;
	counting = 1;
	while (*ptr != '\0')
	{
		if (*ptr == c && counting == -1)
			counting = 1;
		else if (*ptr != c && counting == 1)
		{
			counting = -1;
			rv++;
		}
		ptr++;
	}
	return (rv);
}

static int	nxtw_len(char *ptr, char sep)
{
	int	i;
	int	counting;
	int	rv;

	i = 0;
	rv = 0;
	counting = 0;
	while (ptr[i] != '\0')
	{
		if (!(counting) && ptr[i] != sep)
			counting = 1;
		if (ptr[i] != sep && counting)
			rv++;
		else if (ptr[i] == sep && counting)
			break ;
		i++;
	}
	return (rv);
}

static int	nxtw_idx(char *ptr, char sep)
{
	int	i;

	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] != sep)
			break ;
		i++;
	}
	return (i);
}

static void	tear_down(char **ptr, int length)
{
	while (length >= 0)
	{
		free(ptr[length]);
		ptr[length] = NULL;
		length--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**rv;
	char	*s_ptr;
	int		size;
	int		i;

	s_ptr = (char *) s;
	size = count_words(s, c) + 1;
	rv = malloc(sizeof(char *) * size);
	if (rv == NULL)
		return (rv);
	rv[size - 1] = NULL;
	i = 0;
	while (i < size - 1)
	{
		rv[i] = ft_substr(s_ptr, nxtw_idx(s_ptr, c), nxtw_len(s_ptr, c));
		if (rv[i] == NULL)
		{
			tear_down(rv, i);
			rv = NULL;
			break ;
		}
		s_ptr = s_ptr + nxtw_idx(s_ptr, c) + nxtw_len(s_ptr, c);
		i++;
	}
	return (rv);
}
