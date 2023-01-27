/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:49:37 by sungjuki          #+#    #+#             */
/*   Updated: 2021/12/13 12:56:11 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	size_t	idx;

	if (!s)
		return ;
	len = ft_strlen(s);
	idx = 0;
	while (idx < len)
	{
		write(fd, &s[idx], 1);
		idx++;
	}
}
