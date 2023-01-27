/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:34:27 by sungjuki          #+#    #+#             */
/*   Updated: 2021/12/08 12:59:01 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c_dst;
	size_t			i;

	if (!dst && !src)
		return (0);
	c_dst = dst;
	i = 0;
	while (i++ < n)
		*c_dst++ = *(unsigned char *)src++;
	return (dst);
}
