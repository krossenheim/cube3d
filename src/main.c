/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 13:53:04 by jose-lop      #+#    #+#                 */
/*   Updated: 2025/01/09 20:00:53 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void start_mlx(t_program *prg)
{
    mlx_loop(prg->mlx);
}

static void print_map(t_map_i *mapinfo)
{
    int i;
    int j;

    i = 0;
    while (mapinfo->cols > i)
    {
        j = 0;
        while (mapinfo->rows > j)
        {
            printf("%i", mapinfo->map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
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
    print_map(program->map_i);
    start_mlx(program);
    // while (1)
    //     continue ;
    exit_clean(program);
    return (0);
}