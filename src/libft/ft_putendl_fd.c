/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/16 12:17:10 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 02:38:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*ptr;
	char	size;

	ptr = ft_strjoin(s, "\n");
	size = ft_strlen(s) + 1;
	write(fd, ptr, size);
	free(ptr);
}
