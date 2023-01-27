/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:28:04 by sungjuki          #+#    #+#             */
/*   Updated: 2021/12/22 13:17:04 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char s, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

static char	*make_str(char *rst, char const *s1, size_t	tp1, size_t tp2)
{
	size_t	idx;

	idx = 0;
	while (tp1 + idx < tp2)
	{
		rst[idx] = s1[tp1 + idx];
		idx++;
	}
	rst[idx] = 0;
	return (rst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rst;
	size_t	tp1;
	size_t	tp2;
	size_t	idx;

	if (!s1 || !set)
		return ((char *)s1);
	tp1 = 0;
	while (s1[tp1] && is_set(s1[tp1], set))
		tp1++;
	tp2 = ft_strlen(s1);
	idx = 0;
	while (tp2 - idx > tp1 + 1 && is_set(s1[tp2 - 1 - idx], set))
		idx++;
	tp2 = tp2 - idx;
	rst = (char *)malloc(sizeof(char) * (tp2 - tp1) + 1);
	if (!rst)
		return (0);
	rst = make_str(rst, s1, tp1, tp2);
	return (rst);
}
