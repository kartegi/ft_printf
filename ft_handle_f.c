/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 14:49:20 by ktennie           #+#    #+#             */
/*   Updated: 2020/08/06 16:09:11 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_nbrlen_f(intmax_t n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_handle_f(t_flag *mod, va_list arglist)
{
	long double	num;
	int			len;

	if (mod->b)
		num = (long double)va_arg(arglist, long double);

	else
		num = (long double)va_arg(arglist, double);
	if (num < 0)
		mod->negative = 1;
	len = ft_nbrlen_f((intmax_t)num);
	mod->width -= len + (mod->precision_flag ? (mod->precision + 1) : 7);
	mod->len += len + (mod->precision_flag ? (mod->precision + 1) : 7);
	if (mod->plus && !mod->negative)
		ft_putchar('+');
	if (mod->negative)
		ft_putchar('-');
	if (mod->width && !mod->minus)
		ft_handle_width(mod);
	ft_put_float(num, mod);
	if (mod->width && mod->minus)
	{
		mod->zero = 0;
		ft_handle_width(mod);
	}
}
