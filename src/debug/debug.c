/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/04 14:15:50 by jose-lop      #+#    #+#                 */
/*   Updated: 2025/01/23 14:15:22 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void player_export_info(t_player *player)
{
    FILE *file = fopen(DEBUG_TEMP_FILENAME, "w");
    if (file == NULL) {
        perror("Failed to open file");
        exit(55);
    }
	
	fprintf(file, "Player position: %.4f, %.4f ", player->pos_x,  player->pos_y);
	fprintf(file, "Player direction: %.4f, %.4f ", player->dir_x,  player->dir_y);
	fprintf(file, "Player plane: %.4f, %.4f ", player->plane_x,  player->plane_y);

	fclose(file);
}

static char *get_player_debugstr(t_program *prg)
{
	int	fd;
	char *line;
	char *tmp;
	char *tmp1;

	tmp = NULL;
	fd = open(DEBUG_TEMP_FILENAME, O_RDONLY, 0666);
	if (fd < 0)
	{
		printf("Cant open file infodump (fatal)\n");
		exit_clean(prg);
	}
	while (fd > 0)
	{
		line = get_next_line(fd);
		tmp1 = tmp;
		tmp = ft_strjoin(tmp, line);
		if (tmp1)
			free(tmp1);
		if (line == NULL)	
		{
			close(fd);
			fd = 0;
		}
		free(line);
	}
	if (fd > 0)
		close(fd);
	return (tmp);
}

static char	*player_debugstr(t_program *prg)
{
	char	*debugstr;

	player_export_info(&prg->player);
	debugstr = get_player_debugstr(prg);
	if (debugstr == NULL)
	{
		printf("Error making player_debugstr\n");
		exit_clean(prg);
		exit(45);
	}
	return (debugstr);
}

void	debug_info_to_screen(t_program *prg)
{
	char *str;
	str = player_debugstr(prg);
    mlx_put_image_to_window(prg->mlx, prg->mlx_win, prg->mlx_img.image, 0, 0);
	mlx_string_put(prg->mlx, prg->mlx_win, 50, 50, 0x40FF40, str);
	free(str);
}

int		debug_keypress(void *address, int key)
{
 	char		*str;
	t_program *p;

	if (!address)
		return (-1);
	p = (t_program *) address;
	printmap(p->map_i);
	str = ft_itoa(key);
	mlx_clear_window(p->mlx, p->mlx_win);
    mlx_string_put(p->mlx, p->mlx_win, WIN_HORI/3, WIN_VERT/3, 0xFF00, "KEY UNBOUND");
	mlx_string_put(p->mlx, p->mlx_win, WIN_HORI/2, WIN_VERT/2, 0xFF00, str);
	free(str);
    return (1);
}

void	printmap(t_map_i *ma)
{
	int	i;
	int	j;

	i = 0;
	printf("\n");

	while (ma->cols > i)
	{
		j = 0;
		while (ma->rows > j)
			{
				printf("%d", ma->map[i][j]);
				j++;
			}
		printf("\n");
		i++;
	}
	printf("\n");

}