/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:08:24 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/28 17:29:25 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_handle_width(t_flag *mod)
{
	int		i;

	i = mod->width;
	if (mod->width > 0)
	{
		while (i)
		{
			if (mod->zero && !mod->minus)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i--;
			mod->len++;
		}
	}
}
