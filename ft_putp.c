/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 20:34:44 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/14 14:04:44 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putp(void *p0)
{
	unsigned int x;
	char* str;
	uintmax_t p;

	p = (uintmax_t)p0;
	str = ft_itoa_base(p, 16);
	ft_putstr("0x");
	ft_putstr(str);
	free(str);
}