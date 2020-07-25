/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:57:35 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/25 13:45:14 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_tozero(t_flag *mod)
{
	mod->plus = 0;
	mod->minus = 0;
	mod->zero = 0;
	mod->hash = 0;
	mod->width = 0;
	mod->precision = 0;
	mod->l = 0;
	mod->ll = 0;
	mod->L = 0;
	mod->h = 0;
	mod->hh = 0;
}


int		ft_parse(char *format, va_list arglist)
{
	t_flag	*mod;
	int		i;

	if (!(mod = (t_flag*)malloc(sizeof(t_flag))))
		return (0);
	if (!ft_typecheck(format))
		return (0);
	ft_tozero(t_flag);
	ft_flag(mod, format, arglist);
	i = ft_print(format, arglist, mod);
	free(mod);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int			count;
	int			i;
	va_list		arglist;
	int			flag;

	i	 = 0;
	count = 0;
	va_start(arglist, format);
	while(format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			if(!ft_parse(&format[i], arglist))
				return (-1);
		}
		else
			ft_putchar(++i);
		count++;
	}
	return(flag + count);
}