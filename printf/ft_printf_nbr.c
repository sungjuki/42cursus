/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:04:54 by sungjuki          #+#    #+#             */
/*   Updated: 2022/04/01 14:42:03 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ###########################
** ####   ft_printf_nbr   ####
** ###########################
** if value is minus, make it plus
** if value is 0 and box has precision, value_len becomes 0. (nothing print)
** print_left_margin(padding char <- width , zero num <-, no sign, prefix, value
** if left_arrangement('-' flag -> no_zero, no sign, prefix, value, right_margin)
*/
int	ft_printf_nbr(t_box *box)
{
	int		res_len;
	char	*nbr_str;

	res_len = 0;
	if (box->value == 0 && box->precision > -1)
		box->value_len = 0;
	if (box->sign)
	{
		box->left_margin -= 1;
		box->right_margin -= 1;
		if (box->sign == '-')
			box->value *= -1;
	}
	nbr_str = ft_uitoa(box->value);
	res_len += ft_printf_leftmargin_nbr(box);
	res_len += write(1, nbr_str, box->value_len);
	res_len += ft_printf_rightmargin_nbr(box);
	free(nbr_str);
	return (res_len);
}

/*
** ########################################
** #####   ft_printf_lft_margin_nbr   #####
** ########################################
** print_left_margin(padding char <- width , zero num <-, sign, prefix)
** if (flag '0' -> zero_len == width, padding char becomes '0')
** if precision > value_len -> padding char becomes '0'
** zero_len = precison - value_len
** if it needs to print sign -> jump to sing case
** else no sign case
** print prefix (last left_margin print)
*/
int	ft_printf_leftmargin_nbr(t_box *box)
{
	int		res_len;
	int		i;
	char	padding_char;

	i = -1;
	res_len = 0;
	padding_char = ' ';
	if (box->zero_len && box->precision == -1)
		padding_char = '0';
	box->zero_len = 0;
	if (box->precision - box->value_len > 0)
		box->zero_len += box->precision - box->value_len;
	if (box->sign)
		res_len += ft_print_sign_case_padding_nbr(box, padding_char);
	else if (box->sign == 0)
		res_len += ft_print_no_sign_case_padding_nbr(box, padding_char);
	if (box->prefix_len && box -> value != 0)
	{
		if (ft_strchr(box->base, 'a'))
			res_len += write(1, "0x", 2);
		else if (ft_strchr(box->base, 'A'))
			res_len += write(1, "0X", 2);
	}
	return (res_len);
}

/*
** ##################################################
** #######   ft_printf_no_sign_case_padd   ##########
** ##################################################
** if no sign
** after padding char print, print zero_len (if precision case)
*/

int	ft_print_no_sign_case_padding_nbr(t_box *box, char padding_char)
{
	int		res_len;
	int		i;

	i = -1;
	res_len = 0;
	while (++i + (box->value_len) + (box->zero_len)
		< box->left_margin)
		res_len += write(1, &padding_char, 1);
	i = -1;
	while (++i < box -> zero_len)
		res_len += write(1, "0", 1);
	return (res_len);
}
/*
** ########################################
** #####   ft_printf_sign_case_padd   #####
** ########################################
** if padding char is '0' -> 1. sign 2. padding char
** else if padding char is ' ' -> 1. padding char 2. sign
** after padding char print, print zero_len (if precision case)
*/

int	ft_print_sign_case_padding_nbr(t_box *box, char padding_char)
{
	int		res_len;
	int		i;

	res_len = 0;
	i = -1;
	if (padding_char == '0')
	{
		res_len += write(1, &box -> sign, 1);
		while (++i + (box->value_len)
			+ (box->zero_len) < box->left_margin)
			res_len += write(1, &padding_char, 1);
	}
	else if (padding_char == ' ')
	{
		while (++i + (box->value_len)
			+ (box->zero_len) < box->left_margin)
			res_len += write(1, &padding_char, 1);
		res_len += write(1, &box->sign, 1);
	}
	i = -1;
	while (++i < box->zero_len)
		res_len += write(1, "0", 1);
	return (res_len);
}
/*
** ####################################
** ######   ft_printf_rigt_mrg   ######
** ####################################
** after print zero_len print right_margin
** padding char always ' ' 
*/

int	ft_printf_rightmargin_nbr(t_box *box)
{
	int	res_len;
	int	i;

	i = -1;
	res_len = 0;
	while (++i + (box->value_len) + (box->zero_len) < box->right_margin)
		res_len += write(1, " ", 1);
	return (res_len);
}
