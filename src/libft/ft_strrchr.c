/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 10:50:44 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*p;

	p = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if ((char) s[i] == (char) c)
		{
			p = (char *) &s[i];
			break ;
		}
		i--;
	}
	return (p);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char arr[] = "This is it last makk!";
// 	int c = 0;

// 	const char *p;

// 	p = ft_strrchr(arr, c);
// 	printf("Pinter: '%s'", p);
// }