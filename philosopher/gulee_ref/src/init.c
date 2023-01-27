/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:45:27 by gulee             #+#    #+#             */
/*   Updated: 2022/08/28 23:04:34 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_mutex *mutex, int philo_max)
{
	int	i;

	i = -1;
	while (++i < philo_max)
		if (pthread_mutex_init(&mutex->fork_m[i], NULL) != 0)
			return (-1);
	if (pthread_mutex_init(&mutex->print_m, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&mutex->finish_m, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&mutex->eat_m, NULL) != 0)
		return (-1);
	return (0);
}

static t_mutex	*set_mutex(t_arg *arg)
{
	t_mutex	*mutex;

	mutex = malloc(sizeof(t_mutex));
	if (mutex == NULL)
		return (NULL);
	mutex->fork_m = malloc(sizeof(pthread_mutex_t) * arg->philo_max);
	if (mutex->fork_m == NULL)
		return (NULL);
	if (init_mutex(mutex, arg->philo_max) != 0)
		return (NULL);
	return (mutex);
}

static t_philo	*set_table(t_arg *arg)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * arg->philo_max);
	if (philos == NULL)
		return (NULL);
	while (i < arg->philo_max)
	{
		philos[i].arg = arg;
		philos[i].philo_id = i + 1;
		if (i < 1)
			philos[i].fork_l = arg->philo_max;
		else
			philos[i].fork_l = i;
		philos[i].fork_r = i + 1;
		gettimeofday(&philos[i].last_eat, NULL);
		philos[i].eat_count = 0;
		i++;
	}
	return (philos);
}

int	init_arg(t_table *table, t_philo *philos, t_mutex *mutex, int philo_max)
{
	int			i;
	t_bool		*finish;
	t_timeval	start;

	finish = malloc(sizeof(t_bool));
	if (finish == NULL)
		return (-1);
	*finish = TRUE_E;
	i = -1;
	while (++i < philo_max)
	{
		table[i].i = i;
		table[i].mutex = mutex;
		table[i].finish = finish;
		table[i].philos = philos;
	}
	i = -1;
	if (gettimeofday(&start, NULL) != 0)
		return (-1);
	while (++i < philo_max)
		table[i].start = start;
	return (0);
}

t_table	*create_arg(t_arg *arg)
{
	t_table	*table;
	t_mutex	*mutex;
	t_philo	*philos;

	table = malloc(sizeof(t_table) * arg->philo_max);
	if (arg == NULL)
		return (NULL);
	philos = set_table(arg);
	if (philos == NULL)
		return (NULL);
	mutex = set_mutex(arg);
	if (mutex == NULL)
		return (NULL);
	if (init_arg(table, philos, mutex, arg->philo_max) != 0)
		return (NULL);
	return (table);
}
