/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/21 13:42:23 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/21 13:42:35 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	get_array_size(int n)
{
	int	div;
	int	ct;

	ct = 1;
	div = n;
	while (div != 0)
	{
		div = div / 10;
		ct ++;
	}
	if (n < 0)
		ct++;
	return (ct);
}

static void	fill_array(char *arr, int n, int size)
{
	int	div;
	int	mod;
	int	arr_idx;

	arr_idx = 1;
	div = n;
	if (div < 0)
	{
		div *= -1;
		arr[0] = '-';
	}
	while (div != 0)
	{
		mod = div % 10;
		arr[size - 1 - arr_idx++] = mod + 48;
		div = div / 10;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*rv;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	size = get_array_size(n);
	rv = malloc(sizeof(char) * size);
	if (rv == NULL)
		return (NULL);
	rv[size - 1] = '\0';
	fill_array(rv, n, size);
	return (rv);
}
