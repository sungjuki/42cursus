/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:35:40 by sungjuki          #+#    #+#             */
/*   Updated: 2022/06/09 22:08:59 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		arr_size;
	int		*num_arr;
	t_info	*info;

	if (argc < 2)
	{
		print_error(-1);
	}
	arr_size = 0;
	info = ft_info_new();
	arr_size = get_str_size(argc, argv);
	num_arr = ft_argv_to_arr(argc, argv, arr_size);
	ft_arr_to_stack(info, num_arr, arr_size);
	ft_check_arr_sort(num_arr, arr_size, 0);
	info->arr = (int *)num_arr;
	ft_sort(info);
	return (0);
}

int	print_error(int type)
{
	if (type >= 1)
		write(2, "Error\n", 6);
	exit (1);
}

t_info	*ft_info_new(void)
{
	t_num		*stack_a;
	t_info		*new_mem;

	new_mem = NULL;
	new_mem = (t_info *)malloc(sizeof(t_info));
	if (new_mem == NULL)
		print_error(1);
	stack_a = ft_stack_new();
	new_mem->arr = NULL;
	new_mem->size_a = 0;
	new_mem->top_a = stack_a;
	new_mem->bot_a = stack_a;
	new_mem->size_b = 0;
	return (new_mem);
}

t_num	*ft_stack_new(void)
{
	t_num	*new_mem;

	new_mem = NULL;
	new_mem = (t_num *)malloc(sizeof(t_num));
	if (new_mem == NULL)
		print_error(1);
	new_mem->prev = NULL;
	new_mem->content = 0;
	new_mem->next = NULL;
	return (new_mem);
}
