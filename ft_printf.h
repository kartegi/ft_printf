/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktennie <ktennie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:54:20 by ktennie           #+#    #+#             */
/*   Updated: 2020/07/06 21:13:51 by ktennie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

#include <stdarg.h>
#include "./libft/libft.h"

typedef	struct		s_list
{
    int				precision;
    int				type;
    int				mfw;
    struct s_list	*next;
}					t_list;

#endif //FT_PRINTF_FT_PRINTF_H
