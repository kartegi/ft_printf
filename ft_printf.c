/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:06:22 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/29 21:10:29 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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
	mod->i = 0;
	mod->len = 0;
	mod->x = 0; //for test
	mod->plus = 0;
	mod->minus = 0;
	mod->zero = 0;
	mod->hash = 0;
	mod->width = 0;
	mod->precision = 0;
	mod->precision_flag = 0;
	mod->l = 0;
	mod->ll = 0;
	mod->L = 0;
	mod->h = 0;
	mod->hh = 0;
}


void		ft_parse(const char *format, va_list arglist, t_flag *mod)
{

	while(format[mod->i] != '\0')
	{
		if (format[mod->i] == '%' && format[mod->i + 1] != '%')
		{
			mod->i++;
			ft_flag(format, arglist, mod);
			ft_print_conv(format, arglist, mod);
		}
		else if (format[mod->i] == '%' && format[mod->i + 1] == '%')
		{
			ft_putchar('%');
			mod->len++;
		}
		else
		{
			ft_putchar(format[mod->i]);
			mod->len++;
		}
		mod->i++;
//		printf("\n\n1 ---> %i\n\n", mod->len);
	}

//	printf("I: %i;\nLen: %i;\nPlus: %i;\nMinus: %i;\nZero: %i;\nHash: %i;\n"
//		"Width: %i;\nPrecision: %i;\n"
//		"l: %i;\nll: %i;\nL: %i;\nh: %i;\nhh: %i;\n",
//		   mod->i, mod->len, mod->plus, mod->minus, mod->zero, mod->hash,
//		   mod->width, mod->precision, mod->l, mod->ll,
//		   mod->L, mod->h, mod->hh);
}

int		ft_printf(const char *format, ...)
{
	va_list		arglist;
	t_flag		*mod;

	if (!(mod = (t_flag*)malloc(sizeof(t_flag))))
		return (0);
	va_start(arglist, format);
	ft_tozero(mod);
	ft_parse(format, arglist, mod);
	printf("\n\n1 ---> %i\n\n", mod->len);
	va_end(arglist);
	free(mod);
	return(0);
}