/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:16:53 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/14 22:17:33 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_stack_info *stack)
{
	int	pivot_key[4];
	int	size;
	int	i;

	size = stack->sa_size;
	pivot_key[0] = stack->array_sorted[size / 4 * 1];
	pivot_key[1] = stack->array_sorted[size / 4 * 2];
	pivot_key[2] = stack->array_sorted[size / 4 * 3];
	i = 0;
	while (i < 3)
	{
		stack->sa = stack->sa_top;
		while (stack->sa)
		{
			if (*(int *) stack->sa->content < pivot_key[i])
				ft_pb_key(stack, *(int *) stack->sa->content);
			stack->sa = stack->sa->next;
		}
		i++;
	}
	sort_small(stack, (size / 4 * 3));
	while (stack->sb_size > 0)
		ft_pa_largest(stack, ft_get_largest(stack->sb, stack->sb_top));
}

void	sort_three_sb(t_stack_info *stack)
{
	int	num0;
	int	num1;
	int	num2;

	num0 = *(int *) stack->sb_top->content;
	num1 = *(int *) stack->sb_top->next->content;
	num2 = *(int *) stack->sb_top->next->next->content;
	if (num0 > num1 && num1 < num2 && num0 < num2)
		sb(stack, 1);
	else if (num0 > num1 && num1 > num2 && num0 > num2)
	{
		sb(stack, 1);
		rrb(stack, 1);
	}
	else if (num0 > num1 && num1 < num2 && num0 > num2)
		rb(stack, 1);
	else if (num0 < num1 && num1 > num2 && num0 < num2)
	{
		sb(stack, 1);
		rb(stack, 1);
	}
	else if (num0 < num1 && num1 > num2 && num0 > num2)
		rrb(stack, 1);
	else
		return ;
}

void	ft_pb_key(t_stack_info *stack, int num)
{
	int	proximity;
	int	reverse;

	reverse = 0;
	proximity = (stack->sa_size / 2) + (stack->sa_size % 2);
	if (proximity > ft_get_index(stack->sa, stack->sa_top, num))
		reverse = 1;
	stack->sa = stack->sa_top;
	while (*(int *) stack->sa->content != num && stack->sa)
	{
		if (reverse)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
	pb(stack);
}

int	ft_get_largest(t_list *lst, t_list *lst_top)
{
	int	largest;

	largest = INT_MIN;
	lst = lst_top;
	while (lst)
	{
		if (*(int *) lst->content > largest)
			largest = *(int *) lst->content;
		lst = lst->next;
	}
	return (largest);
}

void	ft_pa_largest(t_stack_info *stack, int num)
{
	int	proximity;
	int	reverse;

	reverse = 0;
	proximity = (stack->sb_size / 2) + (stack->sb_size % 2);
	if (proximity > ft_get_index(stack->sb, stack->sb_top, num))
		reverse = 1;
	stack->sb = stack->sb_top;
	while (*(int *) stack->sb->content != num && stack->sb)
	{
		if (reverse)
			rb(stack, 1);
		else
			rrb(stack, 1);
	}
	pa(stack);
}