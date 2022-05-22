/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:16:53 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/14 22:17:33 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack_info *stack, int part)
{
	int	*pivot_index;
	int	median;
	int	i;

	pivot_index = ft_get_pivot(stack->sa_size, part);
	i = -1;
	while (++i < part - 1)
	{
		median = pivot_index[0] * i + pivot_index[0] * 3 / 10;
		while (ft_push_less(stack, pivot_index[i], median))
			continue ;
	}
	while (stack->sa_size > 3)
		ft_push_b(stack, ft_find_min(stack->sa_top, stack->max_int));
	sort_three_sa(stack);
	while (stack->sb_size > pivot_index[part - 2])
		pa(stack);
	i = -1;
	while (stack->sb_size > 0)
		ft_push_back(stack);
	ft_push_back(stack);
	free(pivot_index);
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
			pa(stack);
			ra(stack, 1);
		}
		else
			pa(stack);
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

int	ft_find_min(t_list *lst, int stack_max)
{
	int	min;
	int	return_index;

	min = stack_max;
	return_index = -1;
	while (lst)
	{
		if (*(*(int **) lst->content + 0) < min)
		{
			min = *(*(int **) lst->content + 0);
			return_index = *(*(int **) lst->content + 1);
		}
		lst = lst->next;
	}
	return (return_index);
}

int	ft_find_max(t_list *lst, int stack_min)
{
	int	max;
	int	return_index;

	max = stack_min;
	return_index = -1;
	while (lst)
	{
		if (*(*(int **) lst->content + 0) > max)
		{
			max = *(*(int **) lst->content + 0);
			return_index = *(*(int **) lst->content + 1);
		}
		lst = lst->next;
	}
	return (return_index);
}
