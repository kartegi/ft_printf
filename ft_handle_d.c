/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:58:38 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/30 12:43:05 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_nbrlen(intmax_t n, t_flag *mod)
{
	int	i;

	i = 0;
	if(n < 0)
	{
		n *= -1;
		i++;
	}
	while(n > 0)
	{
		n /= 10;
		i++;
	}
	mod->len += i;
	return (i);
}
//
//void	ft_precision(t_flag *mod)
//{
//	while(mod->precision)
//	{
//		ft_putchar('0');
//		mod->precision--;
//		mod->len++;
//	}
//	mod->len--;
//}
//
//void	ft_print_num(t_flag *mod, intmax_t num)
//{
//	if(mod->plus && num > 0)
//		ft_putchar('+');
//	if(mod->precision > 0)
//		ft_precision(mod);
//	if(mod->hh)
//		ft_putnbr((signed char)num);
//	else if(mod->h)
//		ft_putnbr((short int)num);
//	else if(mod->ll)
//		ft_putnbr((long long int)num);
//	else if(mod->l)
//		ft_putnbr((long int)num);
//	else
//		ft_putnbr((int)num);
//}
//
//void	ft_handle_d(t_flag *mod, va_list arglist)
//{
//	intmax_t	num;
//	int			len;
//
//	num = (long long int)va_arg(arglist, long long int);
//	len = ft_nbrlen(num, mod);
//	if(mod->precision_flag)
//	{
//		if(mod->precision > len)
//		{
//			if(mod->width)
//			{
//				mod->width -= ((mod->precision - len) + len);
//				mod->precision -= mod->width;
//			}
//			else
//				mod->precision -= len;
//		}
//		else
//			mod->precision *= -1;
//	}
//	if(!mod->precision_flag && mod->width)
//		mod->width -= len;
//	if(mod->width && !mod->minus && !mod->zero)
//		ft_handle_width(mod);
//	ft_print_num(mod, num);
//	if(mod->width && mod->minus && !mod->zero)
//		ft_handle_width(mod);
//}


void	ft_precision(t_flag *mod)
{
	while(mod->precision)
	{
		ft_putchar('0');
		mod->precision--;
		mod->len++;
	}
	mod->len--;
}

void	ft_print_num(t_flag *mod, intmax_t num)
{
	if(mod->plus && num > 0)
		ft_putchar('+');
	if(mod->precision > 0)
		ft_precision(mod);
	if(mod->hh)
		ft_putnbr((signed char)num);
	else if(mod->h)
		ft_putnbr((short int)num);
	else if(mod->ll)
		ft_putnbr((long long int)num);
	else if(mod->l)
		ft_putnbr((long int)num);
	else
		ft_putnbr((int)num);
}

void	ft_handle_d(t_flag *mod, va_list arglist)
{
	intmax_t	num;
	int			len;

	num = (long long int)va_arg(arglist, long long int);
	len = ft_nbrlen(num, mod);
	if(mod->precision_flag)
	{
		if(mod->precision > len)
		{
			if(mod->width)
			{
				mod->width -= ((mod->precision - len) + len);
				mod->precision -= mod->width;
			}
			else
				mod->precision -= len;
		}
		else
			mod->precision *= -1;
	}
	if(!mod->precision_flag && mod->width)
		mod->width -= len;
	if(mod->width && !mod->minus && !mod->zero)
		ft_handle_width(mod);
	ft_print_num(mod, num);
	if(mod->width && mod->minus && !mod->zero)
		ft_handle_width(mod);
}