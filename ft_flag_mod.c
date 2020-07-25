/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:22:43 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/21 11:59:37 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_tozero(t_mod *mod)
{
	mod->length = 0;
	mod->dash = 0;
	mod->plus = 0;
	mod->minus = 0;
	mod->zero = 0;
	mod->hesh = 0;
	mod->width = 0;
	mod->precision = 0;
	mod->l = 0;
	mod->ll = 0;
	mod->L = 0;
	mod->h = 0;
	mod->hh = 0;
}

t_mod	*ft_flag(char *format)
{
	int		i;

	i = 0;
	while(!ft_strchar(CONV, format[i]))
	{
		if(format[i] == '-' && mod->minus)
			mod->minus = 1;
		else if (format[i] == '+' && !mod->plus)
			mod->plus = 1;
		else if (format[i] == '-' && !mod->dash)
			mod->dash = 1;
		else if (format[i] == '0' && !mod->zero)
			mod->zero = 1;
		else if (format[i] == '#' && !mod->hesh)
			mod->hesh = 1;
		else if (format[i] == '+' && !mod->plus)
			mod->plus = 1;
		else if (format[i] == '+' && !mod->plus)
			mod->plus = 1;
	}
}

t_mod	*ft_flag_mod()