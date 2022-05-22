/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:48:37 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/08 01:57:32 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Shift down all elements of stack a by 1.
The last element becomes the first one.
*/
void	rra(t_stack_info *stack, int display)
{
	t_list	*last;
	t_list	*second_last;

	if (ft_lstsize(stack->sa) < 2)
		return ;
	last = ft_lstlast(stack->sa);
	second_last = NULL;
	while (ft_lstsize(stack->sa) - 1)
	{
		second_last = stack->sa;
		stack->sa = stack->sa->next;
	}
	second_last->next = NULL;
	last->next = stack->sa_top;
	stack->sa_top = last;
	if (display)
		ft_putstr_fd("rra\n", 1);
}

/*
Shift down all elements of stack b by 1.
The last element becomes the first one.
*/
void	rrb(t_stack_info *stack, int display)
{
	t_list	*last;
	t_list	*second_last;

	if (ft_lstsize(stack->sb) < 2)
		return ;
	last = ft_lstlast(stack->sb);
	second_last = NULL;
	while (ft_lstsize(stack->sb) - 1)
	{
		second_last = stack->sb;
		stack->sb = stack->sb->next;
	}
	second_last->next = NULL;
	last->next = stack->sb_top;
	stack->sb_top = last;
	if (display)
		ft_putstr_fd("rrb\n", 1);
}

/*
rra and rrb at the same time.
*/
void	rrr(t_stack_info *stack)
{
	rra(stack, 0);
	rrb(stack, 0);
	ft_putstr_fd("rrr\n", 1);
}
