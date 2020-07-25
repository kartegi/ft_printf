/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:06:22 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/25 15:41:15 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//int	ft_printf(const char *format, ...)
//{
//	char	print_char;
//	char	*print_str;
//	int     print_nbr;
//	void	*print_p;
//	va_list arglist;
//
//	va_start(arglist, format);
//	while(*format)
//	{
//		if (*format == '%')
//		{
//		  	format++;
//		  	if (*format == 's')
//			{
//				print_str = va_arg(arglist, char *);
//				ft_putstr(print_str);
//			}
//		  	else if (*format == 'c')
//		  	{
//				print_char = va_arg(arglist, int);
//				ft_putchar(print_char);
//		  	}
//			else if (*format == 'i')
//			{
//				print_nbr = va_arg(arglist, int);
//				ft_putnbr(print_nbr);
//			}
//			else if (*format == 'p')
//			{
//				print_p = va_arg(arglist, void *);
//				ft_putp(print_p);
//			}
//			else if(*format == '%')
//				ft_putchar('%');
//			format++;
//		}
//	    	else
//			ft_putchar(*format++);
//	}
//      	va_end(arglist);
//	return (0);
//}

void	ft_tozero(t_flag *mod)
{
	mod->x = 0;
	mod->plus = 0;
	mod->minus = 0;
	mod->zero = 0;
	mod->hash = 0;
	mod->width = 0;
	mod->precision = 0;
	mod->l = 0;
	mod->ll = 0;
	mod->L = 0;
	mod->h = 0;
	mod->hh = 0;
}


int		ft_parse(const char *format, va_list arglist)
{
	t_flag	*mod;
	int		i;

	if (!(mod = (t_flag*)malloc(sizeof(t_flag))))
		return (0);
//	if (!ft_typecheck(format))
//		return (0);
	ft_tozero(mod);
	ft_flag(mod, format, arglist);
	i = ft_print(format, arglist, mod);
	free(mod);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int			count;
	int			i;
	va_list		arglist;
//	int			flag;

	i	 = 0;
	count = 0;
	va_start(arglist, format);
	while(format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			if(!ft_parse(&format[i], arglist))
				return (-1);
		}
		else
			ft_putchar(++i);
		count++;
	}
	return(count);
}