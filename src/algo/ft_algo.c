/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 08:42:55 by lucas             #+#    #+#             */
/*   Updated: 2016/06/09 19:15:24 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdk.h"

int		ft_modifiable(t_gen *gen)
{
	if (gen->grid[1][gen->x][gen->y] == 0)
		return (1);
	return (0);
}

void	ft_change_value(t_gen *gen)
{
	
}

void	ft_algo(t_gen *gen)
{
	(void)gen;
	while (1)
	{
		if (gen->y >= 9 && gen->x >= 9)
			break ;
		gen->x = 0;
		while (gen->x < 9)
		{
			if (ft_modifiable(gen))
				ft_change_value(gen);
			gen->x++;
		}
		gen->y++;
	}
}
