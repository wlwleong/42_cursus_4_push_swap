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

void	sort_medium(t_stack_info *stack)
{
	int	push_i;
	int	size;
	int	i;

	size = stack->sa_size;
	i = 1;
	while (i < 4)
	{
		stack->sa = stack->sa_top;
		while (stack->sa)
		{
			if (*(*(int **) stack->sa->content + 1) < size / 4 * i)
				ft_push_b(stack, *(*(int **) stack->sa->content + 1));
			stack->sa = stack->sa->next;
		}
		i++;
	}
	push_i = ft_find_min(stack->sa, stack->sa_top, stack->array_sorted[size - 1]);
	while (stack->sa_size > 0)
		ft_push_b(stack, push_i++);
	while (stack->sb_size > size - size / 4)
		pa(stack);
	push_i = ft_find_max(stack->sb, stack->sb_top, stack->array_sorted[0]);
	while (stack->sb_size > 0)
		ft_push_a(stack, push_i--);
}

int	ft_find_min(t_list *lst, t_list *lst_top, int stack_max)
{
	int	min;
	int	return_index;

	min = stack_max;
	return_index = 0;
	lst = lst_top;
	while (lst)
	{
		if (*(*(int **) lst->content) < min)
		{
			min = *(*(int **) lst->content + 0);
			return_index = *(*(int **) lst->content + 1);
		}
		lst = lst->next;
	}
	return (return_index);
}

int	ft_find_max(t_list *lst, t_list *lst_top, int stack_min)
{
	int	max;
	int	return_index;

	max = stack_min;
	return_index = 0;
	lst = lst_top;
	while (lst)
	{
		if (*(*(int **) lst->content) > max)
		{
			max = *(*(int **) lst->content + 0);
			return_index = *(*(int **) lst->content + 1);
		}
		lst = lst->next;
	}
	return (return_index);
}

void	ft_push_a(t_stack_info *stack, int sorted_index)
{
	int	proximity;
	int	reverse;

	reverse = 0;
	proximity = (stack->sb_size / 2) + (stack->sb_size % 2);
	if (proximity > ft_get_index(stack->sb, stack->sb_top, sorted_index))
		reverse = 1;
	stack->sb = stack->sb_top;
	while (*(*(int **) stack->sb->content + 1) != sorted_index && stack->sb)
	{
		if (reverse)
			rb(stack, 1);
		else
			rrb(stack, 1);
	}
	pa(stack);
}
