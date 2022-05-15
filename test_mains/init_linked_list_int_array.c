/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_linked_list_int_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:06:44 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/15 11:30:27 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

void		ft_lstclear_new(t_list **lst);
static int	**ft_array_dup(int **source, int size);
int			ft_bubble_sort(int **array, int size);
void		ft_fill_index(int **source, int **sorted, int size);
void		ft_print_arr(int **array, int size);
void		ft_print_arr_sort(int **array, int size);

int	main(int argc, char *argv[])
{
	t_list			*stack_a;
	t_list			*stack_a_head;
	int				**stack_a_array;
	int				**stack_a_array_sorted;
	int				i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_a_array = malloc (sizeof(int *) * (argc - 1));
	if (!stack_a_array)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < argc - 1)
	{
		stack_a_array[i] = malloc (sizeof(int) * 2);
		if (!stack_a_array[i])
			exit(EXIT_FAILURE);
		stack_a_array[i][0] = ft_atoi(argv[i + 1]);
		stack_a_array[i][1] = i;
		if (i == 0)
		{
			stack_a = ft_lstnew(&stack_a_array[i]);
			stack_a_head = stack_a;
		}
		else
			ft_lstadd_back(&stack_a, ft_lstnew(&stack_a_array[i]));
		i++;
	}
	stack_a_array_sorted = ft_array_dup(stack_a_array, argc - 1);
	ft_print_arr(stack_a_array, argc - 1);
	ft_bubble_sort(stack_a_array_sorted, argc - 1);
	ft_fill_index(stack_a_array, stack_a_array_sorted, argc - 1);
	ft_print_arr(stack_a_array, argc - 1);
	ft_print_arr_sort(stack_a_array, argc - 1);
	i = 1;
	while (stack_a)
	{
		printf("Node %d = %d\n", i, *(*(int **)stack_a->content + 0));
		stack_a = stack_a->next;
		i++;
	}
	stack_a = stack_a_head;
	ft_lstclear_new(&stack_a);
	i = -1;
	while (++i < argc - 1)
	{
		free(stack_a_array[i]);
		free(stack_a_array_sorted[i]);
	}
	free(stack_a_array);
	free(stack_a_array_sorted);
	return (0);
}

static int	**ft_array_dup(int **source, int size)
{
	int	**copy;
	int	i;

	copy = malloc (sizeof(int *) * size);
	i = -1;
	while (++i < size)
	{
		copy[i] = malloc (sizeof(int) * 2);
		if (!copy[i])
			exit(EXIT_FAILURE);
		copy[i][0] = source[i][0];
		copy[i][1] = source[i][1];
	}
	return (copy);
}

int	ft_bubble_sort(int **array, int size)
{
	int	swapped;
	int	temp;
	int	i;

	swapped = 0;
	i = 0;
	while (i < size - 1)
	{
		if (array[i][0] > array[i + 1][0])
		{
			temp = array[i][0];
			array[i][0] = array[i + 1][0];
			array[i + 1][0] = temp;
			swapped = 1;
		}
		i++;
	} 
	if (swapped)
		ft_bubble_sort(array, size - 1);
	return (swapped);
}

void	ft_fill_index(int **source, int **sorted, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (source[i][0] == sorted[j][0])
				source[i][1] = j;
		}
	}
}

void	ft_print_arr(int **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(array[i][0], 1);
		ft_putchar_fd(',', 1);
		ft_putnbr_fd(array[i][1], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	ft_print_arr_sort(int **array, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (array[j][1] == i)
			{
				ft_putnbr_fd(array[j][0], 1);
				ft_putchar_fd(' ', 1);
			}
		}
	}
	ft_putchar_fd('\n', 1);
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
