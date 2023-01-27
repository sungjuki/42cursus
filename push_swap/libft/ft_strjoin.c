/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:49:28 by sungjuki          #+#    #+#             */
/*   Updated: 2021/12/17 14:48:45 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rst;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
	{
		if (!s1)
			return ((char *)s2);
		else
			return ((char *)s1);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	rst = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!rst)
		return (0);
	ft_memcpy(rst, s1, s1_len);
	ft_memcpy(rst + s1_len, s2, s2_len);
	rst[s1_len + s2_len] = 0;
	return (rst);
}
