/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjuki <sungjuki@student.42seoul.k       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:44:17 by sungjuki          #+#    #+#             */
/*   Updated: 2022/06/09 21:45:33 by sungjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3div(t_info *info)
{
	int	idx;
	int	pv1;
	int	pv2;

	idx = info->size_a / 3;
	pv1 = info->arr[idx];
	idx = info->size_a * 2 / 3;
	pv2 = info->arr[idx];
	idx = info->size_a;
	while (idx)
	{
		ft_sort_3div_instruct(info, pv1, pv2);
		idx--;
	}
}

void	ft_sort_3div_instruct(t_info *info, int pv1, int pv2)
{
	if (info->top_a->content < pv1)
	{
		pb(info);
		rb(info);
	}
	else if (info->top_a->content < pv2)
		pb(info);
	else
		ra(info);
}

void	get_min_rotate(t_info *info, int *a, int *b)
{
	int		a_location;
	int		b_location;
	int		idx;
	t_num	*stack_b;
	int		num;

	idx = 0;
	stack_b = info->top_b;
	while (idx < info->size_b)
	{
		num = stack_b->content;
		a_location = set_a_location(num, info);
		if (idx >= (info->size_b + 1) / 2)
			b_location = (info->size_b - idx) * -1;
		else
			b_location = idx;
		if (idx == 0 || ft_get_faster(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		stack_b = stack_b->next;
		idx++;
	}
}

int	ft_get_faster(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a = a * -1;
	if (b < 0)
		b = b * -1;
	if (a_loc < 0)
		a_loc = a_loc * -1;
	if (b_loc < 0)
		b_loc = b_loc * -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
}

void	ft_sort_last(t_info *info)
{
	int	min;
	int	min_location;

	min = get_stack_min(info->top_a);
	min_location = set_a_location_min(info);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(info);
			min_location--;
		}
		else
		{
			rra(info);
			min_location++;
		}
	}
}
