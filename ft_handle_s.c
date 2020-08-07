/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 18:57:38 by ktennie           #+#    #+#             */
/*   Updated: 2020/08/03 18:49:25 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_putstr2(char *str, t_flag *mod)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (mod->precision_flag && i >= mod->precision)
			return (i);
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void	ft_handle_s(t_flag *mod, va_list arglist)
{
	char	*str;

	if (!(str = va_arg(arglist, char *)))
	{
		ft_putstr("(null)");
		mod->len += 6;
		return ;
	}
	if (mod->precision_flag && mod->width)
	{
		if (mod->precision <= ft_strlen(str))
			mod->width -= mod->precision;
		else
			mod->width -= ft_strlen(str);
	}
	else
		mod->width -= ft_strlen(str);
	if (mod->width && !mod->minus && !mod->zero)
		ft_handle_width(mod);
	mod->len += ft_putstr2(str, mod);
	if (mod->width && mod->minus)
	{
		mod->zero = 0;
		ft_handle_width(mod);
	}
}
