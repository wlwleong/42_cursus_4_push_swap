/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:16:53 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/21 23:20:29 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_stack_info *stack)
{
	int	*pivot_index;

	pivot_index = ft_get_pivot(stack->sa_size, 4);
	ft_push_median(stack, pivot_index);
	ft_push_sort(stack);
	while (stack->n_top_sorted--)
		ra(stack, 1);
	while (*(*(int **) stack->sa_top->content + 0) != stack->array_sorted[0])
	{
		if (*(*(int **) stack->sa_top->content + 1)
			== *(*(int **) ft_lstlast(stack->sa)->content + 1) + 1)
			ra(stack, 1);
		else
		{
			pb(stack);
			if (*(*(int **) stack->sb_top->content + 1) < pivot_index[2])
				rb(stack, 1);
		}
	}
	ft_push_sort(stack);
	while (*(*(int **) stack->sa_top->content + 0) != stack->array_sorted[0])
		ra(stack, 1);
	free(pivot_index);
}

int	*ft_get_pivot(int stack_size, int part)
{
	int	*pivot;
	int	i;

	pivot = malloc (sizeof(int) * part);
	if (!pivot)
	{
		ft_putstr_fd("pivot malloc Error!\n", 1);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < part - 1)
	{
		pivot[i] = stack_size / part * (i + 1);
		i++;
	}
	pivot[i] = stack_size;
	return (pivot);
}
