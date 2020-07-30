/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:40:34 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/29 12:31:07 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_itoa_base(uintmax_t num, int base)
{
	int			i;
	uintmax_t	val_cp;
	int			rem;
	char		*str;

	val_cp = num;
	i = 1;
	while((val_cp /= base) >= 1)
		i++;
	str = ft_strnew(i);
	str[i] = '\0';
	while(i-- > 0)
	{
		rem = num % base;
		str[i] = (rem > 9)? (rem-10) + 'a' : rem + '0';
		num /= base;
	}
	return (str);
}
