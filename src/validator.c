/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:49:05 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/26 10:38:13 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	ft_valid_num(char *str)
{
	int	i;

	i = 0;
	if (str && str[i] == '-' && str[i + 1])
		i++;
	if (str && (str[i] == '.' || \
	(str[i] == '0' && str[i + 1] && str[i + 1] != '.')))
		return (0);
	while (str && str[i] != '.' && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (str[i] == '.' && str[i + 1])
		i++;
	else if (str[i] == '.' && !str[i + 1])
		return (0);
	while (str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is(char **av, int ac)
{
	if (1 == ac)
	{
		if (!ft_strncmp(av[0], "Mandelbrot", 10) \
			|| !ft_strncmp(av[0], "mandelbrot", 10) \
			|| !ft_strncmp(av[0], "Burningship", 11) \
			|| !ft_strncmp(av[0], "burningship", 11) \
			|| !ft_strncmp(av[0], "Julia", 6) \
			|| !ft_strncmp(av[0], "julia", 6))
			return (ac);
	}
	else if (2 == ac)
	{
		if ((!ft_strncmp(av[0], "Julia", 6) \
			|| !ft_strncmp(av[0], "julia", 6)) \
			&& ft_valid_num(av[1]))
			return (ac);
	}
	else if (3 == ac)
	{
		if ((!ft_strncmp(av[0], "Julia", 6) \
			|| !ft_strncmp(av[0], "julia", 6)) \
			&& ft_valid_num(av[1]) && ft_valid_num(av[2]))
			return (ac);
	}
	return (0);
}

int	ft_valid(int ac, char **av, t_src *s)
{
	int	i;

	i = ft_is(av, ac);
	if (!i)
		ft_erroer("Validation argv error, please check subject");
	(*s).name = av[0];
	ft_init(&(*s));
	if (2 == i)
		mlx_mouse_move((*s).mlx, (*s).mlx_win, ft_atoi(av[1]), WH / 2);
	else if (3 == i)
		mlx_mouse_move((*s).mlx, (*s).mlx_win, ft_atoi(av[1]), ft_atoi(av[2]));
	return (i);
}
