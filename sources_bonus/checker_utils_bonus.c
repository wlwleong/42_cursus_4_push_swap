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

#include "../includes/checker_bonus.h"

void	ft_error(int type, t_stack_info *stack)
{
	if (type == 0 || type == -1 || type == -2)
	{
		write(2, "Error\n", 6);
		if (type == -1)
			free(stack->array_input);
		else if (type == -2)
			free_stack_array(stack);
	}
	else if (type == -3)
		ft_putstr_fd("malloc Error\n", 1);
	exit(EXIT_FAILURE);
}

void	free_stack_array(t_stack_info *stack)
{
	ft_lstclear(&stack->sa_top);
	ft_lstclear(&stack->sb_top);
	stack->op_lst = stack->op_lst_top;
	while (stack->op_lst)
	{
		free(stack->op_lst->content);
		stack->op_lst = stack->op_lst->next;
	}
	ft_lstclear(&stack->op_lst_top);
	free(stack->array_input);
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

void	ft_print_lst(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_putstr_fd((char *) lst->content, 1);
		ft_putchar_fd(' ', 1);
		lst = lst->next;
	}
	ft_putchar_fd('\n', 1);
}
