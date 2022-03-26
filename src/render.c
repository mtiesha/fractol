/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:07:19 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/25 19:16:40 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_render(t_src *s)
{
	if (s->mlx_win != NULL)
	{
		if (s->name[1] == 'a')
			ft_mandelbrot(s, s->serc, 0, 0);
		else if (s->name[2] == 'l')
			ft_julia(s, s->serc, 0, 0);
		else if (s->name[2] == 'r')
			ft_burningship(s, s->serc, 0, 0);
		mlx_put_image_to_window(s->mlx, s->mlx_win, s->data.img, 0, 0);
	}
	return (0);
}

