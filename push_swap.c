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

static int	*ft_array_dup(int *source, int size);

void	push_swap(t_stack_info sa_info)
{
	init_stack(&sa_info);
	// ft_print_lst(sa_info.sa, sa_info.sa_top);
	sa_info.array_sorted = ft_array_dup(sa_info.array_input, sa_info.sa_size);
	if (!ft_bubble_sort(sa_info.array_sorted, sa_info.sa_size))
		return ;
	if (sa_info.sa_size == 2)
		sa(&sa_info, 1);
	else if (sa_info.sa_size <= 10)
		sort_small(&sa_info);
	// ft_putstr_fd("After sorted: ", 1);
	// ft_print_lst(sa_info.sa, sa_info.sa_top);
	// ft_putstr_fd("Bubble sorted: ", 1);
	// ft_print_arr(sa_info.array_sorted, sa_info.sa_size);
	free_stack(&sa_info);
}

static int	*ft_array_dup(int *source, int size)
{
	int	*copy;
	int	i;

	copy = malloc (sizeof(int) * size);
	i = -1;
	while (++i < size)
		copy[i] = source[i];
	return (copy);
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
