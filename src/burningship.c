/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:59:28 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/28 11:26:19 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_bs_logic(t_x0y *cxp, t_serc *serc, double *z, int *iter)
{
	while (cxp->x * cxp->x + cxp->y * cxp->y < 4
		&& *iter < serc->max_iter)
	{
		*z = cxp->x * cxp->x - cxp->y * cxp->y + cxp->cx_r;
		cxp->y = 2 * fabs(cxp->x * cxp->y) + cxp->cx_i;
		cxp->x = *z;
		(*iter)++;
	}
}

void	ft_burningship(t_src *s, t_serc serc, double p_y, double p_x)
{
	int		iter;
	double	z;
	t_x0y	cxp;

	while (p_x < WH)
	{
		cxp.cx_i = serc.min.i + p_x / WH * (serc.max.i - serc.min.i);
		p_y = 0;
		while (p_y < WH)
		{
			cxp.cx_r = serc.min.r + p_y / WH * (serc.max.r - serc.min.r);
			cxp.x = 0;
			cxp.y = 0;
			iter = 0;
			ft_bs_logic(&cxp, &serc, &z, &iter);
			ft_gate_color(iter, s, p_y, p_x);
			p_y++;
		}
		p_x++;
	}
}
