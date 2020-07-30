/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:40:13 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/28 18:12:29 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_handle_c(t_flag *mod, va_list arglist)
{
	if(mod->width-- && !mod->minus)
		ft_handle_width(mod);
	ft_putchar(va_arg(arglist, int));
	if(mod->width && mod->minus)
		ft_handle_width(mod);
}