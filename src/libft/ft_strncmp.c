/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:30:56 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	s1_ptr = (unsigned char *) s1;
	s2_ptr = (unsigned char *) s2;
	i = 0;
	while (s1_ptr[i] != '\0' || s2_ptr[i] != '\0')
	{
		if (i >= n)
			break ;
		if (s1_ptr[i] != s2_ptr[i])
			return (s1_ptr[i] - s2_ptr[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char s1[] = "This is the first one.";
// 	char s2[] = "This is the first one";
// 	int ans;

// 	int max =33;

// 	ans = strncmp(s1,s2,max);
// 	printf("Up to %d: '%d'", max, ans);

// }