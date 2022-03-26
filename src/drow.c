/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:07:19 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/24 22:17:22 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)(dst) = color;
}

void	ft_gate_color(int iter, t_src *s, double y, double x)
{
	if (iter < s->serc.max_iter)
		ft_put_pixel((&s->data), y, x, 0x42212142 + pow(iter, 2.1));
	else
		ft_put_pixel((&s->data), y, x, YELLOW);
}
