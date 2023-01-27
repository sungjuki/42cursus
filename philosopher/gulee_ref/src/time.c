/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:46:07 by gulee             #+#    #+#             */
/*   Updated: 2022/08/28 23:04:22 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	t_timeval	tmp;

	gettimeofday(&tmp, NULL);
	return (tmp.tv_sec * 1000 + tmp.tv_usec / 1000);
}

int	philo_pause(long int ms, t_table *table)
{
	long int	curr;
	long int	end;

	curr = get_time();
	end = curr + ms;
	while (get_time() < end && is_finish(table) == TRUE_E)
		usleep(100);
	return (0);
}

long	get_timediff(t_timeval begin)
{
	long		start;
	long		end;
	t_timeval	current;

	start = begin.tv_sec * 1000 + begin.tv_usec / 1000;
	gettimeofday(&current, NULL);
	end = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (end - start);
}
