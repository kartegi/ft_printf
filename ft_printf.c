/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:06:22 by ktennie           #+#    #+#             */
/*   Updated: 2020/08/06 23:16:49 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_tozero(t_flag *mod)
{
	mod->i = 0;
	mod->space = 0;
	mod->len = 0;
	mod->upper = 0;
	mod->flag = 0;
	mod->plus = 0;
	mod->negative = 0;
	mod->minus = 0;
	mod->zero = 0;
	mod->hash = 0;
	mod->width = 0;
	mod->precision = 0;
	mod->precision_flag = 0;
	mod->l = 0;
	mod->ll = 0;
	mod->b = 0;
	mod->h = 0;
	mod->hh = 0;
}

void 		ft_tozero_flag(t_flag *mod)
{
	mod->space = 0;
	mod->upper = 0;
	mod->plus = 0;
	mod->negative = 0;
	mod->minus = 0;
	mod->zero = 0;
	mod->hash = 0;
	mod->width = 0;
	mod->precision = 0;
	mod->precision_flag = 0;
	mod->l = 0;
	mod->ll = 0;
	mod->b = 0;
	mod->h = 0;
	mod->hh = 0;
}


int 		ft_parse(const char *format, va_list arglist, t_flag *mod)
{
	const char *flag;
	int 	i;

	while (format[mod->i])
	{
		ft_tozero_flag(mod);
		if (format[mod->i] == '%')
		{
			i = mod->i;
			while (!(flag = ft_strchr(CHECKALL  , format[i])) && format[i])
				i++;
			if (flag && format[mod->i + 1] == ' ')
				mod->space++;
			if(!flag || !format[i])
				return (-1);
			mod->i++;
			ft_flag(format, arglist, mod);
			if (ft_strchr(CONV, format[mod->i]))
				ft_print_conv(format, arglist, mod);
			else if (format[mod->i] == '%')
			{
				ft_putchar('%');
				mod->len++;
			}
		}
		else
		{
			ft_putchar(format[mod->i]);
			mod->len++;
		}
		mod->i++;
	}
	return (mod->len);
}

int		ft_printf(const char *format, ...)
{
	va_list		arglist;
	t_flag		*mod;
	int 		len;

	if (!(mod = (t_flag*)malloc(sizeof(t_flag))))
		return (0);
	va_start(arglist, format);
	ft_tozero(mod);
	len = ft_parse(format, arglist, mod);
	va_end(arglist);
	free(mod);
	return(len);
}
