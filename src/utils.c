/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtiesha < mtiesha@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:02:21 by mtiesha           #+#    #+#             */
/*   Updated: 2022/03/26 17:59:25 by mtiesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	ft_get_x(double num, t_cpx axis)
{
	double	ret;

	if (0.0 == num)
		ret = WH / 2;		
	else if (-0.199999 < num)
	{
		ret = num * WH / axis.i;
		printf("minus\n");
	}
	else
	{
		ret = num * WH / axis.r;
		printf("plus\n");
	}
	return (ret);
}

double	ft_atoi_f(const char *str)
{
	double	d1;
	double	d2;
	char	*c;
	int		len;

	c = (char *)str;
	d1 = (double)ft_atoi(c);
	while (c && *c != '.' && *c)
		c++;
	if (c && *c == '.')
		c++;
	d2 = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len--)
		d2 /= 10;
	if (d1 >= 0 && str[0] != '-')
		return (d1 + d2);
	else
		return (d1 - d2);
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
