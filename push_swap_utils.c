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

void	free_stack_array(t_stack_info *stack)
{
	int	i;

	stack->sa = stack->sa_top;
	ft_lstclear(&stack->sa);
	stack->sb = stack->sb_top;
	ft_lstclear(&stack->sb);
	i = -1;
	while (++i < stack->sa_size)
		free(stack->array_input[i]);
	free(stack->array_input);
	free(stack->array_sorted);
}

void	ft_print_arr(int **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(array[i][0], 1);
		ft_putchar_fd(',', 1);
		ft_putnbr_fd(array[i][1], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	ft_print_lst(t_list *lst)
{
	int	i;

	if (!lst)
		return ;
	i = 1;
	while (lst)
	{
		ft_putnbr_fd(*(*(int **)lst->content + 0), 1);
		ft_putchar_fd(',', 1);
		ft_putnbr_fd(*(*(int **)lst->content + 1), 1);
		ft_putchar_fd(' ', 1);
		lst = lst->next;
		i++;
	}
	ft_putchar_fd('\n', 1);
}
