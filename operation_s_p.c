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

#include "push_swap.h"

void	sa(t_stack_info *stack, int display)
{
	int		*temp;

	if (ft_lstsize(stack->sa) < 2)
		return ;
	temp = stack->sa_top->content;
	stack->sa_top->content = stack->sa_top->next->content;
	stack->sa_top->next->content = temp;
	if (display)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_info *stack, int display)
{
	int		*temp;

	if (ft_lstsize(stack->sb) < 2)
		return ;
	temp = stack->sb_top->content;
	stack->sb_top->content = stack->sb_top->next->content;
	stack->sb_top->next->content = temp;
	if (display)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_info *stack)
{
	sa(stack, 0);
	sb(stack, 0);
	ft_putstr_fd("ss\n", 1);
}
