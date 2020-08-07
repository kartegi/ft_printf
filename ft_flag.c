/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:20:20 by ktennie           #+#    #+#             */
/*   Updated: 2020/08/04 00:08:50 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_size(const char *format, t_flag *mod)
{
	if (format[mod->i] == 'l' && format[mod->i + 1] == 'l')
	{
		mod->ll = 1;
		mod->i++;
	}
	else if (format[mod->i] == 'l')
		mod->l = 1;
	else if (format[mod->i] == 'h' && format[mod->i + 1] == 'h')
	{
		mod->hh = 1;
		mod->i++;
	}
	else if (format[mod->i] == 'h')
		mod->h = 1;
	else if (format[mod->i] == 'L')
		mod->b = 1;
	return (0);
}

void	ft_mod(const char *format, va_list arglist, t_flag *mod)
{
	while (!ft_strchr(CONV, format[mod->i])
		&& format[mod->i] && format[mod->i] != '%')
	{
		if (format[mod->i] == '.' && format[mod->i + 1] == '*'
			&& !mod->precision)
		{
			mod->precision = va_arg(arglist, int);
			mod->i++;
		}
		else if (format[mod->i] == '*' && !mod->width)
			mod->width += va_arg(arglist, int);
		else if (format[mod->i] == '.' && !mod->precision)
		{
			if (ft_isdigit(format[mod->i + 1]))
				mod->precision += ft_atoi(&format[++mod->i]);
			mod->precision_flag = 1;
			while (ft_isdigit(format[mod->i + 1]))
				mod->i++;
		}
		else if (ft_isdigit(format[mod->i]) && !mod->width)
			mod->width += ft_atoi(&format[mod->i]);
		else if (ft_strchr("hlL", format[mod->i]))
			ft_size(format, mod);
		mod->i++;
	}
}

int		ft_flag(const char *format, va_list arglist, t_flag *mod)
{
	while (!ft_strchr(CHECKALL, format[mod->i]) && format[mod->i]
		&& format[mod->i] != '%')
	{
		if (format[mod->i] == '-' && !mod->minus)
			mod->minus = 1;
		else if (format[mod->i] == '+' && !mod->plus)
			mod->plus = 1;
		else if (format[mod->i] == '0' && !mod->zero)
			mod->zero = 1;
		else if (format[mod->i] == '#' && !mod->hash)
			mod->hash = 1;
		mod->i++;
	}
	if (format[mod->i])
		ft_mod(format, arglist, mod);
	return (0);
}
