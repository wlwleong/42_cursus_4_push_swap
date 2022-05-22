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

void	ft_push_median(t_stack_info *stack, int *pivot)
{
	int n;
	int i;

	n = stack->sa_size;
	i = 0;

	while (i < n)
	{
		if (*(*(int **) stack->sa_top->content + 1) < pivot[1])
		{
			pb(stack);
			if (*(*(int **) stack->sb_top->content + 1) < pivot[0])
				rb(stack,1 );
		}
		else
			ra(stack, 1);
		i++;
	}
}

void	ft_push_sort(t_stack_info *stack)
{
	int	min_i;
	int	max_i;
	int	center;
	int	min_rotate;

	while (stack->sb_size > 1)
	{
		center = stack->sb_size / 2 + stack->sb_size % 2;
		min_i = ft_find_min_index(stack->sb, stack->sb_top, stack->max_int);
		max_i = ft_find_max_index(stack->sb, stack->sb_top, stack->min_int);
		min_rotate = 0;
		if (min_i < center && max_i < center)
		{
			if (min_i < max_i)
			{
				while (min_i--)
					rb(stack, 1);
				min_rotate = 1;
			}
			else
			{
				while (max_i--)
					rb(stack, 1);
			}
		}
		else if (min_i < center && max_i > center)
		{
			if (min_i < stack->sb_size - max_i)
			{
				while (min_i--)
					rb(stack, 1);
				min_rotate = 1;
			}
			else
			{
				max_i = stack->sb_size - max_i;
				while (max_i--)
					rrb(stack, 1);
			}
		}
		else if (min_i > center && max_i < center)
		{
			if (stack->sb_size - min_i < max_i)
			{
				min_i = stack->sb_size - min_i;
				while (min_i--)
					rrb(stack, 1);
				min_rotate = 1;
			}
			else
			{
				while (max_i--)
					rb(stack, 1);
			}
		}
		else
		{
			min_i = stack->sb_size - min_i;
			max_i = stack->sb_size - max_i;
			if (min_i < max_i)
			{
				while (min_i--)
					rrb(stack, 1);
				min_rotate = 1;
			}
			else
			{
				while (max_i--)
					rrb(stack, 1);
			}
		}
		pa(stack);
		if (min_rotate)
			ra(stack, 1);
	}
	pa(stack);
	ra(stack, 1);
}

int	ft_find_min_index(t_list *lst, t_list *lst_top, int stack_max)
{
	int	min;
	int	return_index;
	int	i;

	min = stack_max;
	return_index = -1;
	i = 0;
	lst = lst_top;
	while (lst)
	{
		if (*(*(int **) lst->content + 0) < min)
		{
			min = *(*(int **) lst->content + 0);
			return_index = i;
		}
		lst = lst->next;
		i++;
	}
	return (return_index);
}

int	ft_find_max_index(t_list *lst, t_list *lst_top, int stack_min)
{
	int	max;
	int	return_index;
	int	i;

	max = stack_min;
	return_index = -1;
	i = 0;
	lst = lst_top;
	while (lst)
	{
		if (*(*(int **) lst->content + 0) > max)
		{
			max = *(*(int **) lst->content + 0);
			return_index = i;
		}
		lst = lst->next;
		i++;
	}
	return (return_index);
}

int	ft_push_part(t_stack_info *stack, int pivot1, int pivot2)
{
	int n;
	int	i;

	n = stack->sa_size;
	i = 0;
	while (i < n)
	{
		// ft_print_lst(stack->sa, stack->sa_top);
		if (*(*(int **) stack->sa_top->content + 1) < pivot2)
		{
			// printf("pushing %d to b...\n", *(*(int **) stack->sa_top->content));
			pb(stack);
			if (*(*(int **) stack->sa_top->content) + 1 > pivot2 && *(*(int **) stack->sb_top->content + 1) < pivot1)
			{
				// printf("rotating both because %d is in 3rd part...\n", *(*(int **) stack->sa_top->content));
				rr(stack);
			}
			else if (*(*(int **) stack->sb_top->content + 1) < pivot1)
			{
				// printf("rotating b because %d is in the 1st part...\n", *(*(int **) stack->sb_top->content));
				rb(stack, 1);
			}
		}
		else
		{
			// printf("rotating a because %d is in the 3rd part\n", *(*(int **) stack->sa_top->content));
			ra(stack, 1);
		}
		i++;
		// printf("stack size = %d\n", stack->sa_size);
		fflush(stdout);
	}
	return (1);
}
