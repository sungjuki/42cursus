/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:18:44 by sungjuki          #+#    #+#             */
/*   Updated: 2021/12/21 13:46:07 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	idx;
	char	*ans;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	ans = (char *)malloc(sizeof(char) * len + 1);
	if (!ans)
		return (0);
	idx = 0;
	while (idx < len)
	{
		ans[idx] = f(idx, s[idx]);
		idx++;
	}
	ans[idx] = 0;
	return (ans);
}
