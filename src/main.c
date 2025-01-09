/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 13:53:04 by jose-lop      #+#    #+#                 */
/*   Updated: 2025/01/09 16:55:39 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void start_mlx(t_program *prg)
{
    mlx_loop(prg->mlx);
}

int main()
{
    t_program *program;

    program = initialize_program();
    if (!program)
	{
		write(1, "Could not initialize program.\n", 31);
		return (0);
	}
    start_mlx(program);
    while (1)
        continue ;
    exit_clean(program);
    return (0);
}