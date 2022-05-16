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

#include "push_swap.h"

static void	init_stack(t_stack_info *stack);
static void	ft_fill_index(t_stack_info *stack);

void	push_swap(t_stack_info stack)
{
	init_stack(&stack);
	if (!ft_bubble_sort(stack.array_sorted, stack.sa_size))
	{
		free_stack_array(&stack);
		return ;
	}
	ft_fill_index(&stack);
	if (stack.sa_size == 2)
		sa(&stack, 1);
	else if (stack.sa_size == 3)
		sort_three_sa(&stack);
	else if (stack.sa_size <= 10)
		sort_small(&stack);
	else
		sort_medium(&stack);
	// ft_print_arr(stack.array_input, stack.sa_size);
	// ft_putstr_fd("After sorted: ", 1);
	// ft_print_lst(stack.sa, stack.sa_top);
	free_stack_array(&stack);
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
}

static void	ft_fill_index(t_stack_info *stack)
{
	int	i;
	int	j;

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

void	ft_lstclear_new(t_list **lst)
{
	t_list	*list;
	t_list	*temp;

	list = *lst;
	if (!list)
		return ;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	*lst = NULL;
}
