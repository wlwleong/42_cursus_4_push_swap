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

void	ft_lstclear_new(t_list **lst);

void	push_swap(t_stack_info sa_info)
{
	int	i;

	if (ft_get_limits(&sa_info))
	{
		if (ft_check_sorted(&sa_info))
			return ;
	}
	init_stack(&sa_info);
	i = 0;
	while (i < sa_info.size)
		ft_lstadd_back(&sa_info.sa, ft_lstnew(&sa_info.array[i++]));
	sa_info.sa_top = sa_info.sa;
	ft_print_lst(sa_info.sa);
	sa(&sa_info, 1);
	ft_print_lst(sa_info.sa);
	ss(&sa_info);
	ft_print_lst(sa_info.sa);
	sa_info.sa = sa_info.sa_top;
	ft_lstclear_new(&sa_info.sa);
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
