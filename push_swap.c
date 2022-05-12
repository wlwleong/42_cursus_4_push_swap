/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:32:09 by wlwleong          #+#    #+#             */
/*   Updated: 2022/04/26 20:33:23 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack_info sa_info)
{
	if (ft_get_limits(&sa_info))
	{
		if (ft_check_sorted(&sa_info))
			return ;
	}
	init_stack(&sa_info);
	ft_print_lst(sa_info.sa);
	if (sa_info.size == 2)
		sa(&sa_info, 1);
	else if (sa_info.size == 3)
		sort_three(&sa_info);
	ft_putstr_fd("After sorted:\n", 1);
	ft_print_lst(sa_info.sa);
	free_stack(&sa_info);
}

void	ft_lstclear_new(t_list **lst)
{
	t_list	*list;
	t_list	*temp;

	list = *lst;
	if (!list)
		return ;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
	*lst = NULL;
}
