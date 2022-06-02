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

int	ft_push_less(t_stack_info *stack, int pivot, int median)
{
	int	index[2];

	if (ft_find_less_sa(stack, index, pivot) < 0)
		return (0);
	if (index[TOP] < index[LAST])
	{
		while (index[TOP]--)
			ra(stack, 1);
	}
	else
	{
		while (index[LAST]--)
			rra(stack, 1);
	}
	pb(stack, 1);
	if (*(*(int **) stack->sb_top->content + 1) <= median)
	{
		if (ft_find_less_sa(stack, index, pivot) < 0)
			return (0);
		if (index[TOP] > 0 && index[LAST] > 0)
			rr(stack, 1);
		else
			rb(stack, 1);
	}
	return (1);
}

int	ft_find_less_sa(t_stack_info *stack, int *index, int pivot)
{
	index[TOP] = ft_find_top_less(stack->sa_top, pivot);
	index[LAST] = ft_find_last_less(stack->sa_top, pivot);
	if (index[TOP] < 0 || index[LAST] < 0)
		return (-1);
	index[LAST] = stack->sa_size - index[LAST];
	return (1);
}

int	ft_find_top_less(t_list *lst, int pivot)
{
	int	top_index;
	int	index;

	top_index = -1;
	index = 0;
	while (lst && top_index == -1)
	{
		if (*(*(int **) lst->content + 1) < pivot)
			top_index = index;
		lst = lst->next;
		index++;
	}
	return (top_index);
}

int	ft_find_last_less(t_list *lst, int pivot)
{
	int	last_index;
	int	index;

	last_index = -1;
	index = 0;
	while (lst)
	{
		if (*(*(int **) lst->content + 1) < pivot)
			last_index = index;
		lst = lst->next;
		index++;
	}
	return (last_index);
}

void	ft_push_back(t_stack_info *stack)
{
	int	etc_i[2];
	int	max_i[2];

	if (stack->sa_last[0] == stack->array_sorted[stack->size - 1])
	{
		if (stack->sb_size > 1
			&& *(*(int **) stack->sb_top->content + 1)
			!= ft_find_max(stack->sb_top, stack->min_int))
		{
			pa(stack, 1);
			ra(stack, 1);
		}
		else
			pa(stack, 1);
	}
	etc_i[0] = ft_get_index(stack->sb_top, stack->sa_last[1] + 1);
	max_i[0] = ft_find_max_index_sb(stack);
	if (etc_i[0] < 0)
	{
		while (stack->sa_last[0] != stack->array_sorted[stack->size - 1])
			rra(stack, 1);
		return ;
	}
	ft_smart_rotate(stack, etc_i, max_i);
}
