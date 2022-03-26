/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:07:19 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/26 10:51:19 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	ft_destroy_window(t_src *s)
{
	mlx_destroy_window(s->mlx, s->mlx_win);
	s->mlx_win = NULL;
	return (0);
}

int	ft_handle_keypress(int keysym, t_src *s)
{
	if (65307 == keysym)
		ft_destroy_window(s);
	else if (109 == keysym)
		s->name = "mandelbrot";
	else if (106 == keysym)
		s->name = "julia";
	else if (98 == keysym)
		s->name = "burningship";
	else if (101 == keysym)
		ft_scale_re(1, s);
	else if (113 == keysym)
		ft_scale_re(0, s);
	else if (115 == keysym || 119 == keysym || 97 == keysym || 100 == keysym)
		ft_wasd(keysym, s);
	return (0);
}

int	main(int argc, char **argv)
{
	t_src	s;

	if (argc < 2 || !ft_valid(--argc, ++argv, &s))
		ft_erroer("Error: mandelbrot || julia || burningship");
	mlx_loop_hook(s.mlx, &ft_render, &s);
	mlx_hook(s.mlx_win, 2, 1L << 0, \
		&ft_handle_keypress, &s);
	if (10 < ft_strlen(s.name))
	{
		mlx_mouse_move(s.mlx, s.mlx_win, 50, WH / 2);
		printf("%s\n", s.name);
	}
	mlx_mouse_hook(s.mlx_win, &ft_mouse_hook, &s);
	mlx_loop(s.mlx);
	mlx_destroy_display(s.mlx);
	free(s.mlx);
}
