/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:16:53 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/21 23:20:29 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_stack_info *stack)
{
	int	*pivot_index;

	pivot_index = ft_get_pivot(stack->sa_size, 4);
	ft_push_median(stack, pivot_index);
	ft_push_sort(stack);
	while (stack->n_top_sorted--)
		ra(stack, 1);
	ft_push_rest(stack);
	ft_push_sort(stack);
	while (*(*(int **) stack->sa_top->content + 0) != stack->array_sorted[0])
		ra(stack, 1);
	free(pivot_index);
}

int	ft_find_min_index(t_list *lst, t_list *lst_top, int stack_max)
{
	int	min;
	int	return_index;
	int	i;

	min = stack_max;
	return_index = -1;
	i = 0;
	lst = lst_top;
	while (lst)
	{
		if (*(*(int **) lst->content + 0) < min)
		{
			min = *(*(int **) lst->content + 0);
			return_index = i;
		}
		lst = lst->next;
		i++;
	}
	return (return_index);
}

int	ft_find_max_index(t_list *lst, t_list *lst_top, int stack_min)
{
	int	max;
	int	return_index;
	int	i;

	max = stack_min;
	return_index = -1;
	i = 0;
	lst = lst_top;
	while (lst)
	{
		if (*(*(int **) lst->content + 0) > max)
		{
			max = *(*(int **) lst->content + 0);
			return_index = i;
		}
		lst = lst->next;
		i++;
	}
	return (return_index);
}
