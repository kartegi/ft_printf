/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:47:46 by ktennie           #+#    #+#             */
/*   Updated: 2020/08/03 18:27:23 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_nbrlen_x(uintmax_t n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*ft_nbr2str_x(uintmax_t n, t_flag *mod)
{
	int			i;
	int			cp;
	char		*str;

	i = ft_nbrlen_x(n);
	str = ft_strnew(i);
	while (i-- > 0)
	{
		cp = n % 16;
		if (mod->upper)
			str[i] = (cp > 9) ? (cp - 10) + 'A' : cp + '0';
		else
			str[i] = (cp > 9) ? (cp - 10) + 'a' : cp + '0';
		n /= 16;
	}
	return (str);
}

void	ft_precision_x(t_flag *mod, int len)
{
	if (mod->precision_flag && mod->precision > len)
	{
		mod->precision -= len;
		while (mod->precision)
		{
			ft_putchar('0');
			mod->precision--;
			mod->len++;
		}
	}
}

void	ft_modify_x(t_flag *mod, int num, char *str, uintmax_t nbr)
{
	mod->len += ft_strlen(str);
	if (mod->zero && mod->hash && nbr != 0)
		ft_putstr(mod->upper ? "0X" : "0x");
	if (mod->width && !mod->minus)
		ft_handle_width(mod);
	if (mod->hash && nbr != 0 && !mod->zero)
		ft_putstr(mod->upper ? "0X" : "0x");
	mod->hash && nbr != 0 ? (mod->len += 2) : (mod->len += 0);
	ft_precision_x(mod, num);
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

void	ft_handle_x(t_flag *mod, va_list arglist)
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
	str = ft_nbr2str_x(num, mod);
	len = ft_nbrlen_x(num);
	if (mod->width && mod->zero && mod->precision_flag
		&& (long unsigned)mod->precision > num)
		mod->zero = 0;
	mod->width -= ft_strlen(str) + (mod->hash ? 2 : 0) +
				  (mod->precision_flag && (long unsigned)mod->precision > num ?
				   (mod->precision - num) : 0);
	ft_modify_x(mod, len, str, num);
}
