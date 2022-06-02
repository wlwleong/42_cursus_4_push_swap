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

void	sort_small(t_stack_info *stack)
{
	int	push_index;

	push_index = 0;
	while (stack->sa_size > 3)
		ft_push_b(stack, push_index++);
	sort_three_sa(stack);
	while (stack->sb_size > 0)
		pa(stack, 1);
}
