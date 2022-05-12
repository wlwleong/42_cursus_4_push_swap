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
	stack->sa = stack->sa_top;
	if (*(int *) stack->sa_top->content == stack->smallest_int)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (*(int *) stack->sa_top->content == stack->largest_int)
	{
		if (*(int *) stack->sa->next->content == stack->smallest_int)
			ra(stack, 1);
		else
		{
			sa(stack, 1);
			rra(stack, 1);
		}
	}
	else
	{
		if (*(int *) stack->sa->next->content == stack->smallest_int)
			sa(stack, 1);
		else
			rra(stack, 1);
	}
}
