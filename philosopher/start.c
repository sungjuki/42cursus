/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:12:04 by sungjuki          #+#    #+#             */
/*   Updated: 2022/09/28 21:18:39 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_thread(t_table *table, int philo_max)
{
	int	i;

	i = 0;
	while (i < philo_max)
	{
		if (pthread_create(&table[i].philos[i].thread_id, NULL, \
			&routine, &table[i]) != 0)
			return (-1);
		i += 2;
	}
	usleep(5000);
	i = 1;
	while (i < philo_max)
	{
		if (pthread_create(&table[i].philos[i].thread_id, NULL, \
			&routine, &table[i]) != 0)
			return (-1);
		i += 2;
	}
	return (0);
}

int	start(t_arg *arg)
{
	t_table	*table;
	int		i;

	table = create_arg(arg);
	if (table == NULL)
		return (-1);
	if (start_thread(table, arg->philo_max) != 0)
		return (-1);
	while (exit_check(table, arg, table->philos) == FALSE_E)
		usleep(100);
	i = -1;
	while (++i < arg->philo_max)
		pthread_join(table[i].philos[i].thread_id, NULL);
	all_free(table, table->mutex, arg->philo_max);
	return (0);
}
