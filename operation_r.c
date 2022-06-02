/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:48:37 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/08 01:33:06 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Shift up all elements of stack a by 1.
The first element becomes the last one.
*/
void	ra(t_stack_info *stack, int display)
{
	t_list	*last;
	t_list	*temp;

	if (ft_lstsize(stack->sa) < 2)
		return ;
	temp = stack->sa_top;
	stack->sa_top = stack->sa->next;
	last = ft_lstlast(stack->sa);
	last->next = temp;
	last->next->next = NULL;
	stack->sa = stack->sa_top;
	stack->sa_last = *(int **) ft_lstlast(stack->sa_top)->content;
	if (display)
	{
		stack->n_operations++;
		ft_putstr_fd("ra\n", 1);
	}
}

/*
Shift up all elements of stack b by 1.
The first element becomes the last one.
*/
void	rb(t_stack_info *stack, int display)
{
	t_list	*last;
	t_list	*temp;

	if (ft_lstsize(stack->sb) < 2)
		return ;
	temp = stack->sb_top;
	stack->sb_top = stack->sb->next;
	last = ft_lstlast(stack->sb);
	last->next = temp;
	last->next->next = NULL;
	stack->sb = stack->sb_top;
	stack->sb_last = *(int **) ft_lstlast(stack->sb_top)->content;
	if (display)
	{
		stack->n_operations++;
		ft_putstr_fd("rb\n", 1);
	}
}

/*
ra and rb at the same time.
*/
void	rr(t_stack_info *stack, int display)
{
	ra(stack, 0);
	rb(stack, 0);
	stack->n_operations++;
	if (display)
		ft_putstr_fd("rr\n", 1);
}
