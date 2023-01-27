/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:56:38 by sungjuki          #+#    #+#             */
/*   Updated: 2022/09/28 21:30:27 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	action_eat(t_table *table, t_philo *philos, int i)
{
	pthread_mutex_lock(&table->mutex->eat_m);
	state_print(EAT_E, table, philos, i);
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
