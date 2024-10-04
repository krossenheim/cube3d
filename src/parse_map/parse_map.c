/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/03 23:30:52 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 13:57:22 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static t_list    *get_map_raw(char * path)
{
    int     map_fd;
    t_list  *first;
    t_list  *new;
    char    *line;

    map_fd = open(path, O_RDONLY, 0666);
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
        if (!line || *line == '\0')
            break ;
        new = ft_lstnew(ft_strdup(line));
        if (!first)
            first = new;
        if (!new->content)
        {
            write(1, "Malloc error\n", 14);
            return (false);
        }
        ft_lstadd_back(first, new);
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
        {
            printf("Notty: '%s'\n", (char *) rawmap->content);
            write(1, "k", 1);
            return (false);
        }
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

bool    malloced_cols_success(t_map_i *map)
{
    int     i;
    bool    teardown;

    teardown = false;
    i = 0;
    while (map->rows > i)
    {
        map->map[i] = malloc(sizeof(int) * map->cols);
        if (!map->map[i])
        {
            teardown = true;
            write(1, "Malloc error soup", 18);
            break;
        }
        i++;
    }
    while (teardown && i >= 0)
    {
        free(map->map[i]);
        i--;
    }
    return (!teardown);
}
bool    parse_map(t_program *prog)
{
    t_list  *raw;

    raw = get_map_raw("testmap");
	if (raw == NULL)
		return (false);
	if (!valid_map(raw))
	{
		printf("Invalid map\n");
		ft_lstclear(&raw, clean_map_raw);
		return (false);
	}
    prog->map_i = malloc(sizeof(t_map_i));
    if (!prog->map_i)
    {
        write(1, "Malloc no memory parsemap 1", 28);
        return (false);
    }
    prog->map_i->rows = ft_lstsize(raw);
    prog->map_i->cols = ft_strlen(raw->content);
    prog->map_i->map = malloc(sizeof(int *) * prog->map_i->rows);
    if (!prog->map_i->map)
    {
        write(1, "Malloc no memory parsemap 32", 28);
        ft_lstclear(&raw, clean_map_raw);
        free(prog->map_i);
        return(false);
    }
    if (!malloced_cols_success(prog->map_i))
    {
        write(1, "Malloc no memory parsemap 43", 28);
        ft_lstclear(&raw, clean_map_raw);
        free(prog->map_i->map);
        free(prog->map_i);
        return (false);
    }
    ft_lstclear(&raw, clean_map_raw);
    return (true);
}