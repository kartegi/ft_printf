/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:54:20 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/25 16:12:23 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

#define CONV	"csidfxXop"
#define	MOD		".*123456789"

#include <stdarg.h>
#include "./libft/libft.h"
#include <stdint.h>

typedef struct	s_mod
{
	int			x;
	int			minus;
	int			plus;
	int			zero;
	int			hash;
	int			width;
	int			precision;
	int			l;
	int			ll;
	int			L;
	int			h;
	int			hh;
}				t_flag;


char	*ft_itoa_base(uintmax_t num, int base);
//void	ft_putp(void *p0);
int		ft_printf(const char *format, ...);
void	ft_putnbr_u(unsigned int n);
void	ft_tozero(t_flag *mod);
//int		ft_parse(char *format, va_list arglist);
int		ft_flag(t_flag *mod, const char *format, va_list arglist);
int		ft_mod(t_flag *mod, const char *format, va_list arglist);
int		ft_getnum(const char *format, int i, t_flag *mod);
int		ft_size(const char *format, int i, t_flag *mod);
int		ft_print(const char *format, va_list arglist, t_flag *mod);

#endif