/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/03 23:30:52 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 04:13:31 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static t_list    *get_map_raw(char * path)
{
    int     map_fd;
    t_list  *first;
    t_list  *new;
    char    *line;

    map_fd = open(path, O_RDONLY);
    first = NULL;
    if (map_fd < 0)
    {
        write(1, "Could not open file ", 21);
        write(1, path, ft_strlen(path));
        write(1, "\n", 1);
        return (NULL);
    }
    while (1)
    {
        line = get_next_line(map_fd);
		printf("a%s\n", line);
        if (!line || *line == '\0')
            break ;
        new = ft_lstnew(ft_strdup(line));
        if (!first)
            first = new;
        // if (!new->content)
        // {
        //     write(1, "Malloc error\n", 14);
        //     return (false);
        // }
        ft_lstadd_back(&first, new);
        free(line);
    }
    if (line)
        free(line);
    close(map_fd);
    if (!first)
        write(1, "Map file is empty.", 15);
    return (first);
}

void    clean_map_raw(void *content)
{
    t_list *node;

    node = (t_list *) content;
    free(node->content);
    free(node);
}

bool    ones_and_zeros_only(char *str)
{
    while (str && *str)
    {
        if (*str != '1' && *str != '0')
            return (false);
        str++;
    }
    return (true);
}

bool    valid_map(t_list *rawmap)
{
    size_t		len;
	bool	started;

	started = false;
    while (rawmap)
    {
		if (!ones_and_zeros_only((char *) rawmap->content))
			return (false);
		if (started == false)
		{
			len = ft_strlen((char *) rawmap->content);
			started = true;
		}
		else if (ft_strlen((char *) rawmap->content) !=  len)
			return (false);
		rawmap = rawmap->next;
    }
    return (true);
}

bool    parse_map(t_program *prog)
{
    t_list  *raw;

    raw = get_map_raw("testmap");
	if (!valid_map(raw))
	{
		printf("Invalid map\n");
		ft_lstclear(&raw, clean_map_raw);
		return (NULL);
	}
    printf("Our map has '%d' rows\n", ft_lstsize(raw));
    prog->map_i = malloc(sizeof(t_map_i));
    prog->map_i->rows = ft_lstsize(raw);
    prog->map_i->map = malloc(sizeof(int *) * prog->map_i->rows);

    ft_lstclear(&raw, clean_map_raw);
    return (NULL);
}