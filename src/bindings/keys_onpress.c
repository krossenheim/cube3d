/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys_onpress.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/21 15:32:33 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/21 15:34:20 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		escape_pressed(void *address)
{
    t_program *p;

	printf("Quitting '%s' because escape was pressed.\n", WIN_NAME);
    p = (t_program *) address;
    if (!p)
        return (-1);
    exit_clean(p);
	return (1);
}
