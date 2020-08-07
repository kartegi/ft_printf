/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:31:27 by ktennie           #+#    #+#             */
/*   Updated: 2020/08/06 13:43:01 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "includes/ft_printf.h"
//
//int		ft_nbrlen_o(uintmax_t n)
//{
//	int	i;
//
//	i = 0;
//	if (n == 0)
//		i++;
//	while (n > 0)
//	{
//		n /= 8;
//		i++;
//	}
//	return (i);
//}
//
//char	*ft_nbr2str_o(uintmax_t n, t_flag *mod)
//{
//	int			i;
//	int			cp;
//	char		*str;
//
//	i = ft_nbrlen_o(n);
//	if (mod->precision_flag && mod->precision > i)
//		i += (mod->precision - i);
//	str = ft_strnew(i);
//	while (i-- > 0)
//	{
//		cp = n % 8;
//		str[i] = cp + '0';
//		n /= 8;
//	}
//	return (str);
//}
//
//void 	ft_savespace(t_flag *mod, char *str, int len)
//{
//	if (mod->width && mod->zero
//		&& mod->precision_flag && mod->precision > len)
//		mod->zero = 0;
//	mod->width -= ft_strlen(str) + (mod->hash ? 1 : 0);
//	mod->len += (mod->hash ? 1 : 0);
//	if (mod->zero && mod->hash)
//		ft_putstr("0");
//	if (mod->width && !mod->minus)
//		ft_handle_width(mod);
//	if (mod->hash && !mod->zero)
//		ft_putstr("0");
//}
//
//void	ft_modify_o(t_flag *mod, char *str, int len, uintmax_t num)
//{
//	ft_savespace(mod, str, len);
//	num = num;
//	if (num == 0 && (mod->precision_flag && mod->precision == 0))
//	{
//		mod->len++;
//		free(str);
//		return ;
//	}
//	if (len == 0 && (!mod->precision_flag
//					 || (mod->precision_flag && mod->precision != 0)))
//	{
//		ft_putchar('0');
//		mod->len++;
//	}
//	else
//		mod->len += ft_strlen(str);
//	ft_putstr(str);
//	if (mod->width && mod->minus)
//	{
//		mod->zero = 0;
//		ft_handle_width(mod);
//	}
//	free(str);
//}
//
//void	ft_handle_o(t_flag *mod, va_list arglist)
//{
//	char		*str;
//	int			len;
//	uintmax_t	num;
//
//	if (mod->hh)
//		num = (unsigned char)va_arg(arglist, unsigned int);
//	else if (mod->h)
//		num = (unsigned short)va_arg(arglist, unsigned int);
//	else if (mod->ll)
//		num = va_arg(arglist, unsigned long long);
//	else if (mod->l)
//		num = va_arg(arglist, unsigned long);
//	else
//		num = va_arg(arglist, unsigned int);
//	str = ft_nbr2str_o(num, mod);
//	len = ft_nbrlen_o(num);
//	ft_modify_o(mod, str, len, num);
//}

#include "includes/ft_printf.h"

int		ft_nbrlen_o(uintmax_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 8;
		i++;
	}
	return (i);
}

char	*ft_nbr2str_o(uintmax_t n)
{
	int			i;
	int			cp;
	char		*str;

	i = ft_nbrlen_o(n);
	str = ft_strnew(i);
	while (i-- > 0)
	{
		cp = n % 8;
			str[i] = cp + '0';
		n /= 8;
	}
	return (str);
}

void	ft_precision_o(t_flag *mod, int len)
{
	if (mod->precision_flag && mod->precision > len)
	{
		mod->precision -= len + (mod->hash ? 1 : 0);
		while (mod->precision)
		{
			ft_putchar('0');
			mod->precision--;
			mod->len++;
		}
	}
}

void	ft_modify_o(t_flag *mod, int num, char *str)
{
	mod->len += ft_strlen(str);
	if (mod->zero && mod->hash)
		ft_putstr("0");
	if (mod->width && !mod->minus)
		ft_handle_width(mod);
	if (mod->hash  && !mod->zero)
		ft_putstr("0");
	mod->hash ? (mod->len += 1) : (mod->len += 0);
	ft_precision_o(mod, num);
	if (num == 0 && (!mod->precision_flag
					 || (mod->precision_flag && mod->precision != 0)))
	{
		ft_putchar('0');
		mod->len++;
	}
	else
		ft_putstr(str);
	if (mod->width && mod->minus)
	{
		mod->zero = 0;
		ft_handle_width(mod);
	}
	free(str);
}

void	ft_handle_o(t_flag *mod, va_list arglist)
{
	char		*str;
	uintmax_t	num;
	int			len;

	if (mod->hh)
		num = (unsigned char)va_arg(arglist, unsigned int);
	else if (mod->h)
		num = (unsigned short)va_arg(arglist, unsigned int);
	else if (mod->ll)
		num = va_arg(arglist, unsigned long long);
	else if (mod->l)
		num = va_arg(arglist, unsigned long);
	else
	num = va_arg(arglist, unsigned int);
	str = ft_nbr2str_o(num);
	len = ft_nbrlen_o(num);
	if (mod->width && mod->zero && mod->precision_flag
		&& (long unsigned)mod->precision > num)
		mod->zero = 0;
	mod->width -= ft_strlen(str) + (mod->hash ? 1 : 0) +
				  (mod->precision_flag && mod->precision > len ?
				   (mod->precision - len) : 0);
	ft_modify_o(mod, len, str);
}
