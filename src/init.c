/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:30:43 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/25 20:49:28 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	ft_init_defolt(t_src *s)
{
	(*s).serc.max_iter = 50;
	(*s).scale = 1;
	ft_set_cpx(&(*s).serc.max, 2.0, 2.0);
	ft_set_cpx(&(*s).serc.min, -2.0, -2.0);
}

void	ft_init(t_src *m)
{
	(*m).mlx = mlx_init();
	if (NULL == (*m).mlx)
		ft_erroer("MLX Error");
	(*m).mlx_win = mlx_new_window((*m).mlx, WH, WH, "fractol_mtiesha");
	if (NULL == (*m).mlx_win)
	{
		free(m->mlx_win);
		ft_erroer("Window Error");
	}
	(*m).data.img = mlx_new_image((*m).mlx, WH, WH);
	if (!(*m).data.img)
		ft_erroer("IMG Error");
	(*m).data.addr = mlx_get_data_addr((*m).data.img, \
			&(*m).data.bits_per_pixel, &(*m).data.line_length, \
			&(*m).data.endian);
	if (!(*m).data.img)
		ft_erroer("IMG Fill(bpp etc) Error");
	ft_init_defolt(&(*m));
}
