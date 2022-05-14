/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_linked_list_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:06:44 by wlwleong          #+#    #+#             */
/*   Updated: 2022/04/21 21:19:28 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"
#include <stdio.h>

t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstclear_new(t_list **lst);

void	ft_get_limits(int *arr, int size, t_stack_info *stack_a)
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

int	main(int argc, char *argv[])
{
	t_list			*stack_a;
	t_list			*stack_a_head;
	t_stack_info	stack_a_info;
	int				*stack_a_array;
	int				i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_a_array = malloc (sizeof(int) * (argc - 1));
	if (!stack_a_array)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < argc - 1)
	{
		stack_a_array[i] = ft_atoi(argv[i + 1]);
		if (i == 0)
		{
			stack_a = ft_lstnew(&stack_a_array[i]);
			stack_a_head = stack_a;
		}
		else
			ft_lstadd_back(&stack_a, ft_lstnew(&stack_a_array[i]));
		i++;
	}
	ft_get_limits(stack_a_array, argc - 1, &stack_a_info);
	i = 1;
	while (stack_a)
	{
		printf("Node %d = %d\n", i, *(int *)stack_a->content);
		stack_a = stack_a->next;
		i++;
	}
	printf("Smallest num = %d   ;   Largest num = %d\n", stack_a_info.smallest_int, stack_a_info.largest_int);
	stack_a = stack_a_head;
	ft_lstclear_new(&stack_a);
	free(stack_a_array);
	return (0);
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
