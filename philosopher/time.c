/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:56:58 by sungjuki          #+#    #+#             */
/*   Updated: 2022/09/28 20:04:42 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	t_timeval	tmp;

	gettimeofday(&tmp, NULL);
	return (tmp.tv_sec * 1000 + tmp.tv_usec / 1000);
}

long long	philo_pause(long int ms, t_table *table)
{
	long long	curr;
	long long	end;

	curr = get_time();
	end = curr + ms;
	while (get_time() < end && is_finish(table) == TRUE_E)
		usleep(100);
	return (0);
}

long long	get_timediff(t_timeval begin)
{
	long long	start;
	long long	end;
	t_timeval	current;

	start = begin.tv_sec * 1000 + begin.tv_usec / 1000;
	gettimeofday(&current, NULL);
	end = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (end - start);
}
