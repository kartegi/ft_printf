/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 11:52:50 by ktennie           #+#    #+#             */
/*   Updated: 2020/08/06 01:55:30 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_putstr_p(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void	ft_handle_p(t_flag *mod, va_list arglist)
{
	uintmax_t	p;
	char		*str;

	if(!(p = (uintmax_t)va_arg(arglist, void *)))
	{
		ft_putstr("(nil)");
		mod->len += 5;
		return ;
	}
	str = ft_itoa_base(p, 16, mod);
	if (mod->width)
		mod->width -= ft_strlen(str) + 2;
	if (mod->width && !mod->minus && !mod->zero)
		ft_handle_width(mod);
	ft_putstr("0x");
	mod->len += ft_putstr_p(str) + 2;
	if (mod->width && mod->minus && !mod->zero)
		ft_handle_width(mod);
	free(str);
}
