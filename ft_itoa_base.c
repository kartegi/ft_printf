/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:40:34 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/30 14:34:14 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_itoa_base(uintmax_t num, int base, t_flag *mod)
{
	int			i;
	uintmax_t	val_cp;
	int			rem;
	char		*str;
	int 		pre_len;

	val_cp = num;
	i = 1;
	pre_len = 0;
	while((val_cp /= base) >= 1)
		i++;
	if(mod->precision_flag && mod->precision > i)
		i += (pre_len = mod->precision - i);
	str = ft_strnew(i);
	str[i] = '\0';
	while(i-- > pre_len)
	{
		rem = num % base;
		str[i] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		num /= base;
	}
	if(pre_len)
		while(i-- > pre_len)
			str[i] = '0';
	return (str);
}
