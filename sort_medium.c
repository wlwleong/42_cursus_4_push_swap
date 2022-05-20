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
		while (ft_push_less(stack, pivot_index[i]))
			continue;
	}
	while (stack->sa_size > 3)
		ft_push_b(stack, ft_find_min(stack->sa, stack->sa_top, stack->max_int));
	sort_three_sa(stack);
	while (stack->sb_size > pivot_index[part - 2])
		pa(stack);
	while (stack->sb_size > 1)
	{
		ft_print_lst(stack->sb, stack->sb_top);
		printf("max is at %d   min is at %d   stack size = %d\n", ft_find_max_pos(stack->sb, stack->sb_top, ft_find_max(stack->sb, stack->sb_top, stack->min_int)), ft_find_min_pos(stack->sb, stack->sb_top, ft_find_min(stack->sb, stack->sb_top, stack->max_int)), stack->sb_size);
		fflush(stdout);
		ft_push_a(stack, ft_find_max(stack->sb, stack->sb_top, stack->min_int));
	}
	pa(stack);
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
