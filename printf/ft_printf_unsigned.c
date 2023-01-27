/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:08:28 by sungjuki          #+#    #+#             */
/*   Updated: 2022/04/01 14:49:51 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** ##########################
** ####   ft_printf_uni  ####
** ##########################
** if value is minus, make it plus
** if value is 0 and box has precision, value_len becomes 0. (nothing print)
** print_left_margin(padding char <- width , zero num <-, no sign, prefix, value
** if left_arrangement('-' flag -> no_zero, no sign, prefix, value, right_margin)
*/
int	ft_printf_unsigned(t_box *box)
{
	int		ret_len;
	char	*nbr_str;

	ret_len = 0;
	if (box->value == 0 && box->precision > -1)
		box->value_len = 0;
	nbr_str = ull_to_hexbase(box->value, box->base);
	if (box->prefix_len == 2 && box->value != 0)
	{
		box->left_margin -= 2;
		box->right_margin -= 2;
	}
	ret_len += ft_printf_leftmargin_nbr(box);
	ret_len += write(1, nbr_str, box->value_len);
	ret_len += ft_printf_rightmargin_nbr(box);
	free(nbr_str);
	return (ret_len);
}
