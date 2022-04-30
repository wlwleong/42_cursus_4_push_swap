/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:10:20 by wlwleong          #+#    #+#             */
/*   Updated: 2022/04/27 14:10:46 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_limits(t_stack_info *sa)
{
	int	largest_index;
	int	smallest_index;
	int	i;

	sa->largest_int = INT_MIN;
	sa->smallest_int = INT_MAX;
	i = 0;
	while (i < sa->size)
	{
		if (sa->array[i] > sa->largest_int)
		{
			sa->largest_int = sa->array[i];
			largest_index = i;
		}
		if (sa->array[i] < sa->smallest_int)
		{
			sa->smallest_int = sa->array[i];
			smallest_index = i;
		}
		i++;
	}
	if (smallest_index == 0
		&& largest_index == sa->size - 1)
		return (1);
	return (0);
}

int	ft_check_sorted(t_stack_info *sa)
{
	int	i;

	i = 0;
	while (i < sa->size - 1 && sa->array[i] < sa->array[i + 1])
		i++;
	if (i + 1 == sa->size)
		return (1);
	return (0);
}

void	init_stack(t_stack_info *sa_info)
{
	sa_info->sa = NULL;
    sa_info->sa_top = NULL;
    sa_info->sb = NULL;
    sa_info->sb_top = NULL;
}

void	ft_print_lst(t_list *lst)
{
	int	i;

	if (!lst)
		return ;
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
