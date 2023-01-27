/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_preprocess.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:49:29 by sungjuki          #+#    #+#             */
/*   Updated: 2022/04/02 16:12:31 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
** ###########################
** ##### ft_read_arg_pnt #####
** ###########################
**
** '*' -> read_astrsk
** precision == -1 -> width value
** precision != -1 -> precision value
*/

t_options	*ft_read_astrsk(t_options *options, va_list ap)
{
	if (options->precision == -1)
	{
		options->width = va_arg(ap, int);
		if (options->width < 0)
		{
			ft_strlcat(options->flag, "-", ft_strlen(options->flag) + 2);
			options->width *= -1;
		}
	}
	else
		options->precision = va_arg(ap, int);
	if (options->precision < 0)
		options->precision = -1;
	return (options);
}

/*
** ###########################
** ##### ft_read_options #####
** ###########################
**
** '*' -> read_astrsk
** '0' -> 1) first appear -> '0' flag
**   -> 2) else if -> width or precision number(after '.')
** 'flag' -> strlcat to options -> flag
*/
t_options	*ft_read_options(t_options *options, va_list ap,
		const char *format, int i)
{	
	if (format[i] == '*')
		options = ft_read_astrsk(options, ap);
	else if (format[i] == '0'
		&& options->width == 0
		&& options->precision == -1)
	{
		if (!ft_strchr(options->flag, '0'))
			ft_strlcat(options->flag, "0", ft_strlen(options->flag) + 2);
	}
	else if (ft_isdigit(format[i]) && options->precision == -1)
		options->width = (options->width * 10) + (format[i] - '0');
	else if (ft_isdigit(format[i]))
		options->precision = (options->precision * 10) + (format[i] - '0');
	else if (format[i] == '.')
		options->precision = 0;
	else if (ft_strchr(FLAG, format[i])
		&& !ft_strchr(options->flag, format[i]))
		ft_strlcat(options->flag, &format[i], ft_strlen(options->flag) + 2);
	return (options);
}
/*
** ##########################
** #### ft_printf_boxing ####
** ##########################
**
** flag assignment
** value_len_precision
** margin assignment
*/

int	ft_printf_boxing(t_options *options, t_box *box, va_list ap)
{
	if (!ft_strchr(TYPE, options->type) || !options_flag_check(options))
		return (0);
	if (options->type == 'c'
		|| options->type == 'd'
		|| options->type == 'i')
		box->value = va_arg(ap, int);
	else if (options->type == 'u'
		|| options->type == 'x'
		|| options->type == 'X')
		box->value = va_arg(ap, unsigned int);
	else if (options->type == 's'
		|| options->type == 'p')
		box->value = va_arg(ap, unsigned long long);
	else if (options->type == '%')
		box->value = '%';
	if (!ft_boxing_flag_n_base(options, box))
		return (0);
	if (!ft_boxing_value_len_n_precision(options, box))
		return (0);
	if (!ft_boxing_margin(options, box))
		return (0);
	return (1);
}
