/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:07:50 by sungjuki          #+#    #+#             */
/*   Updated: 2022/04/01 14:36:29 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(t_box *box)
{
	int		res_len;
	char	*str;

	res_len = 0;
	str = (char *)box->value;
	if (box->precision > -1 && box->precision < box->value_len)
		box->value_len = box->precision;
	res_len += ft_printf_leftmargin_str(box);
	res_len += write(1, str, box->value_len);
	res_len += ft_printf_rightmargin_str(box);
	return (res_len);
}

int	ft_printf_leftmargin_str(t_box *box)
{
	int		res_len;
	int		i;
	char	padding_char;

	i = -1;
	res_len = 0;
	padding_char = ' ';
	while (++i + box->value_len < box->left_margin)
		res_len += write(1, &padding_char, 1);
	return (res_len);
}

int	ft_printf_rightmargin_str(t_box *box)
{
	int		res_len;
	int		i;

	i = -1;
	res_len = 0;
	if (box->right_margin > box->value_len)
		while (++i + box->value_len < box->right_margin)
			res_len += write(1, " ", 1);
	return (res_len);
}
