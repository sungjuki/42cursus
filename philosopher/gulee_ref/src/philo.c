/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:45:48 by gulee             #+#    #+#             */
/*   Updated: 2022/08/28 22:57:01 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_arg	*arg;

	if (check_arg(argc, argv) == FALSE_E)
		return (error_print("Argument"));
	arg = arg_save(argc, argv);
	start(arg);
	if (arg != NULL)
		free(arg);
	return (0);
}
