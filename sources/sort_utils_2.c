/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:18:19 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/18 00:10:59 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	ft_find_min(t_list *lst, int stack_max)
{
	int	min;
	int	return_index;

	min = stack_max;
	return_index = -1;
	while (lst)
	{
		if (*(*(int **) lst->content + 0) < min)
		{
			min = *(*(int **) lst->content + 0);
			return_index = *(*(int **) lst->content + 1);
		}
		lst = lst->next;
	}
	return (return_index);
}

int	ft_find_max(t_list *lst, int stack_min)
{
	int	max;
	int	return_index;

	max = stack_min;
	return_index = -1;
	while (lst)
	{
		if (*(*(int **) lst->content + 0) > max)
		{
			max = *(*(int **) lst->content + 0);
			return_index = *(*(int **) lst->content + 1);
		}
		lst = lst->next;
	}
	return (return_index);
}

int	ft_smart_rotate(t_stack_info *stack, int *index1, int *index2)
{
	if (index1[0] < stack->sb_size - index1[0])
		index1[1] = index1[0];
	else
		index1[1] = stack->sb_size - index1[0];
	if (index2[0] < stack->sb_size - index2[0])
		index2[1] = index2[0];
	else
		index2[1] = stack->sb_size - index2[0];
	if (index1[1] < index2[1])
		ft_rb_rrb_pa(stack, index1[0], 1);
	else
	{
		ft_rb_rrb_pa(stack, index2[0], 0);
		return (1);
	}
	return (0);
}

void	ft_rb_rrb_pa(t_stack_info *stack, int index, int rotate)
{
	int	center;

	center = stack->sb_size / 2 + stack->sb_size % 2;
	if (index < center)
	{
		while (index--)
			rb(stack, 1);
	}
	else
	{
		index = stack->sb_size - index;
		while (index--)
			rrb(stack, 1);
	}
	pa(stack, 1);
	if (rotate)
		ra(stack, 1);
}
