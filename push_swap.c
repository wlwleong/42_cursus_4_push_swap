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
	pb(&sa_info);
	pb(&sa_info);
	pb(&sa_info);
	ft_putstr_fd("stack a\n", 1);
	ft_print_lst(sa_info.sa);
	ft_putstr_fd("stack b\n", 1);
	ft_print_lst(sa_info.sb);
	ft_putstr_fd("\n", 1);
	rra(&sa_info, 1);
	ft_putstr_fd("stack a\n", 1);
	ft_print_lst(sa_info.sa);
	ft_putstr_fd("stack b\n", 1);
	ft_print_lst(sa_info.sb);
	ft_putstr_fd("\n", 1);
	rrb(&sa_info, 1);
	ft_putstr_fd("stack a\n", 1);
	ft_print_lst(sa_info.sa);
	ft_putstr_fd("stack b\n", 1);
	ft_print_lst(sa_info.sb);
	ft_putstr_fd("\n", 1);
	rrr(&sa_info);
	ft_putstr_fd("stack a\n", 1);
	ft_print_lst(sa_info.sa);
	ft_putstr_fd("stack b\n", 1);
	ft_print_lst(sa_info.sb);
	ft_putstr_fd("\n", 1);
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
