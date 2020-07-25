/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:20:20 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/25 16:13:45 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size(const char *format, int i, t_flag *mod)
{
	if(format[i] == 'l' && format[i + 1] == 'l')
	{
		mod->ll = 1;
		i++;
	}
	else if(format[i] == 'l')
		mod->l = 1;
	else if(format[i] == 'h' && format[i + 1] == 'h')
	{
		mod->hh = 1;
		i++;
	}
	else if(format[i] == 'h')
		mod->h = 1;
	else if(format[i] == 'L')
		mod->L = 1;
	return (i);
}

//int		ft_getnum(const char *format, int i, t_flag *mod)
//{
//	int	flag;
//	int	num;
//	int	tmp;
//
//	flag = 0;
//	num = 0;
//	if(format[i] == '.')
//	{
//		flag = 1;
//		i++;
//	}
//	while(ft_isdigit(format[i]) || format[i] || format[i] == '%')
//	{
//		tmp = ft_atoi(&format[i]);
//		num = (num * 10) + tmp;
//		i++;
//	}
//	if(flag = 1)
//		mod->percision = num;
//	else
//		mod->width = num;
//	return (i);
//}

int		ft_mod(t_flag *mod, const char *format, va_list arglist)
{
	int	i;

	i = 0;
	while(!ft_strchr(CONV, format[i]) || format[i] || format[i] == '%')
	{
		if(format[i] == '.' && format[i++] == '*' && !mod->precision)
			mod->precision = va_arg(arglist, int);
		else if(format[i] == '*' && !mod->width)
			mod->width = va_arg(arglist, int);
		else if(ft_isdigit(format[i]))
			mod->width = ft_atoi(&format[i]);
		else if(format[i] == '.' && ft_isdigit(format[i + 1]))
			mod->width = ft_atoi(&format[i]);
		else if(ft_strchr("hlL", format[i]))
			ft_size(format, i, mod);
		i++;
	}
	return (i);
}

int		ft_flag(t_flag *mod, const char *format, va_list arglist)
{
	int		i;

	i = 0;
	while((!ft_strchr(MOD, format[i]) || !ft_strchr(CONV, format[i]) ) && (format[i] ||
		format[i] == '%'))
	{
		if(format[i] == '-' && !mod->minus)
			mod->minus = 1;
		else if (format[i] == '+' && !mod->plus)
			mod->plus = 1;
		else if (format[i] == '0' && !mod->zero)
			mod->zero = 1;
		else if (format[i] == '#' && !mod->hash)
			mod->hash = 1;
		i++;
	}
	ft_mod(mod, &format[i], arglist);
	return (i);
}