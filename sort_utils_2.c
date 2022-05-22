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
