/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   get_next_line.c									:+:	:+:			*/
/*													 +:+					*/
/*   By: jose-lop <jose-lop@student.42.fr>			+#+					 */
/*												   +#+					  */
/*   Created: 2023/11/06 13:39:53 by jose-lop	  #+#	#+#				 */
/*   Updated: 2023/11/07 19:29:18 by jose-lop	  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#include "cube3d.h"

static char	*ft_get_line(char *src)
{
	int	src_len;
	int	line_len;
	int	i;

	line_len = 0;
	src_len = ft_strlen(src);
	i = 0;
	while (i < src_len)
	{
		line_len++;
		if (src[i] == '\n')
			break ;
		i++;
	}
	if (line_len == 0)
		return (NULL);
	return (ft_substr(src, 0, line_len));
}

static char	*read_from_file(int fd, char *returnvalue)
{
	int		readbytes;
	char	*buffer;
	char	*tmp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readbytes = read(fd, buffer, BUFFER_SIZE);
	while (readbytes > 0)
	{
		buffer[readbytes] = '\0';
		if (buffer[0] == '\n')
			break ;
		tmp = returnvalue;
		returnvalue = ft_strjoin(returnvalue, buffer);
		if (tmp)
			free(tmp);
		if (!returnvalue)
			break ;
		readbytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (!returnvalue || readbytes == -1 || ft_strlen(returnvalue) == 0)
	{
		free(returnvalue);
		return (NULL);
	}
	return (returnvalue);
}

char	*get_next_line(int fd)
{
	static char	*remainder[1024];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder[fd] = read_from_file(fd, remainder[fd]);
	if (!remainder[fd])
		return (NULL);
	line = ft_get_line(remainder[fd]);
	if (!line)
		return (NULL);
	temp = ft_substr(remainder[fd], ft_strlen(line), ft_strlen(remainder[fd]));
	free(remainder[fd]);
	remainder[fd] = temp;
	if (!remainder[fd])
		return (NULL);
	return (line);
}
