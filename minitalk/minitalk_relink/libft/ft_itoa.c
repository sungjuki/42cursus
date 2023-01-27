/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:42:04 by sungjuki          #+#    #+#             */
/*   Updated: 2021/12/21 17:24:35 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long long nbr, int sign)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		i++;
		nbr = nbr / 10;
	}
	if (sign == -1)
		i++;
	return (i);
}

static void	put_itoa(long long nbr, char *ans, int sign, int len)
{
	if (nbr == 0)
	{
		ans[0] = '0';
		ans[1] = 0;
		return ;
	}
	ans[len] = 0;
	while (nbr != 0)
	{
		ans[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	if (sign == -1)
		ans[--len] = '-';
}

char	*ft_itoa(int n)
{
	int			len;
	int			sign;
	long long	nbr;
	char		*ans;

	nbr = n;
	sign = 1;
	if (n < 0)
	{
		sign *= -1;
		nbr = -nbr;
	}
	len = ft_nbrlen(nbr, sign);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (0);
	put_itoa(nbr, ans, sign, len);
	return (ans);
}
