/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:07:19 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/26 12:07:52 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define WH 900

# define YELLOW 0x00FFFF00
# define PURP 0x008B00FF

typedef struct s_cpx
{
	double	r;
	double	i;
}	t_cpx;

typedef struct s_serc
{
	t_cpx	min;
	t_cpx	max;
	double	max_iter;
}	t_serc;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_x0y
{
	double	x;
	double	y;
	double	cx_r;
	double	cx_i;
}	t_x0y;

typedef struct s_src
{
	void		*mlx;
	void		*mlx_win;
	t_img		data;
	char		*name;
	t_serc		serc;
	int			set_flag;
	t_cpx		set_j;
}	t_src;

/* Validation args */
int			ft_valid(int ac, char **av, t_src *s);

/* Utils */
double		ft_atoi_f(const char *str);
void		ft_erroer(char *str);
void		ft_set_cpx(t_cpx *s, double r, double i);

/* Init */
void		ft_init(t_src *s);

/* Drow */
void		ft_put_pixel(t_img *img, int x, int y, int color);
void		ft_gate_color(int iter, t_src *s, double y, double x);

/* Fractals */
void		ft_burningship(t_src *s, t_serc serc, double p_y, double p_x);
void		ft_mandelbrot(t_src *s, t_serc lims, double col, double row);
void		ft_julia(t_src *s, t_serc serc, double p_y, double p_x);

/* Render */
void		ft_wasd(int keycode, t_src *s);
int			ft_render(t_src *s);
int			ft_scale_re(int flag, t_src *s);
int			ft_handle_keypress(int keysym, t_src *data);
int			ft_mouse_hook(int keycode, int x, int y, t_src *s);

#endif
