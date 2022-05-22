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
	int	top_i;
	int	last_i;

	top_i = ft_find_top_less(stack->sa_top, pivot);
	last_i = ft_find_last_less(stack->sa_top, pivot);
	if (top_i < 0 || last_i < 0)
		return (0);
	if (top_i < (stack->sa_size - last_i))
	{
		while (top_i--)
			ra(stack, 1);
	}
	else
	{
		last_i = stack->sa_size - last_i;
		while (last_i--)
			rra(stack, 1);
	}
	pb(stack);
	if (*(*(int **) stack->sb_top->content + 1) <= median)
		rb(stack, 1);
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

int	ft_smart_rotate(t_stack_info *stack, int *index1, int *index2)
{
	if (index1[0] < stack->sb_size - index1[0])
		index1[1] = index1[0];
	else
		index1[1] = stack->sb_size - index1[0];
	if (index2[0] < stack->sb_size - index2[0])
		index2[1] = index2[0];
	else
		index2[1] = stack->sb_size - index2[0];
	if (index1[1] < index2[1])
		ft_rb_rrb_pa(stack, index1[0], 1);
	else
	{
		ft_rb_rrb_pa(stack, index2[0], 0);
		return (1);
	}
	return (0);
}
