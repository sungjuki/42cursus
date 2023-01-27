/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:04:03 by sungjuki          #+#    #+#             */
/*   Updated: 2022/06/09 22:26:57 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_str_size(int argc, char **argv)
{
	int		idx;
	int		size;
	int		checker;
	char	**split_str;

	idx = 0;
	size = 0;
	while (idx < argc)
	{
		checker = 0;
		while (argv[idx][checker])
		{
			if (!ft_isspace(argv[idx][checker]))
				break ;
			checker++;
		}
		if (argv[idx][checker] == '\0')
			print_error(1);
		split_str = ft_split(argv[idx], ' ');
		size += get_size_split_str(split_str);
		ft_free_str(split_str);
		idx++;
	}
	return (size - 1);
}

int	*ft_argv_to_arr(int argc, char **argv, int size)
{
	int		argc_idx;
	int		arr_idx;
	int		*new_arr;
	char	**split_str;

	argc_idx = 1;
	arr_idx = 0;
	new_arr = (int *)malloc(sizeof(int) * size);
	if (!new_arr)
		print_error(1);
	while (argc_idx < argc)
	{
		split_str = ft_split(argv[argc_idx], ' ');
		set_str_to_arr(new_arr, &arr_idx, split_str);
		ft_free_str(split_str);
		argc_idx++;
	}
	new_arr[arr_idx] = '\0';
	return (new_arr);
}

void	ft_arr_to_stack(t_info *info, int *arr, int size)
{
	t_num	*new_node;
	int		idx;

	idx = 0;
	while (idx < size)
	{
		new_node = ft_stack_new();
		info->size_a += 1;
		info->bot_a->content = (int)arr[idx];
		info->bot_a->next = new_node;
		new_node->prev = info->bot_a;
		info->bot_a = new_node;
		idx++;
	}
	info->bot_a = info->bot_a->prev;
	info->bot_a->next = NULL;
	free(new_node);
}

void	ft_check_arr_sort(int *arr, int size, int idx)
{
	int	i;
	int	checker;
	int	tmp;

	checker = 0;
	while (idx < size)
	{
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				checker++;
			}
			i++;
		}
		if (arr[idx] == arr[idx + 1])
			print_error(1);
		idx++;
	}
	if (checker == 0)
		print_error(-1);
}
