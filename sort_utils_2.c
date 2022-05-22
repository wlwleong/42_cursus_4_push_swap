/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:18:19 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/18 00:10:59 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_pivot(int stack_size, int part)
{
	int	*pivot;
	int	i;

	pivot = malloc (sizeof(int) * part);
	if (!pivot)
	{
		ft_putstr_fd("pivot malloc Error!\n", 1);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < part - 1)
	{
		pivot[i] = stack_size / part * (i + 1);
		i++;
	}
	pivot[i] = stack_size;
	return (pivot);
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

void	ft_push_sort(t_stack_info *stack)
{
	int	min_i[2];
	int	max_i[2];

	while (stack->sb_size > 1)
	{
		min_i[0] = ft_find_min_index(stack->sb, stack->sb_top, stack->max_int);
		max_i[0] = ft_find_max_index(stack->sb, stack->sb_top, stack->min_int);
		if (min_i[0] < stack->sb_size - min_i[0])
			min_i[1] = min_i[0];
		else
			min_i[1] = stack->sb_size - min_i[0];
		if (max_i[0] < stack->sb_size - max_i[0])
			max_i[1] = max_i[0];
		else
			max_i[1] = stack->sb_size - max_i[0];
		if (min_i[1] < max_i[1])
			ft_rb_rrb_pa(stack, min_i[0], 1);
		else
		{
			ft_rb_rrb_pa(stack, max_i[0], 0);
			stack->n_top_sorted++;
		}
	}
	pa(stack);
	stack->n_top_sorted++;
}

void	ft_rb_rrb_pa(t_stack_info *stack, int index, int rotate)
{
	int	center;

	center = stack->sb_size / 2 + stack->sb_size % 2;
	if (index < center)
	{
		while (index--)
			rb(stack, 1);
	}
	else
	{
		index = stack->sb_size - index;
		while (index--)
			rrb(stack, 1);
	}
	pa(stack);
	if (rotate)
		ra(stack, 1);
}

void	ft_push_rest(t_stack_info *stack, int pivot)
{
	while (*(*(int **) stack->sa_top->content + 0) != stack->array_sorted[0])
	{
		if (*(*(int **) stack->sa_top->content + 1)
			== *(*(int **) ft_lstlast(stack->sa)->content + 1) + 1)
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
