/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:02:21 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/28 19:07:51 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	ft_atoi_f(const char *str)
{
	double	num_ud;
	double	num_ad;
	char	*tmp;
	int		len;

	tmp = (char *)str;
	num_ud = (double)ft_atoi(tmp);
	while (tmp && *tmp != '.' && *tmp)
		tmp++;
	tmp++;
	num_ad = (double)ft_atoi(tmp);
	len = ft_strlen(tmp);
	while (len--)
		num_ad /= 10;
	if (num_ud >= 0 && str[0] != '-')
		return (num_ud + num_ad);
	else
		return (num_ud - num_ad);
}

void	ft_erroer(char *str)
{
	perror(str);
	exit(1);
}

void	ft_set_cpx(t_cpx *s, double r, double i)
{
		(*s).r = r;
		(*s).i = i;
}

void	ft_wasd(int keycode, t_src *s)
{
	double	z;

	if (keycode == 97 || keycode == 100)
	{
		z = 0.1 * (s->serc.max.r - s->serc.min.r) * -1;
		if (keycode == 100)
			z *= -1;
		s->serc.max.r += z;
		s->serc.min.r += z;
	}
	if (keycode == 115 || keycode == 119)
	{
		z = 0.1 * (s->serc.max.i - s->serc.min.i) * -1;
		if (keycode == 115)
			z *= -1;
		s->serc.max.i += z;
		s->serc.min.i += z;
	}
}
