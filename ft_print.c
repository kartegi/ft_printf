/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:20:06 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/25 15:55:54 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print(const char *format, va_list arglist, t_flag *mod)
{
	int i;

	i = 0;
	while(format[i] != ' ' || format[i] != '%' || format[i])
	{
		if(format[i] == 'c')
			ft_putchar(va_arg(arglist, int));
		else if (format[i] == 's')
			ft_putstr(va_arg(arglist, char *));
		else if (format[i] == 'p')
			mod->x = 1;
		else if (format[i] == 'o')
			mod->x = 1;
		else if (format[i] == 'd' || format[i] == 'i')
			ft_putnbr(va_arg(arglist, int));
		else if (format[i] == 'u')
			mod->x = 1;
		else if (format[i] == 'x' || format[i] == 'X')
			mod->x = 1;
		else if (format[i] == 'f')
			mod->x = 1;
		else
			return (0);
	}
	return (i);
}