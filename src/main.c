/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 13:53:04 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 14:21:38 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main()
{
    t_program *program;

    program = initialize_program();
    if (!program)
	{
		write(1, "Could not initialize program.\n", 31);
		return (0);
	}
    exit_clean(program);
    return (0);
}