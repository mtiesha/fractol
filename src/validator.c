/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:49:05 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/26 17:55:50 by mtiesha          ###   ########.fr       */
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

static void	ft_gate_jul(t_src *s)
{
	double	x;
	double	y;

	x = ft_get_x(s->set_j.r, s->serc.max);
	y = ft_get_x(s->set_j.i, s->serc.max);
	ft_set_cpx(&s->set_j, x, y);
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
	{
		ft_set_cpx(&(*s).set_j, ft_atoi_f(av[1]), 0.0);
		ft_gate_jul(s);
	}
	else if (3 == i)
	{
		ft_set_cpx(&(*s).set_j, ft_atoi_f(av[1]), ft_atoi_f(av[2]));
		ft_gate_jul(s);
	}
	return (i);
}
