/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:29:04 by sungjuki          #+#    #+#             */
/*   Updated: 2022/03/23 11:37:27 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_options	*init_options(t_options *options)
{
	options->flag[0] = 0;
	options->width = 0;
	options->precision = -1;
	options->type = 0;
	return (options);
}

t_box	*init_box(t_box *box)
{
	box->left_margin = 0;
	box->right_margin = 0;
	box->sign = 0;
	box->zero_len = 0;
	box->prefix_len = 0;
	box->value = 0;
	box->value_len = 0;
	box->base_len = (int)ft_strlcpy(box->base, "0123456789", 11);
	box->precision = -1;
	return (box);
}

int	options_flag_check(t_options *options)
{
	int	i;

	i = -1;
	while (options->flag[++i])
		if (!ft_strchr(FLAG, options->flag[i]))
			return (0);
	return (1);
}
