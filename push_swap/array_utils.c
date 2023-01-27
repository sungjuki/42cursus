/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:53:36 by sungjuki          #+#    #+#             */
/*   Updated: 2022/06/09 21:33:14 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;
	int			checker;

	res = 0;
	sign = 1;
	checker = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	while (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
		checker++;
	}
	res = res * sign;
	if (*str != '\0' || checker > 10
		|| res > 2147493647 || res < -2147483648)
		print_error(1);
	return ((int)res);
}

int	get_size_split_str(char **split_str)
{
	int	idx;

	idx = 0;
	while (split_str[idx])
		idx++;
	return (idx);
}

void	ft_free_str(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

void	set_str_to_arr(int *arr, int *arr_idx, char **str)
{
	int	tmp_num;
	int	idx;

	idx = 0;
	while (str[idx])
	{
		tmp_num = ft_atoi(str[idx]);
		arr[*arr_idx] = tmp_num;
		(*arr_idx)++;
		idx++;
	}
}
