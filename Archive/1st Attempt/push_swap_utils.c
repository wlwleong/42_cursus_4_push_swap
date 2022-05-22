/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:10:20 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/08 01:30:42 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack_info *stack)
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
}

int	ft_bubble_sort(int *array, int size)
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

void	free_stack(t_stack_info *stack)
{
	stack->sa = stack->sa_top;
	ft_lstclear_new(&stack->sa);
	stack->sb = stack->sb_top;
	ft_lstclear_new(&stack->sb);
	free(stack->array_input);
	free(stack->array_sorted);
}

void	ft_print_arr(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(array[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	ft_print_lst(t_list *lst, t_list *lst_top)
{
	int	i;

	if (!lst)
		return ;
	lst = lst_top;
	i = 1;
	while (lst)
	{
		ft_putnbr_fd(*(int *)lst->content, 1);
		ft_putchar_fd(' ', 1);
		lst = lst->next;
		i++;
	}
	ft_putchar_fd('\n', 1);
}
