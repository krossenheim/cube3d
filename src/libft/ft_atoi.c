/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 14:38:09 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	ft_isspace(int c)
{
	if ((9 <= c && 13 >= c) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *p)
{
	char	*ptr;
	int		rv;
	int		isneg;

	ptr = (char *)p;
	rv = 0;
	isneg = 0;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-' )
			isneg = 1;
		ptr++;
	}
	while (*ptr != '\0' && ft_isdigit(*ptr))
	{
		rv *= 10;
		rv += *(ptr) - 48;
		ptr++;
	}
	if (isneg)
		return (-rv);
	return (rv);
}
