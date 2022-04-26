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
#include <stdio.h>

int		ft_get_limits(t_stack_info *sa);
int		ft_check_sorted(t_stack_info *sa);
void	init_stack(t_stack_info *sa_info, t_list **sa);
void	ft_lstclear_new(t_list **lst);

void	push_swap(t_stack_info sa_info)
{
	t_list	*stack_a;
	int		i;

	if (ft_get_limits(&sa_info))
	{
		if (ft_check_sorted(&sa_info))
			return ;
	}
	init_stack(&sa_info, &stack_a);
	i = 1;
	while (stack_a)
	{
		printf("Node %d = %d\n", i, *(int *)stack_a->content);
		stack_a = stack_a->next;
		i++;
	}
	stack_a = sa_info.sa_top;
	ft_lstclear_new(&stack_a);
}

int	ft_get_limits(t_stack_info *sa)
{
	int		i;

	sa->largest_int = INT_MIN;
	sa->smallest_int = INT_MAX;
	i = 0;
	while (i < sa->sa_size)
	{
		if (sa->array[i] > sa->largest_int)
		{
			sa->largest_int = sa->array[i];
			sa->largest_int_index = i;
		}
		if (sa->array[i] < sa->smallest_int)
		{
			sa->smallest_int = sa->array[i];
			sa->smallest_int_index = i;
		}
		i++;
	}
	if (sa->smallest_int_index == 0
		&& sa->largest_int_index == sa->sa_size - 1)
		return (1);
	return (0);
}

int	ft_check_sorted(t_stack_info *sa)
{
	int	i;

	i = 0;
	while (i < sa->sa_size - 1 && sa->array[i] < sa->array[i + 1])
		i++;
	if (i + 1 == sa->sa_size)
		return (1);
	return (0);
}

void	init_stack(t_stack_info *sa_info, t_list **sa)
{
	int	i;

	i = 0;
	while (i < sa_info->sa_size)
	{
		if (i == 0)
		{
			*sa = ft_lstnew(&sa_info->array[i]);
			sa_info->sa_top = *sa;
		}
		else
			ft_lstadd_back(sa, ft_lstnew(&sa_info->array[i]));
		i++;
	}
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
