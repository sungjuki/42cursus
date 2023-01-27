/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:03:25 by sungjuki          #+#    #+#             */
/*   Updated: 2022/04/01 14:25:21 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(t_box *box)
{
	int		res_len;
	char	chr;

	chr = (char)(box->value);
	res_len = 0;
	res_len += ft_printf_leftmargin(box);
	res_len += write(1, &chr, 1);
	res_len += ft_printf_rightmargin(box);
	return (res_len);
}

int	ft_printf_leftmargin(t_box *box)
{
	int	res_len;
	int	i;

	i = -1;
	res_len = 0;
	if (box->left_margin > (int) sizeof(char))
		while (++i + (int) sizeof(char) < box->left_margin)
			res_len += write(1, " ", 1);
	return (res_len);
}

int	ft_printf_rightmargin(t_box *box)
{
	int	res_len;
	int	i;

	i = -1;
	res_len = 0;
	if (box->right_margin > (int) sizeof(char))
		while (++i + (int) sizeof(char) < box->right_margin)
			res_len += write(1, " ", 1);
	return (res_len);
}
