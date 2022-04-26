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

void	ft_get_limits(int *arr, int size, t_stack_info *stack_a);
void	ft_lstclear_new(t_list **lst);

void	push_swap(t_stack_info sa_info)
{
	t_list	*stack_a;
	t_list	*stack_a_head;
	int		i;

	i = 0;
	while (i < sa_info.sa_size)
	{
		if (i == 0)
		{
			stack_a = ft_lstnew(&sa_info.array[i]);
			stack_a_head = stack_a;
		}
		else
			ft_lstadd_back(&stack_a, ft_lstnew(&sa_info.array[i]));
		i++;
	}
	ft_get_limits(sa_info.array, sa_info.sa_size, &sa_info);
	i = 1;
	while (stack_a)
	{
		printf("Node %d = %d\n", i, *(int *)stack_a->content);
		stack_a = stack_a->next;
		i++;
	}
	printf("Smallest num = %d   ;   Largest num = %d\n", sa_info.smallest_int, sa_info.largest_int);
	stack_a = stack_a_head;
	ft_lstclear_new(&stack_a);
}

void		ft_get_limits(int *arr, int size, t_stack_info *stack_a)
{
	int		i;

	stack_a->largest_int = INT_MIN;
	stack_a->smallest_int = INT_MAX;
	i = 0;
	while (i < size)
	{
		if (arr[i] > stack_a->largest_int)
			stack_a->largest_int = arr[i];
		if (arr[i] < stack_a->smallest_int)
			stack_a->smallest_int = arr[i];
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
