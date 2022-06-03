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
static int	ft_bubble_sort(int *array, int size);

void	checker(t_stack_info *stack)
{
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
	stack->array_sorted = malloc (sizeof(int) * stack->sa_size);
	if (!stack->array_sorted)
	{
		ft_putstr_fd("array_sorted malloc Error!\n", 1);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < stack->sa_size)
		stack->array_sorted[i] = stack->array_input[i][0];
	stack->size = i;
	stack->n_top_sorted = 0;
	stack->n_operations = 0;
}

static int	ft_bubble_sort(int *array, int size)
{
	int	swapped;
	int	temp;
	int	i;

	swapped = 0;
	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			swapped = 1;
		}
		i++;
	}
	if (swapped)
		ft_bubble_sort(array, size - 1);
	return (swapped);
}
