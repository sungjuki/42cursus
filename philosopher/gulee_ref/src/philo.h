/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:27:14 by gulee             #+#    #+#             */
/*   Updated: 2022/08/28 23:06:50 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_bool
{
	FALSE_E,
	TRUE_E
}	t_bool;

typedef enum e_state
{
	FORK_E,
	EAT_E,
	SLEEP_E,
	THINK_E,
	DIED_E,
	FINISH_E
}	t_state;

typedef struct timeval	t_timeval;

typedef struct s_mutex
{
	pthread_mutex_t	*fork_m;
	pthread_mutex_t	print_m;
	pthread_mutex_t	finish_m;
	pthread_mutex_t	eat_m;
}				t_mutex;

typedef struct s_arg
{
	int			philo_max;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	int			must_eat_count;
}				t_arg;

typedef struct s_philo
{
	t_arg		*arg;
	pthread_t	thread_id;
	int			philo_id;
	t_timeval	last_eat;
	int			eat_count;
	int			fork_l;
	int			fork_r;
}				t_philo;

typedef struct s_table
{
	int			i;
	t_mutex		*mutex;
	t_bool		*finish;
	t_philo		*philos;
	t_timeval	start;
}				t_table;

/* ================================================
				  validation
================================================ */
t_bool	check_arg(int argc, char **argv);

/* ================================================
					utils
================================================ */
ssize_t	ft_atoi(const char *str);
t_bool	ft_isdigit(char num);
int		error_print(char *str);
void	all_free(t_table *table, t_mutex *mutex, int philo_max);

/* ================================================
					arg_save
================================================ */
t_arg	*arg_save(int argc, char **argv);

/* ================================================
					create
================================================ */
t_table	*create_arg(t_arg *arg);

/* ================================================
					check
================================================ */
t_bool	exit_check(t_table *table, t_arg *arg, t_philo *philos);
t_bool	eat_check(t_table *table, t_arg *arg);
t_bool	is_finish(t_table *table);

/* ================================================
					start
================================================ */
int		start(t_arg *arg);
int		start_thread(t_table *table, int philo_max);
void	*routine(void *arg);

/* ================================================
					time
================================================ */
int		philo_pause(long int usec, t_table *table);
long	get_timediff(t_timeval begin);

/* ================================================
					print
================================================ */
void	state_print(t_state status, t_table *table, t_philo *philos, int i);

#endif
