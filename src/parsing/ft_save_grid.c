/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 08:42:55 by lucas             #+#    #+#             */
/*   Updated: 2016/06/09 18:47:56 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdk.h"

void		ft_open_file(t_gen *gen, char *filename)
{
	gen->fd = open(filename, O_RDONLY);
	if (gen->fd == -1)
		ft_error(gen);
}

int 		***ft_malloc_grid(void)
{
	int		***grid;
	int		z;
	int		y;

	z = 0;
	grid = (int***)malloc(sizeof(int**) * 2);
	if (!grid)
		return (NULL);
	while (z < 2)
	{
		grid[z] = (int**)malloc(sizeof(int*) * 9);
		y = 0;
		while (y < 9)
		{
			grid[z][y] = (int*)malloc(sizeof(int) * 9);
			y++;
		}
		z++;
	}
	return (grid);
}

void		ft_save_grid(t_gen *gen, int ac, char **av)
{
	char	*line;
	char	**split;
	int		x;
	int		i;
	int		y;

	if (ac != 2)
		ft_error(gen);
	ft_open_file(gen, av[1]);
	gen->grid = ft_malloc_grid();
	y = 0;
	i = 0;
	while (get_next_line(gen->fd, &line))
	{
		x = 0;
		i = 0;
		if (ft_strlen(line) < 9)
			continue ;
		split = ft_strsplit(line, ' ');
		while (split[i])
		{
			gen->grid[0][y][x] = ft_atoi(split[i]);
			gen->grid[1][y][x] = ft_atoi(split[i]);
			x++;
			i++;
		}
		free(line);
		y++;
	}
}
