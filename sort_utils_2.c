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
	int	bottom_i;
	int	i;

	top_i = ft_find_top(stack->sa, stack->sa_top, pivot);
	bottom_i = ft_find_bottom(stack->sa, stack->sa_top, pivot);
	if (top_i < 0 || bottom_i < 0)
		return (0);
	if (top_i < (stack->sa_size - bottom_i))
	{
		i = 0;
		while (i++ < top_i)
			ra(stack, 1);
	}
	else
	{
		i = 0;
		while (i++ < (stack->sa_size - bottom_i))
			rra(stack, 1);
	}
	pb(stack);
	return (1);
}

int	ft_find_top(t_list *lst, t_list *lst_top, int pivot)
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
	return (index - 1);
}

int	ft_find_bottom(t_list *lst, t_list *lst_top, int pivot)
{
	int	bottom_index;
	int	index;

	bottom_index = -1;
	index = 0;
	lst = lst_top;
	while (lst)
	{
		if (*(*(int **) lst->content + 1) < pivot)
			bottom_index = index;
		lst = lst->next;
		index++;
	}
	return (bottom_index);
}
