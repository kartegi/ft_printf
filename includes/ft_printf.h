/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:54:20 by ktennie           #+#    #+#             */
/*   Updated: 2020/08/05 16:34:39 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H

# define SIZE		"lhL"
# define CONV		"csuidfxXop"
# define MOD		".*123456789"
# define CHECKALL	"lhLcsuidfxXop.*123456789"

# include <stdarg.h>
# include "libft.h"
# include <stdint.h>
# include <limits.h>
#include <stdio.h>

typedef struct	s_mod
{
	int			i;
	int 		space;
	int			len;
	int			upper;
	int 		flag;
	int			minus;
	int			plus;
	int			negative;
	int			zero;
	int			hash;
	int			width;
	int			precision;
	int			precision_flag;
	int			l;
	int			ll;
	int			b;
	int			h;
	int			hh;
}				t_flag;

char			*ft_itoa_base(uintmax_t num, int base, t_flag *mod);
int				ft_printf(const char *format, ...);
void			ft_tozero(t_flag *mod);
int 			ft_parse(const char *format, va_list arglist, t_flag *mod);
int				ft_flag(const char *format, va_list arglist, t_flag *mod);
void			ft_mod(const char *format, va_list arglist, t_flag *mod);
int				ft_getnum(const char *format, int i, t_flag *mod);
int				ft_size(const char *format, t_flag *mod);
int				ft_print_conv(const char *format, va_list arglist, t_flag *mod);
void			ft_handle_c(t_flag *mod, va_list arglist);
void			ft_handle_width(t_flag *mod);
void			ft_handle_s(t_flag *mod, va_list arglist);
void			ft_handle_p(t_flag *mod, va_list arglist);
void			ft_handle_d(t_flag *mod, va_list arglist);
void			ft_handle_o(t_flag *mod, va_list arglist);
void			ft_handle_x(t_flag *mod, va_list arglist);
void			ft_handle_u(t_flag *mod, va_list arglist);
void			ft_put_float(long double n, t_flag *mod);
void			ft_handle_f(t_flag *mod, va_list arglist);

#endif
