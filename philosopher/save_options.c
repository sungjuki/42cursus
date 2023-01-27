/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:14:08 by sungjuki          #+#    #+#             */
/*   Updated: 2022/09/28 17:17:44 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_arg	*arg_save(int argc, char **argv)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (arg == NULL)
		return (NULL);
	arg->philo_max = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->must_eat_count = ft_atoi(argv[5]);
	else
		arg->must_eat_count = -1;
	return (arg);
}
