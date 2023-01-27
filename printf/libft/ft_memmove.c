/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:10:41 by sungjuki          #+#    #+#             */
/*   Updated: 2022/01/07 12:31:06 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;
	size_t			idx;

	if (dst == 0 && src == 0)
		return (0);
	if (len == 0)
		return (dst);
	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	idx = -1;
	if (c_dst < c_src)
	{
		while (++idx < len)
			c_dst[idx] = c_src[idx];
	}
	else
	{
		idx = len;
		while (--idx > 0)
			c_dst[idx] = c_src[idx];
		c_dst[0] = c_src[0];
	}
	return (dst);
}
