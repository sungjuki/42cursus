/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:40:57 by sungjuki          #+#    #+#             */
/*   Updated: 2021/12/21 17:15:45 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s && (*s != c))
				s++;
		}
		if (!*s)
			return (cnt);
		else
			s++;
	}
	return (cnt);
}

static void	ft_strcpy(char *s, char *start, char *end)
{
	while (start < end)
		*s++ = *start++;
	*s = 0;
}

static char	**all_free(char **ans, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(ans[i]);
		ans[i] = 0;
		i++;
	}
	free(ans);
	return (0);
}

static char	**make_split_str(char **ans, char *s, char c, int idx)
{
	char	*start;
	char	*end;

	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && (*s != c))
				s++;
			end = s;
			ans[idx] = (char *)malloc(sizeof(char) * (end - start + 1));
			if (!ans[idx])
				return (all_free(ans, idx));
			ft_strcpy(ans[idx++], start, end);
		}
		if (!*s)
			break ;
		s++;
	}
	ans[idx] = 0;
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		idx;
	char	**ans;

	if (!s)
		return (0);
	words = word_cnt(s, c);
	idx = 0;
	ans = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ans)
		return (0);
	ans = make_split_str(ans, (char *)s, c, idx);
	return (ans);
}
