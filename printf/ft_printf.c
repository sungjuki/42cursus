/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:33:28 by sungjuki          #+#    #+#             */
/*   Updated: 2022/04/02 13:57:44 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_sub(const char *format, va_list ap,
		t_options *options, t_box *box)
{
	int	res_len;
	int	i;

	i = 0;
	res_len = 0;
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			res_len += write(1, &format[i++], 1);
		if (format[i] == '%')
		{
			options = init_options(options);
			i++;
			while (format[i] != '\0' && !ft_strchr(TYPE, format[i]))
				options = ft_read_options(options, ap, format, i++);
			options->type = format[i++];
			box = init_box(box);
			if (ft_strchr(TYPE, options->type)
				&& ft_printf_boxing(options, box, ap))
				res_len += ft_printf_type(options, box);
			else
				res_len = -1;
		}
	}
	return (res_len);
}
/*
** until format[i] meets % print string
** until format[i] meets 'TYPE' read options
** after format[i] meets 'TYPE' print arg
** repeat until format[i] meets '\0'
*/

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_box		*box;
	t_options	*options;
	int			res_len;

	options = (t_options *)malloc(sizeof(t_options));
	if (!options)
		return (-1);
	box = (t_box *)malloc(sizeof(t_box));
	if (!box)
	{
		free(options);
		return (-1);
	}
	va_start(ap, format);
	res_len = ft_printf_sub(format, ap, options, box);
	free(options);
	free(box);
	va_end(ap);
	return (res_len);
}
