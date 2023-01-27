/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:41:44 by sungjuki          #+#    #+#             */
/*   Updated: 2022/08/25 11:24:03 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putmatrix_fd(char **m, int nl, int fd)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (m && m[i])
	{
		if (nl)
			cnt += ft_putendl_fd(m[i], fd);
		else
			cnt += ft_putstr_fd(m[i], fd);
		i++;
	}
	return (cnt);
}
