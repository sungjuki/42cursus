/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:46:12 by gulee             #+#    #+#             */
/*   Updated: 2022/08/28 23:57:18 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_print(char *str)
{
	printf("%s Error\n", str);
	return (TRUE_E);
}

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

t_bool	ft_isdigit(char num)
{
	if (num >= '0' && num <= '9')
		return (TRUE_E);
	return (FALSE_E);
}

ssize_t	ft_atoi(const char *str)
{
	size_t	result;
	ssize_t	negative;

	result = 0;
	negative = 1;
	while (*str != '\0' && (ft_isspace(*str)))
		str++;
	if (*str != '\0' && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * negative);
}

void	all_free(t_table *table, t_mutex *mutex, int philo_max)
{
	int	i;

	i = -1;
	pthread_mutex_unlock(&table->mutex->print_m);
	while (++i < philo_max)
		pthread_mutex_destroy(&mutex->fork_m[i]);
	pthread_mutex_destroy(&mutex->finish_m);
	pthread_mutex_destroy(&mutex->eat_m);
	pthread_mutex_destroy(&mutex->print_m);
	if (mutex->fork_m != NULL)
		free(mutex->fork_m);
	if (mutex != NULL)
		free(mutex);
	if (table->philos != NULL)
		free(table->philos);
	if (table->finish != NULL)
		free(table->finish);
	if (table != NULL)
		free(table);
}
