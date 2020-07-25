/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:00:25 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/16 14:27:02 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "libft/libft.h"
void	ft_putnbr_u(unsigned int n)
{
	int	i;
	int j;
	unsigned int uint_tmp;

	i = 0;
	uint_tmp = n;
	if(n == 0)
		ft_putchar('0');
	while(uint_tmp > 0)
	{
		uint_tmp = uint_tmp / 10;
		i++;
	}
	while(i > 0)
	{
		j = i;
		uint_tmp = n;
		while(j > 1)
		{
			uint_tmp = uint_tmp / 10;
			j--;
		}
		ft_putchar(uint_tmp % 10 + '0');
		i--;
	}
}