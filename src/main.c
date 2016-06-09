/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 08:42:32 by lucas             #+#    #+#             */
/*   Updated: 2016/06/09 18:59:28 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdk.h"

void	ft_show(t_gen *gen)
{
	int	x;
	int	y;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
		{
			ft_putnbr(gen->grid[1][y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int		main(int ac, char **av)
{
	t_gen	gen;

	gen.x = 0;
	gen.y = 0;
	ft_save_grid(&gen, ac, av);
	ft_show(&gen);
	ft_algo(&gen);
	return (0);
}
