/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:49:37 by sungjuki          #+#    #+#             */
/*   Updated: 2022/08/22 11:49:01 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	idx;

	if (!s)
		return (0);
	len = ft_strlen(s);
	idx = 0;
	while (idx < len)
	{
		write(fd, &s[idx], 1);
		idx++;
	}
	return (++idx);
}
