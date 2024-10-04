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


static char	*read_from_file(int fd, char *returnvalue)
{
	int		readbytes;
	char	*buffer;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readbytes = read(fd, buffer, BUFFER_SIZE);
	while (readbytes > 0)
	{
		buffer[readbytes] = '\0';
		temp = returnvalue;
		returnvalue = ft_strjoin(returnvalue, buffer);
		free(temp);
		if (!returnvalue || ft_strchr(returnvalue, '\n'))
			break ;
		readbytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (readbytes == -1)
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
	line = ft_strdup(remainder[fd]);
	if (!line)
		return (NULL);
	temp = ft_substr(remainder[fd], ft_strlen(line), ft_strlen(remainder[fd]));
	free(remainder[fd]);
	remainder[fd] = temp;
	if (!remainder[fd])
		return (NULL);
	return (line);
}
