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
	if (num0 > num1 && num0 < num2)
		sa(stack, 1);
	else if (num0 > num1 && num1 > num2)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (num0 > num1 && num1 < num2)
		ra(stack, 1);
	else if (num0 < num1 && num0 < num2)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (num0 < num1 && num0 > num2)
		rra(stack, 1);
	else
		return ;
}
