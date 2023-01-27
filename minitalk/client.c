/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:17:09 by sungjuki          #+#    #+#             */
/*   Updated: 2022/06/23 14:35:22 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		write(1, "Invalid argc\n", 13);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 101 || pid > 99999)
	{
		write(1, "Invalid PID\n", 12);
		exit(1);
	}
	send_msg(pid, argv[2]);
}

void	send_msg(int pid, char *str)
{
	int	len;
	int	byte_idx;
	int	bit_idx;
	int	bit_tmp;

	len = ft_strlen(str);
	byte_idx = 0;
	while (byte_idx < len)
	{
		bit_idx = 0;
		while (bit_idx < 8)
		{
			bit_tmp = str[byte_idx] >> (7 - bit_idx) & 1;
			if (bit_tmp == 0)
				kill_and_pause(pid, SIGUSR1);
			else if (bit_tmp == 1)
				kill_and_pause(pid, SIGUSR2);
			bit_idx++;
		}
		usleep(420);
		byte_idx++;
	}
	line_break(pid);
	exit(0);
}

void	kill_and_pause(pid_t pid, int signo)
{
	kill(pid, signo);
	usleep(42);
}

void	line_break(pid_t pid)
{
	int		bit_idx;
	int		bit_tmp;
	char	nl;

	nl = '\n';
	bit_idx = 0;
	while (bit_idx < 8)
	{
		bit_tmp = nl >> (7 - bit_idx) & 1;
		if (bit_tmp == 0)
			kill_and_pause(pid, SIGUSR1);
		else if (bit_tmp == 1)
			kill_and_pause(pid, SIGUSR2);
		bit_idx++;
	}
	exit(0);
}
