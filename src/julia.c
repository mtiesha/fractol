/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:07:19 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/26 11:28:46 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	ft_jul_logic(t_x0y *cxp, t_serc *serc, double *z, int *iter)
{
	while (cxp->x * cxp->x + cxp->y * cxp->y < 4 && *iter < serc->max_iter)
	{
		*z = cxp->x * cxp->x - cxp->y * cxp->y + cxp->cx_r;
		cxp->y = 2 * cxp->x * cxp->y + cxp->cx_i;
		cxp->x = *z;
		(*iter)++;
	}
}

void	ft_julia(t_src *s, t_serc serc, double p_y, double p_x)
{
	t_x0y	cpx;
	int		iter;
	double	z;

	if (s->set_flag)
		mlx_mouse_get_pos(s->mlx, s->mlx_win, &s->set_j.r, &s->set_j.i);
	s->set_flag = 1;
	while (p_y < WH)
	{
		p_x = 0;
		while (p_x < WH)
		{
			cpx.cx_r = serc.min.r + s->set_j.r / WH * (serc.max.r - serc.min.r);
			cpx.cx_i = serc.min.i + s->set_j.i / WH * (serc.max.i - serc.min.i);
			cpx.x = serc.min.r + (double)p_x / WH * (serc.max.r - serc.min.r);
			cpx.y = serc.min.i + (double)p_y / WH * (serc.max.i - serc.min.i);
			iter = 0;
			ft_jul_logic(&cpx, &serc, &z, &iter);
			ft_gate_color(iter, s, p_x, p_y);
			p_x++;
		}
		p_y++;
	}
}
