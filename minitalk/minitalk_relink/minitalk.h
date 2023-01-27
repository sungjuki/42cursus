/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:59:29 by sungjuki          #+#    #+#             */
/*   Updated: 2022/06/22 12:48:08 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

/*
 *		minitalk sever
 *		server_get_bytes : func to receive bits(len & str)
 */
void	sig_handler(int sig);

/*
 * 		minitalk client
 * 		client_send_bytes : func to send bits(len & str)
 * 		kill_and_pause : func to connect & init
 * 		line_break : make nl
 */
void	send_msg(int pid, char *str);
void	kill_and_pause(pid_t pid, int signo);
void	line_break(pid_t pid);
#endif
