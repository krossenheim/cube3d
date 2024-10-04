/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/20 13:53:04 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/04 12:06:49 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main()
{
    t_program *mainprogram;
    
    mainprogram = malloc(sizeof(t_program));
    if (!mainprogram)
        write(1, "Insuficcient memory!!!\n", 24);
    if (!mainprogram)
        return (0);
    if (!parse_map(mainprogram))
    {
        return (0);
    }
    
    return (0);
    t_program *program;

    program = initialize_program();
    if (!program)
        {
            printf("Initialize program returns null?\n");
            return (0);
        }
    printf("Hello World\n");
    exit_clean(program);
    return (0);
}