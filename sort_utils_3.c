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

int	ft_push_less(t_stack_info *stack, int pivot)
{
	int	top_i;
	int	last_i;

	top_i = ft_find_top_less(stack->sa, stack->sa_top, pivot);
	last_i = ft_find_last_less(stack->sa, stack->sa_top, pivot);
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
	return (1);
}

int	ft_find_top_less(t_list *lst, t_list *lst_top, int pivot)
{
	int	top_index;
	int	index;

	top_index = -1;
	index = 0;
	lst = lst_top;
	while (lst && top_index == -1)
	{
		if (*(*(int **) lst->content + 1) < pivot)
			top_index = index;
		lst = lst->next;
		index++;
	}
	return (top_index);
}

int	ft_find_last_less(t_list *lst, t_list *lst_top, int pivot)
{
	int	last_index;
	int	index;

	last_index = -1;
	index = 0;
	lst = lst_top;
	while (lst)
	{
		if (*(*(int **) lst->content + 1) < pivot)
			last_index = index;
		lst = lst->next;
		index++;
	}
	return (last_index);
}
