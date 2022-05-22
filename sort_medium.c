/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:16:53 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/21 23:20:29 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_stack_info *stack)
{
	int	*pivot_index;

	pivot_index = ft_get_pivot(stack->sa_size, 4);
	ft_push_median(stack, pivot_index);
	ft_push_sort(stack);
	while (stack->n_top_sorted--)
		ra(stack, 1);
	ft_push_rest(stack, pivot_index[1]);
	ft_push_sort(stack);
	while (*(*(int **) stack->sa_top->content + 0) != stack->array_sorted[0])
		ra(stack, 1);
	free(pivot_index);
}

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
			pb(stack);
			if (*(*(int **) stack->sb_top->content + 1) < pivot[0]
				&& (*(*(int **) stack->sa_top->content + 1) > pivot[1]))
			{
				rr(stack);
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

void	ft_push_rest(t_stack_info *stack, int pivot)
{
	while (*(*(int **) stack->sa_top->content + 0) != stack->array_sorted[0])
	{
		if (*(*(int **) stack->sa_top->content + 1) == stack->sa_last[1] + 1)
			ra(stack, 1);
		else
		{
			pb(stack);
			if (stack->sb_size > 1)
			{
				if (*(*(int **) stack->sb_top->content + 1) <= pivot + 10)
					rb(stack, 1);
			}
		}
	}
}
