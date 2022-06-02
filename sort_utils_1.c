/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:53:54 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/17 22:19:00 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_sa(t_stack_info *stack)
{
	int	num0;
	int	num1;
	int	num2;

	num0 = *(*(int **) stack->sa_top->content);
	num1 = *(*(int **) stack->sa_top->next->content);
	num2 = *(*(int **) stack->sa_top->next->next->content);
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

void	ft_push_b(t_stack_info *stack, int sorted_index)
{
	int	proximity;
	int	reverse;

	reverse = 0;
	proximity = (stack->sa_size / 2) + (stack->sa_size % 2);
	if (proximity > ft_get_index(stack->sa_top, sorted_index))
		reverse = 1;
	while (*(*(int **) stack->sa_top->content + 1) != sorted_index && stack->sa)
	{
		if (reverse)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
	pb(stack, 1);
}

void	ft_push_a(t_stack_info *stack, int sorted_index)
{
	int	proximity;
	int	reverse;

	reverse = 0;
	proximity = (stack->sb_size / 2) + (stack->sb_size % 2);
	if (proximity > ft_get_index(stack->sb_top, sorted_index))
		reverse = 1;
	while (*(*(int **) stack->sb_top->content + 1) != sorted_index && stack->sb)
	{
		if (*(*(int **) stack->sb_top->next->content + 1) == sorted_index)
			sb(stack, 1);
		else
		{
			if (reverse)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
	pa(stack, 1);
}

int	ft_get_index(t_list *lst, int to_find)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (*(*(int **) lst->content + 1) == to_find)
			return (index);
		lst = lst->next;
		index++;
	}
	return (-1);
}
