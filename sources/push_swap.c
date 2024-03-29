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

#include "../includes/push_swap.h"

static void	init_stack(t_stack_info *stack);
static int	ft_bubble_sort(int *array, int size);
static void	update_stack(t_stack_info *stack);

void	push_swap(t_stack_info *stack)
{
	init_stack(stack);
	if (!ft_bubble_sort(stack->array_sorted, stack->sa_size))
	{
		free_stack_array(stack);
		return ;
	}
	update_stack(stack);
	if (stack->sa_size == 2)
		sa(stack, 1);
	else if (stack->sa_size <= 10)
		sort_small(stack);
	else if (stack->sa_size <= 100)
		sort_big(stack, 4);
	else
		sort_big(stack, 10);
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

static void	update_stack(t_stack_info *stack)
{
	int	i;
	int	j;

	stack->min_int = stack->array_sorted[0];
	stack->max_int = stack->array_sorted[stack->sa_size - 1];
	i = -1;
	while (++i < stack->sa_size)
	{
		j = -1;
		while (++j < stack->sa_size)
		{
			if (stack->array_input[i][0] == stack->array_sorted[j])
				stack->array_input[i][1] = j;
		}
	}
}
