/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:38:05 by sungjuki          #+#    #+#             */
/*   Updated: 2022/03/23 11:54:35 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ##############################
** ########   ft_uitoa   ########
** ##############################
** if n == 0, return "0" right away
** n should be bigger than 0
** for correct working of itoa_rec
** allocate digit_num + 1 for last '\0'
** fill the pnt[] from last index(remainder)
*/
char	*ft_uitoa(unsigned int n)
{
	int		digit_num;
	char	*pnt;

	if (n == 0)
		return (ft_strdup("0"));
	digit_num = get_malloc_size(n, "0123456789");
	pnt = (char *)malloc(sizeof(char) * digit_num + 1);
	if (pnt == NULL)
		return (NULL);
	pnt[digit_num] = 0;
	itoa_rec(n, digit_num - 1, &pnt);
	return (pnt);
}

/*
** ##############################
** #######   itoa_rec   #########
** ########EEE###################
** div n first to prevent the overflow
** while condition checks if n is 0 or not  
** so, if n is 0, we can not get right digit_num.
*/
void	itoa_rec(unsigned int n, int index, char **db_pnt)
{
	unsigned int	mod;
	unsigned int	div;
	char			*pnt;

	if (n == 0)
		return ;
	mod = n % 10;
	div = n / 10;
	pnt = *db_pnt;
	pnt[index] = mod + '0';
	itoa_rec(div, index - 1, db_pnt);
}

/*
** ##########################
** ####  ull_to_hexbase  ####
** ##########################
** div n first to prevent the overflow
** while condition checks if n is 0 or not  
** so, if n is 0, we can not get right digit_num.
*/
char	*ull_to_hexbase(unsigned long long nbr, char *base_to)
{
	int					malloc_size;
	int					i;
	char				*res_str;
	unsigned long long	tmp_nbr;

	malloc_size = get_malloc_size(nbr, base_to);
	res_str = (char *)malloc(sizeof(char) * malloc_size + 1);
	res_str[malloc_size] = '\0';
	tmp_nbr = nbr;
	i = malloc_size - 1;
	while (malloc_size-- > 0)
	{
		res_str[i--] = base_to[tmp_nbr % ft_strlen(base_to)];
		tmp_nbr /= ft_strlen(base_to);
	}
	return (res_str);
}

int	get_malloc_size(unsigned long long dec, char *base_to)
{
	int					to_base_len;
	int					len_for_malloc;
	unsigned long long	tmp;

	tmp = dec;
	to_base_len = ft_strlen(base_to);
	len_for_malloc = 0;
	while (tmp >= 0)
	{
		len_for_malloc++;
		tmp /= to_base_len;
		if (tmp == 0)
			break ;
	}
	return (len_for_malloc);
}
