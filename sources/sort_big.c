/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:16:53 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/14 22:17:33 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_big(t_stack_info *stack, int part)
{
	int	*pivot_index;
	int	median;
	int	i;

	pivot_index = ft_get_pivot(stack->sa_size, part);
	i = -1;
	while (++i < part - 1)
	{
		median = pivot_index[0] * i + pivot_index[0] * 3 / 10;
		while (ft_push_less(stack, pivot_index[i], median))
			continue ;
	}
	while (stack->sa_size > 3)
		ft_push_b(stack, ft_find_min(stack->sa_top, stack->max_int));
	sort_three_sa(stack);
	while (stack->sb_size > pivot_index[part - 2])
		pa(stack, 1);
	while (stack->sb_size > 0)
		ft_push_back(stack);
	ft_push_back(stack);
	free(pivot_index);
}
