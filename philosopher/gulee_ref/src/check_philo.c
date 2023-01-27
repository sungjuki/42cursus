/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:42:14 by gulee             #+#    #+#             */
/*   Updated: 2022/08/29 00:12:50 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	exit_check(t_table *tab, t_arg *arg, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < arg->philo_max)
	{
		if (arg->must_eat_count >= 0 && eat_check(tab, arg) == TRUE_E)
		{
			pthread_mutex_lock(&tab->mutex->finish_m);
			*tab->finish = FALSE_E;
			pthread_mutex_unlock(&tab->mutex->finish_m);
			state_print(FINISH_E, tab, philos, i);
			return (TRUE_E);
		}
		if (get_timediff(philos[i].last_eat) > arg->time_to_die)
		{
			pthread_mutex_lock(&tab->mutex->finish_m);
			*tab->finish = FALSE_E;
			pthread_mutex_unlock(&tab->mutex->finish_m);
			state_print(DIED_E, tab, philos, i);
			if (arg->philo_max == 1)
				pthread_mutex_unlock(&tab->mutex->fork_m[philos[i].fork_r - 1]);
			return (TRUE_E);
		}
	}
	return (FALSE_E);
}

t_bool	eat_check(t_table *table, t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->philo_max)
	{
		pthread_mutex_lock(&table->mutex->eat_m);
		if (arg->must_eat_count > table->philos[i].eat_count)
		{
			pthread_mutex_unlock(&table->mutex->eat_m);
			return (FALSE_E);
		}
		pthread_mutex_unlock(&table->mutex->eat_m);
		i++;
	}
	return (TRUE_E);
}

t_bool	is_finish(t_table *table)
{
	pthread_mutex_lock(&table->mutex->finish_m);
	if (*table->finish == TRUE_E)
	{
		pthread_mutex_unlock(&table->mutex->finish_m);
		return (TRUE_E);
	}
	pthread_mutex_unlock(&table->mutex->finish_m);
	return (FALSE_E);
}
