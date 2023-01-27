/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:56:22 by sungjuki          #+#    #+#             */
/*   Updated: 2022/09/28 21:14:52 by sungjuki         ###   ########.fr       */
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
