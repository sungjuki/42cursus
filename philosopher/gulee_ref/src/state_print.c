/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:45:53 by gulee             #+#    #+#             */
/*   Updated: 2022/08/29 00:17:57 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state_print(t_state state, t_table *table, t_philo *philos, int i)
{
	pthread_mutex_lock(&table->mutex->print_m);
	if (state == DIED_E)
		printf("\033[0m%7ld ms    %-3d \033[0;31mdied\n",
			get_timediff(table->start), philos[i].philo_id);
	else if (state == FINISH_E)
		printf("\033[0;31mGod damn philo finish!!!!!!!!!!!!\n");
	if (state == FORK_E && is_finish(table) == TRUE_E)
		printf("\033[0m%7ld ms    %-3d \033[0;33mhas taken a fork\n",
			get_timediff(table->start), philos[i].philo_id);
	if (state == EAT_E && is_finish(table) == TRUE_E)
	{
		printf("\033[0m%7ld ms    %-3d \033[0;32mis eating eat_count: %-3d\n" \
		, get_timediff(table->start), philos[i].philo_id, \
		philos[i].eat_count + 1);
		gettimeofday(&philos[i].last_eat, NULL);
	}
	if (state == SLEEP_E && is_finish(table) == TRUE_E && \
		eat_check(table, table->philos[i].arg) != TRUE_E)
		printf("\033[0m%7ld ms    %-3d \033[0;34mis sleeping\n",
			get_timediff(table->start), philos[i].philo_id);
	if (state == THINK_E && is_finish(table) == TRUE_E && \
		eat_check(table, table->philos[i].arg) != TRUE_E)
		printf("\033[0m%7ld ms    %-3d \033[0;35mis thinking\n",
			get_timediff(table->start), philos[i].philo_id);
	pthread_mutex_unlock(&table->mutex->print_m);
}
