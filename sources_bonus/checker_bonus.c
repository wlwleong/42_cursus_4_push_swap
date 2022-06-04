/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:32:09 by wlwleong          #+#    #+#             */
/*   Updated: 2022/04/26 20:33:23 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	init_stack(t_stack_info *stack);
// static int	ft_bubble_sort(int *array, int size);

void	checker(t_stack_info *stack)
{
	init_stack(stack);
	free_stack_array(stack);
}

static void	init_stack(t_stack_info *stack)
{
	int	i;

	stack->sa = NULL;
	i = 0;
	while (i < stack->sa_size)
		ft_lstadd_back(&stack->sa, ft_lstnew(&stack->array_input[i++]));
	stack->sa_top = stack->sa;
	stack->sb = NULL;
	stack->sb_top = stack->sb;
	stack->sb_size = 0;
	stack->size = i;
	stack->n_operations = 0;
}

// static int	ft_bubble_sort(int *array, int size)
// {
// 	int	swapped;
// 	int	temp;
// 	int	i;

// 	swapped = 0;
// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		if (array[i] > array[i + 1])
// 		{
// 			temp = array[i];
// 			array[i] = array[i + 1];
// 			array[i + 1] = temp;
// 			swapped = 1;
// 		}
// 		i++;
// 	}
// 	if (swapped)
// 		ft_bubble_sort(array, size - 1);
// 	return (swapped);
// }
