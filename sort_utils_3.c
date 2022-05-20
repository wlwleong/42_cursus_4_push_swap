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

#include "push_swap.h"

int	ft_find_max_pos(t_list *lst, t_list *lst_top, int stack_max, int stack_size)
{
	int	max_index;
	int	center;
	int	index;

	max_index = -1;
	index = 0;
	lst = lst_top;
	while (lst && max_index == -1)
	{
		if (*(*(int **) lst->content + 1) == stack_max)
			max_index = index;
		lst = lst->next;
		index++;
	}
	center = stack_size / 2 + stack_size % 2;
	if (max_index > center)
		return (stack_size - max_index + 1);
	return (max_index + 1);
}

int	ft_find_min_pos(t_list *lst, t_list *lst_top, int stack_min, int stack_size)
{
	int	min_index;
	int	center;
	int	index;

	min_index = -1;
	index = 0;
	lst = lst_top;
	while (lst && min_index == -1)
	{
		if (*(*(int **) lst->content + 1) == stack_min)
			min_index = index;
		lst = lst->next;
		index++;
	}
	center = stack_size / 2 + stack_size % 2;
	if (min_index > center)
		return (stack_size - min_index + 1);
	return (min_index + 1);
}
