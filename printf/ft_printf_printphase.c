/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printphase.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:56:02 by sungjuki          #+#    #+#             */
/*   Updated: 2022/04/01 14:22:13 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_type(t_options *options, t_box *box)
{
	int	res_len;

	res_len = 0;
	if (options->type == 'c' || options->type == '%')
		res_len += ft_printf_char(box);
	else if (options->type == 's')
		res_len += ft_printf_str(box);
	else if (options->type == 'd' || options->type == 'i')
		res_len += ft_printf_nbr(box);
	else if (options->type == 'x'
		|| options->type == 'X'
		|| options->type == 'u')
		res_len += ft_printf_unsigned(box);
	else if (options->type == 'p')
		res_len += ft_printf_pnt(box);
	return (res_len);
}
