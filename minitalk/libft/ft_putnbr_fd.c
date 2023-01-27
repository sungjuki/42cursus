/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:33:13 by sungjuki          #+#    #+#             */
/*   Updated: 2021/12/17 14:03:33 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div;
	int		mod;
	char	buf;

	div = n / 10;
	mod = n % 10;
	if (n < 0)
	{
		write(fd, "-", 1);
		div = -div;
		mod = -mod;
	}
	if (div != 0)
		ft_putnbr_fd(div, fd);
	buf = mod + '0';
	write(fd, &buf, 1);
}
