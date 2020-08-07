/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 14:37:41 by ktennie           #+#    #+#             */
/*   Updated: 2020/08/03 14:37:41 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_nbrlen_u(uintmax_t n)
{
	int	i;

	i = 0;
	if(n == 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_nbr2str_u(uintmax_t n, t_flag *mod)
{
	int			i;
	int			cp;
	char		*str;

	i = ft_nbrlen_u(n);
	if (mod->precision_flag && mod->precision > i)
		i += (mod->precision - i);
	str = ft_strnew(i);
	while (i-- > 0)
	{
		cp = n % 10;
		str[i] = cp + '0';
		n /= 10;
	}
	return (str);
}

void	ft_modify_u(t_flag *mod, char *str, int len)
{
	if (mod->width && mod->zero && mod->precision_flag && mod->precision > len)
		mod->zero = 0;
	mod->width -= ft_strlen(str);
	mod->len += ft_strlen(str);
	if (mod->width && !mod->minus)
		ft_handle_width(mod);
	ft_putstr(str);
	if (mod->width && mod->minus && !mod->zero)
		ft_handle_width(mod);
	free(str);
}

void	ft_handle_u(t_flag *mod, va_list arglist)
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
	len = ft_nbrlen_u(num);
	str = ft_nbr2str_u(num, mod);
	ft_modify_u(mod, str, len);
}
