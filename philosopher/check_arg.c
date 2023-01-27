/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:55:29 by sungjuki          #+#    #+#             */
/*   Updated: 2022/09/28 17:21:17 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_num_check(char *argv)
{
	int	index;

	index = 0;
	if (argv == NULL)
		return (FALSE_E);
	while (argv[index])
	{
		if (ft_isdigit(argv[index]) == FALSE_E)
			return (FALSE_E);
		++index;
	}
	return (TRUE_E);
}

static t_bool	argv_transfer(int argc, char **argv)
{
	int		index;
	ssize_t	temp;

	index = 1;
	temp = ft_atoi(argv[index]);
	while (index < argc)
	{
		temp = ft_atoi(argv[index]);
		if (temp <= 0 || temp > 2147483647)
			return (FALSE_E);
		temp = 0;
		++index;
	}
	return (TRUE_E);
}

t_bool	check_arg(int argc, char **argv)
{
	int	index;

	index = 1;
	if (argc != 5 && argc > 6)
		return (FALSE_E);
	while (index < argc)
	{
		if (is_num_check(argv[index]) == FALSE_E)
			return (FALSE_E);
		++index;
	}
	if (argv_transfer(argc, argv) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}
