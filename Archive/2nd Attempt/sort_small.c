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
		pa(stack);
}

int	ft_get_index(t_list *lst, t_list *lst_top, int sorted_index)
{
	int	index;

	lst = lst_top;
	index = 0;
	while (*(*(int **) lst->content + 1) != sorted_index && lst)
	{
		lst = lst->next;
		index++;
	}
	return (index);
}
