/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdk.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 08:42:55 by lucas             #+#    #+#             */
/*   Updated: 2016/06/09 19:15:27 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDK_H
# define SDK_H
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <sys/stat.h>

typedef struct	s_gen
{
	int			***grid;
	int			x;
	int			y;
	int			value;
	int			fd;
}				t_gen;


int 			***ft_malloc_grid(void);
void			ft_save_grid(t_gen *gen, int ac, char **av);
void			ft_show(t_gen *gen);
void			ft_error(t_gen *gen);
void			ft_algo(t_gen *gen);
#endif
