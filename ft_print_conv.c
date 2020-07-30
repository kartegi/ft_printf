/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:20:06 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/29 15:58:32 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_print_conv(const char *format, va_list arglist, t_flag *mod)
{
	if(ft_strchr(CONV, format[mod->i]))
	{
		if(format[mod->i] == 'c')
			ft_handle_c(mod, arglist);
		else if (format[mod->i] == 's')
			ft_handle_s(mod, arglist);
		else if (format[mod->i] == 'p')
			ft_handle_p(mod, arglist);
		else if (format[mod->i] == 'd' || format[mod->i] == 'i')
			ft_handle_d(mod, arglist);
		else if (format[mod->i] == 'o')
			mod->x = 1;
		else if (format[mod->i] == 'u')
			mod->x = 1;
		else if (format[mod->i] == 'x' || format[mod->i] == 'X')
			mod->x = 1;
		else if (format[mod->i] == 'f')
			mod->x = 1;
	}
	return (0);
}