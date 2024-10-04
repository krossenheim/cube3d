/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 12:16:43 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
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

static char	*fake_itoa(char *rv, int n)
{
	int		size;

	size = get_array_size(n);
	rv[size - 1] = '\0';
	fill_array(rv, n, size);
	return (rv);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*toput;
	char	rv[100];
	int		toput_len;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else
	{
		toput = fake_itoa(rv, n);
		toput_len = ft_strlen(toput);
		write(fd, toput, sizeof(char) * toput_len);
	}
}
