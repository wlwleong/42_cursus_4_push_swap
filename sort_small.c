/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 16:29:41 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/08 16:56:56 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_info *stack)
{
	int	num0;
	int	num1;
	int	num2;

	num0 = *(int *) stack->sa_top->content;
	num1 = *(int *) stack->sa_top->next->content;
	num2 = *(int *) stack->sa_top->next->next->content;
	if (num0 > num1 && num1 < num2 && num0 < num2)
		sa(stack, 1);
	else if (num0 > num1 && num1 > num2 && num0 > num2)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (num0 > num1 && num1 < num2 && num0 > num2)
		ra(stack, 1);
	else if (num0 < num1 && num1 > num2 && num0 < num2)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (num0 < num1 && num1 > num2 && num0 > num2)
		rra(stack, 1);
	else
		return ;
}

void	sort_small(t_stack_info *stack)
{
	while (stack->sa_size > 3)
		ft_pb_smallest(stack, ft_get_smallest(stack->sa, stack->sa_top));
	sort_three(stack);
	while (stack->sb_size > 0)
		pa(stack);
}

int	ft_get_smallest(t_list *lst, t_list *lst_top)
{
	int	smallest;

	smallest = INT_MAX;
	lst = lst_top;
	while (lst)
	{
		if (*(int *) lst->content < smallest)
			smallest = *(int *) lst->content;
		lst = lst->next;
	}
	return (smallest);
}

int	ft_get_index(t_list *lst, t_list *lst_top, int num)
{
	int	index;

	lst = lst_top;
	index = 1;
	while (*(int *) lst->content != num && lst)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}

void	ft_pb_smallest(t_stack_info *stack, int num)
{
	int	proximity;
	int	reverse;

	reverse = 0;
	proximity = (stack->sa_size / 2) + (stack->sa_size % 2);
	if (proximity > ft_get_index(stack->sa, stack->sa_top, num))
		reverse = 1;
	stack->sa = stack->sa_top;
	while (*(int *) stack->sa->content != num && stack->sa)
	{
		if (reverse)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
	pb(stack);
}
