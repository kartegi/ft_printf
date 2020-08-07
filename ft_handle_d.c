/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:58:38 by ktennie           #+#    #+#             */
/*   Updated: 2020/08/05 17:28:12 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
//
int		ft_nbrlen_d(intmax_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
//
char	*ft_nbr2str(intmax_t n)
{
	int			i;
	int			cp;
	char		*str;

	i = ft_nbrlen_d(n);
	str = ft_strnew(i);
	while (i-- > 0)
	{
		cp = n % 10;
		str[i] = cp + '0';
		n /= 10;
	}
	return (str);
}
//
//void	ft_modify_d(t_flag *mod, intmax_t num)
//{
//	intmax_t	len;
//	char		*str;
//
//	len = ft_nbrlen(num);
//	if (mod->zero && !mod->minus && mod->width && mod->width > len)
//	{
//		mod->precision_flag = 1;
//		mod->precision += mod->width;
//		mod->width = 0;
//	}
//	str = ft_nbr2str(num, mod);
//	if (mod->width && mod->zero && mod->precision_flag && mod->precision > len)
//		mod->zero = 0;
//	else if (mod->width && mod->zero && mod->precision_flag && mod->precision )
//	mod->width -= ft_strlen(str) + (mod->plus == 2 ? 1 : 0);
//	mod->len += ft_strlen(str);
//	if (mod->width && !mod->minus)
//		ft_handle_width(mod);
//	if (mod->plus == 2)
//		ft_putchar('+');
//	ft_putstr(str);
//	if (mod->width && mod->minus)
//	{
//		ft_handle_width(mod);
//		mod->zero = 0;
//	}
//	free(str);
//}

void	ft_modify_d(t_flag *mod, intmax_t num, char *str)
{
	int 	len;

	len = ft_nbrlen_d(num) + (mod->negative || mod->plus ? 1 : 0);
	if (mod->width && mod->precision_flag)
		mod->zero = 0;
	mod->width -= len + (mod->precision_flag && mod->precision > ft_nbrlen_d(num)
			? mod->precision - ft_nbrlen_d(num) : 0);
	mod->width += num == 0 && mod->precision_flag && mod->precision == 0 ? 1 : 0;
	mod->len += len + ((mod->precision_flag && mod->precision > ft_nbrlen_d(num))
			? mod->precision - ft_nbrlen_d(num) : 0);
	mod->len -= num == 0 && mod->precision_flag && mod->precision == 0 ? 1 : 0;
	if (mod->width && !mod->minus && !mod->zero)
		ft_handle_width(mod);
	if (mod->plus && !mod->negative)
		ft_putchar('+');
	else if (mod->negative)
		ft_putchar('-');
	if (mod->width && !mod->minus && mod->zero)
		ft_handle_width(mod);
	//precision
	while (mod->precision_flag && mod->precision > ft_nbrlen_d(num))
	{
		ft_putchar('0');
		mod->precision--;
	}
	if (mod->space && mod->width <= 0 && !mod->negative && !mod->plus)
	{
		ft_putchar(' ');
		mod->len++;
	}
	num == 0 && mod->precision_flag && mod->precision == 0 ? 0 : ft_putstr(str);
	if (mod->width && mod->minus)
		ft_handle_width(mod);
}

void	ft_handle_d(t_flag *mod, va_list arglist)
{
	intmax_t	num;
	char 		*str;

	if (mod->hh)
		num = (signed char)va_arg(arglist, int);
	else if (mod->h)
		num = (short int)va_arg(arglist, int);
	else if (mod->ll)
		num = (long long int)va_arg(arglist, long long int);
	else if (mod->l)
		num = va_arg(arglist, long int);
	else
		num = va_arg(arglist, int);
	if(num < 0)
	{
		mod->negative = 1;
		mod->plus = 0;
		num *= -1;
	}
	if (num == LLONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		mod->len += 20;
		return ;
	}
	str = ft_nbr2str(num);
	ft_modify_d(mod, num, str);
}
