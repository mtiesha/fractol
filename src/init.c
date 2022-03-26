/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:30:43 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/26 10:36:38 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	ft_init_defolt(t_src *s)
{
	(*s).serc.max_iter = 50;
	ft_set_cpx(&(*s).serc.max, 2.0, 2.0);
	ft_set_cpx(&(*s).serc.min, -2.0, -2.0);
}

void	ft_init(t_src *s)
{
	(*s).mlx = mlx_init();
	if (NULL == (*s).mlx)
		ft_erroer("MLX Error");
	(*s).mlx_win = mlx_new_window((*s).mlx, WH, WH, "fractol_mtiesha");
	if (NULL == (*s).mlx_win)
	{
		free(s->mlx_win);
		ft_erroer("Window Error");
	}
	(*s).data.img = mlx_new_image((*s).mlx, WH, WH);
	if (!(*s).data.img)
		ft_erroer("IMG Error");
	(*s).data.addr = mlx_get_data_addr((*s).data.img, \
			&(*s).data.bits_per_pixel, &(*s).data.line_length, \
			&(*s).data.endian);
	if (!(*s).data.img)
		ft_erroer("IMG Fill(bpp etc) Error");
	ft_init_defolt(&(*s));
}
