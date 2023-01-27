/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:45:57 by gulee             #+#    #+#             */
/*   Updated: 2022/08/29 00:19:10 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	action_eat(t_table *table, t_philo *philos, int i)
{
	state_print(EAT_E, table, philos, i);
	pthread_mutex_lock(&table->mutex->eat_m);
	philos[i].eat_count++;
	pthread_mutex_unlock(&table->mutex->eat_m);
	philo_pause(philos[i].arg->time_to_eat, table);
	pthread_mutex_unlock(&table->mutex->fork_m[philos[i].fork_l - 1]);
	pthread_mutex_unlock(&table->mutex->fork_m[philos[i].fork_r - 1]);
	if (eat_check(table, philos[i].arg) != TRUE_E)
		state_print(SLEEP_E, table, philos, i);
	philo_pause(philos[i].arg->time_to_sleep, table);
	if (eat_check(table, philos[i].arg) != TRUE_E)
		state_print(THINK_E, table, philos, i);
}

static int	action_fork(t_table *table, t_philo *philos, int i)
{
	pthread_mutex_lock(&table->mutex->fork_m[philos[i].fork_r - 1]);
	state_print(FORK_E, table, philos, i);
	if (table->philos->arg->philo_max <= 1)
		return (-1);
	pthread_mutex_lock(&table->mutex->fork_m[philos[i].fork_l - 1]);
	state_print(FORK_E, table, philos, i);
	return (0);
}

void	*routine(void *arg)
{
	t_table		*table;
	t_philo		*philos;
	int			i;
	int			j;

	table = (t_table *)arg;
	i = table->i;
	philos = table->philos;
	j = 0;
	while (is_finish(table) == TRUE_E)
	{
		if (philos->arg->must_eat_count > 0 && j >= philos->arg->must_eat_count)
			break ;
		if (action_fork(table, philos, i) == 0)
				action_eat(table, philos, i);
		++j;
	}
	return (NULL);
}
