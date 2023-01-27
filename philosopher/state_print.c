/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:37:28 by sungjuki          #+#    #+#             */
/*   Updated: 2022/09/28 20:02:46 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state_print(t_state state, t_table *table, t_philo *philos, int i)
{
	pthread_mutex_lock(&table->mutex->print_m);
	if (state == DIED_E)
		printf("%lld ms    %d died\n",
			get_timediff(table->start), philos[i].philo_id);
	else if (state == FINISH_E)
		printf("philo finish!\n");
	if (state == FORK_E && is_finish(table) == TRUE_E)
		printf("%lld ms    %d has taken a fork\n",
			get_timediff(table->start), philos[i].philo_id);
	if (state == EAT_E && is_finish(table) == TRUE_E)
	{
		printf("%lld ms    %d is eating\n" \
		, get_timediff(table->start), philos[i].philo_id);
		gettimeofday(&philos[i].last_eat, NULL);
	}
	if (state == SLEEP_E && is_finish(table) == TRUE_E && \
		eat_check(table, table->philos[i].arg) != TRUE_E)
		printf("%lld ms    %d is sleeping\n",
			get_timediff(table->start), philos[i].philo_id);
	if (state == THINK_E && is_finish(table) == TRUE_E && \
		eat_check(table, table->philos[i].arg) != TRUE_E)
		printf("%lld ms    %d is thinking\n",
			get_timediff(table->start), philos[i].philo_id);
	pthread_mutex_unlock(&table->mutex->print_m);
}
