/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas    <lucas   @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 08:42:55 by lucas             #+#    #+#             */
/*   Updated: 2016/06/06 01:23:58 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <sys/stat.h>
# define WIN_X 800
# define WIN_Y 800
# define MOVE 5
# define THETA 0.09
//# define THETA 3.14159265359 / 2

typedef struct	s_mat
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	e;
	double	f;
	double	g;
	double	h;
	double	i;
	double	j;
	double	k;
	double	l;
	double	m;
	double	n;
	double	o;
	double	p;
}				t_mat;

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	double	o;
	double	old_z;
}				t_point;

typedef struct s_img
{
	void		*img;
	char		*data;
	int			bits;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_gen
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			z;
	double		zoom;
	t_img 		*img;
	t_mat		mat;
	char		*filename;
	t_point 	*origin;
	t_point		***map;
}				t_gen;

/* MLX */
void			ft_create_window(t_gen *gen);

/* Parsing */
void			ft_save_map(int ac, char **av, t_gen *gen);
void			ft_save_list(t_point *new, char *line, t_gen *gen);
int				ft_isdir(char *filename);
int				ft_isfile(char *filename);
void 			ft_ini_origin(t_gen *gen);

/* Gestion Erreur */
void			ft_error_files(int i);
void			ft_error_pass(void);
void			ft_error_map(t_gen *gen);

/* Moves */
int				ft_mouse_hook(int button, int x, int y, t_gen *gen);
int				ft_key_hook(int keycode, t_gen *gen);
void			ft_divise(t_gen *gen);
void			ft_multiply(t_gen *gen);
void			ft_rotate_x(t_gen *gen);
void			ft_rotate_xx(t_gen *gen);
void			ft_rotate_y(t_gen *gen);
void			ft_rotate_yy(t_gen *gen);
void			ft_rotate_z(t_gen *gen);
void			ft_proj_ortho(t_gen *gen);

/* Matrices */
void			ft_init_mat(t_gen *gen);
void			ft_app_matrice(t_gen *gen);

/* Affichage */
void			ft_show(t_gen *gen);
void			ft_show_map(t_gen *gen);
void 			ft_init_point(t_gen *gen, t_point *p);

/* Draw Line */
void			ft_put_pixel(t_gen *gen, int x, int y, int z, int z2);
void    		ft_draw_line(t_gen *gen, t_point *p1, t_point *p2);
void			ft_choose_color(int *r, int *v, int *b, int z, int z2);
void			octan_1(t_gen *gen, t_point *p1, t_point *p2);
void			octan_2(t_gen *gen, t_point *p1, t_point *p2);
void			octan_3(t_gen *gen, t_point *p1, t_point *p2);
void			octan_4(t_gen *gen, t_point *p1, t_point *p2);
#endif
