/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:44:25 by wlwleong          #+#    #+#             */
/*   Updated: 2022/06/02 21:44:30 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_median(t_stack_info *stack, int *pivot)
{
	int	end;
	int	i;

	end = stack->sa_size;
	i = -1;
	while (++i < end)
	{
		if (*(*(int **) stack->sa_top->content + 1) < pivot[1])
		{
			pb(stack, 1);
			if (*(*(int **) stack->sb_top->content + 1) < pivot[0]
				&& (*(*(int **) stack->sa_top->content + 1) > pivot[1]))
			{
				rr(stack, 1);
				i++;
			}
			else if (stack->sb_size > 1
				&& *(*(int **) stack->sb_top->content + 1) <= 10)
				rb(stack, 1);
		}
		else
			ra(stack, 1);
	}
}

void	ft_push_sort(t_stack_info *stack)
{
	int	min_i[2];
	int	max_i[2];

	while (stack->sb_size > 1)
	{
		min_i[0] = ft_find_min_index_sb(stack);
		max_i[0] = ft_find_max_index_sb(stack);
		if (ft_smart_rotate(stack, min_i, max_i))
			stack->n_top_sorted++;
	}
	pa(stack, 1);
	stack->n_top_sorted++;
}

int	ft_find_min_index_sb(t_stack_info *stack)
{
	int	min;

	min = ft_find_min(stack->sb_top, stack->max_int);
	return (ft_get_index(stack->sb_top, min));
}

int	ft_find_max_index_sb(t_stack_info *stack)
{
	int	max;

	max = ft_find_max(stack->sb_top, stack->min_int);
	return (ft_get_index(stack->sb_top, max));
}

void	ft_push_rest(t_stack_info *stack, int pivot)
{
	while (*(*(int **) stack->sa_top->content + 0) != stack->array_sorted[0])
	{
		if (*(*(int **) stack->sa_top->content + 1) == stack->sa_last[1] + 1)
			ra(stack, 1);
		else
		{
			pb(stack, 1);
			if (stack->sb_size > 1)
			{
				if (*(*(int **) stack->sb_top->content + 1) <= pivot + 10)
					rb(stack, 1);
			}
		}
	}
}
