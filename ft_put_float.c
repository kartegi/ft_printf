/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 00:35:29 by ktennie           #+#    #+#             */
/*   Updated: 2020/08/06 17:09:36 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

long long int	ft_powerof(int n)
{
	long long int	result;
	int				base;

	base = 10;
	result = 1;
	while (n > 0)
	{
		result *= base;
		n--;
	}
	return (result);
}

void			ft_putrem(long double rem, int base)
{
	int				i;
	int				flag;
	long long int	power;

	i = 0;
	flag = 0;
	power = ft_powerof(base);
	while (i < base)
	{
		if ((int)(rem * power) % 10 >= 5 && i == 0)
			flag = 1;
		rem = rem * 10.0;
		if (flag == 1 && i == base - 1)
			rem++;
		i++;
	}
	ft_putchar('.');
	ft_putnbr((long long int)rem);
}

void			ft_put_float(long double n, t_flag *mod)
{
	long double	rem;

	rem = n - (int)n;
	if (n < 0.0)
	{
		rem *= -1;
		n *= -1.0;
	}
	ft_putnbr((int)n);
	if (!mod->precision_flag || mod->precision > 0)
		ft_putrem(rem, mod->precision_flag ? mod->precision : 6);
	else if (mod->hash && mod->precision_flag && mod->precision == 0)
		ft_putchar('.');
}
