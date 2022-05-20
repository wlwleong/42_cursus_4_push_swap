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

int	ft_find_max_pos(t_list *lst, t_list *lst_top, int stack_max)
{
	int	max_index;
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
	return (max_index);
}

int	ft_find_min_pos(t_list *lst, t_list *lst_top, int stack_min)
{
	int	min_index;
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
	return (min_index);
}
