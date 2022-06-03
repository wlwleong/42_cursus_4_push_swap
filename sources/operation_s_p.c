/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_s_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:07:43 by wlwleong          #+#    #+#             */
/*   Updated: 2022/04/30 21:08:35 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
*/
void	sa(t_stack_info *stack, int display)
{
	int	*temp;

	if (ft_lstsize(stack->sa) < 2)
		return ;
	temp = stack->sa_top->content;
	stack->sa_top->content = stack->sa_top->next->content;
	stack->sa_top->next->content = temp;
	stack->sa_last = *(int **) ft_lstlast(stack->sa_top)->content;
	if (display)
	{
		stack->n_operations++;
		ft_putstr_fd("sa\n", 1);
	}
}

/*
Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
*/
void	sb(t_stack_info *stack, int display)
{
	int	*temp;

	if (ft_lstsize(stack->sb) < 2)
		return ;
	temp = stack->sb_top->content;
	stack->sb_top->content = stack->sb_top->next->content;
	stack->sb_top->next->content = temp;
	stack->sb_last = *(int **) ft_lstlast(stack->sb_top)->content;
	if (display)
	{
		stack->n_operations++;
		ft_putstr_fd("sb\n", 1);
	}
}

/*
sa and sb at the same time.
*/
void	ss(t_stack_info *stack, int display)
{
	sa(stack, 0);
	sb(stack, 0);
	stack->n_operations++;
	if (display)
		ft_putstr_fd("ss\n", 1);
}

/*
Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
*/
void	pa(t_stack_info *stack, int display)
{
	t_list	*list;
	t_list	*temp;

	if (!stack->sb_top)
		return ;
	list = stack->sb_top;
	temp = stack->sb_top->next;
	ft_lstadd_front(&stack->sa, list);
	stack->sa_top = stack->sa;
	stack->sb = temp;
	stack->sb_top = stack->sb;
	stack->sa_size = ft_lstsize(stack->sa);
	stack->sb_size = ft_lstsize(stack->sb);
	stack->sa_last = *(int **) ft_lstlast(stack->sa_top)->content;
	stack->n_operations++;
	if (display)
		ft_putstr_fd("pa\n", 1);
}

/*
Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/
void	pb(t_stack_info *stack, int display)
{
	t_list	*list;
	t_list	*temp;

	if (!stack->sa_top)
		return ;
	list = stack->sa_top;
	temp = stack->sa_top->next;
	ft_lstadd_front(&stack->sb, list);
	stack->sb_top = stack->sb;
	stack->sa = temp;
	stack->sa_top = stack->sa;
	stack->sa_size = ft_lstsize(stack->sa);
	stack->sb_size = ft_lstsize(stack->sb);
	stack->sb_last = *(int **) ft_lstlast(stack->sb_top)->content;
	stack->n_operations++;
	if (display)
		ft_putstr_fd("pb\n", 1);
}
