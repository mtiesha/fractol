/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:07:19 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/26 20:38:31 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	ft_recompil(t_src *s)
{
	mlx_destroy_image(s->mlx, s->data.img);
	s->data.img = mlx_new_image(s->mlx, WH, WH);
	if (NULL == s->data.img)
		ft_erroer("IMG Error");
	s->data.addr = mlx_get_data_addr(s->data.img, \
			&s->data.bits_per_pixel, &s->data.line_length, \
			&s->data.endian);
	if (NULL == s->data.img)
		ft_erroer("IMG Fill(bpp etc) Error");
	if ('a' == s->name[1])
		ft_handle_keypress(109, s);
	else if ('l' == s->name[2])
		ft_handle_keypress(106, s);
	else if ('r' == s->name[2])
		ft_handle_keypress(98, s);
}

int	ft_scale_re(int flag, t_src *s)
{
	if (1 == flag)
	{
		s->serc.max_iter += 1;
		ft_recompil(s);
	}
	if (0 == flag)
	{
		s->serc.max_iter -= 1;
		ft_recompil(s);
	}
	return (0);
}

void	ft_zoom_p(t_src *s, double a, double b)
{
	double	z;

	ft_scale_re(1, &(*s));
	z = (s->serc.max.r - s->serc.min.r) * a * 0.10;
	s->serc.max.r -= (s->serc.max.r - s->serc.min.r) * (1.0 - a) * 0.10;
	s->serc.min.r += z;
	z = (s->serc.max.i - s->serc.min.i) * b * 0.10;
	s->serc.max.i -= (s->serc.max.i - s->serc.min.i) * (1.0 - b) * 0.10;
	s->serc.min.i += z;
}

void	ft_zoom_m(t_src *s, double a, double b)
{
	double	z;

	ft_scale_re(0, &(*s));
	z = (s->serc.max.r - s->serc.min.r) * a * 0.10;
	s->serc.max.r += (s->serc.max.r - s->serc.min.r) * (1.0 - a) * 0.10;
	s->serc.min.r -= z;
	z = (s->serc.max.i - s->serc.min.i) * b * 0.10;
	s->serc.max.i += (s->serc.max.i - s->serc.min.i) * (1.0 - b) * 0.10;
	s->serc.min.i -= z;
}

int	ft_mouse_hook(int keycode, int x, int y, t_src *s)
{
	double	a;
	double	b;

	if (keycode == 4)
	{
		a = x / (double)(WH);
		b = y / (double)(WH);
		ft_zoom_p(s, a, b);
	}
	else if (keycode == 5)
	{
		a = x / (double)(WH);
		b = y / (double)(WH);
		ft_zoom_m(s, a, b);
	}
	return (0);
}
