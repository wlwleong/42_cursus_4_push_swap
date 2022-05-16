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

#include "push_swap.h"

void	sort_medium(t_stack_info *stack, int part)
{
	int	*pivot_index;
	int	i;

	pivot_index = ft_get_pivot(stack->sa_size, part);
	i = -1;
	while (++i < part - 1)
	{
		stack->sa = stack->sa_top;
		while (stack->sa)
		{
			if (*(*(int **) stack->sa->content + 1) < pivot_index[i])
				ft_push_b(stack, *(*(int **) stack->sa->content + 1));
			stack->sa = stack->sa->next;
		}
	}
	while (stack->sa_size > 1)
		ft_push_b(stack, ft_find_min(stack->sa, stack->sa_top, stack->max_int));
	while (stack->sb_size > pivot_index[part - 2])
		pa(stack);
	while (stack->sb_size > 1)
		ft_push_a(stack, ft_find_max(stack->sb, stack->sb_top, stack->min_int));
	pa(stack);
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

int	ft_find_min(t_list *lst, t_list *lst_top, int stack_max)
{
	int	min;
	int	return_index;

	min = stack_max;
	return_index = -1;
	lst = lst_top;
	while (lst)
	{
		if (*(*(int **) lst->content + 0) < min)
		{
			min = *(*(int **) lst->content + 0);
			return_index = *(*(int **) lst->content + 1);
		}
		lst = lst->next;
	}
	if (return_index == -1)
		ft_putstr_fd("Error. min not found!\n", 1);
	return (return_index);
}

int	ft_find_max(t_list *lst, t_list *lst_top, int stack_min)
{
	int	max;
	int	return_index;

	max = stack_min;
	return_index = -1;
	lst = lst_top;
	while (lst)
	{
		if (*(*(int **) lst->content + 0) > max)
		{
			max = *(*(int **) lst->content + 0);
			return_index = *(*(int **) lst->content + 1);
		}
		lst = lst->next;
	}
	if (return_index == -1)
		ft_putstr_fd("Error. max not found!\n", 1);
	return (return_index);
}

void	ft_push_a(t_stack_info *stack, int sorted_index)
{
	int	proximity;
	int	reverse;

	reverse = 0;
	proximity = (stack->sb_size / 2) + (stack->sb_size % 2);
	if (proximity > ft_get_index(stack->sb, stack->sb_top, sorted_index))
		reverse = 1;
	stack->sb = stack->sb_top;
	while (*(*(int **) stack->sb->content + 1) != sorted_index && stack->sb)
	{
		if (reverse)
			rb(stack, 1);
		else
			rrb(stack, 1);
	}
	pa(stack);
}
