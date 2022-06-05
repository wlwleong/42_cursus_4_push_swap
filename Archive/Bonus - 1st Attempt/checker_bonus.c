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

#include "../includes/checker_bonus.h"
#include <stdio.h>

static void	init_stack(t_stack_info *stack);
static int	ft_check_op(char *str);
static void	execute_op(t_stack_info *stack, char *operation);
static int	ft_check_sorted(t_list *lst);

void	checker(t_stack_info *stack)
{
	t_gnl	gnl;

	init_stack(stack);
	gnl.n_read = read(0, gnl.input, BUFFER_SIZE);
	while (gnl.n_read > 0)
	{
		gnl.input[gnl.n_read - 1] = '\0';
		if (!ft_check_op(gnl.input))
			ft_error(-2, stack);
		ft_lstadd_back(&stack->op_lst, ft_lstnew(ft_strdup(gnl.input)));
		if (stack->op_lst_top == NULL)
			stack->op_lst_top = stack->op_lst;
		gnl.n_read = read(0, gnl.input, BUFFER_SIZE);
	}
	stack->op_lst = stack->op_lst_top;
	while (stack->op_lst)
	{
		execute_op(stack, (char *) stack->op_lst->content);
		stack->op_lst = stack->op_lst->next;
	}
	if (ft_check_sorted(stack->sa_top))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack_array(stack);
}

static void	init_stack(t_stack_info *stack)
{
	int	i;

	stack->sa = NULL;
	i = 0;
	while (i < stack->sa_size)
		ft_lstadd_back(&stack->sa, ft_lstnew(&stack->array_input[i++]));
	stack->sa_top = stack->sa;
	stack->sb = NULL;
	stack->sb_top = stack->sb;
	stack->sb_size = 0;
	stack->op_lst = NULL;
	stack->op_lst_top = stack->op_lst;
	stack->n_operations = 0;
}

static int	ft_check_op(char *str)
{
	if (ft_strncmp(str, "sa", 2) != 0 && ft_strncmp(str, "sb", 2) != 0
		&& ft_strncmp(str, "ss", 2) != 0
		&& ft_strncmp(str, "pa", 2) != 0 && ft_strncmp(str, "pb", 2) != 0
		&& ft_strncmp(str, "ra", 2) != 0 && ft_strncmp(str, "rb", 2) != 0
		&& ft_strncmp(str, "rr", 2) != 0
		&& ft_strncmp(str, "rra", 3) != 0 && ft_strncmp(str, "rrb", 3) != 0
		&& ft_strncmp(str, "rrr", 3) != 0)
		return (0);
	return (1);
}

static void	execute_op(t_stack_info *stack, char *operation)
{
	if (ft_strncmp(operation, "sa", 3) == 0)
		sa(stack, 0);
	else if (ft_strncmp(operation, "sb", 3) == 0)
		sb(stack, 0);
	else if (ft_strncmp(operation, "ss", 3) == 0)
		ss(stack, 0);
	else if (ft_strncmp(operation, "pa", 3) == 0)
		pa(stack, 0);
	else if (ft_strncmp(operation, "pb", 3) == 0)
		pb(stack, 0);
	else if (ft_strncmp(operation, "ra", 3) == 0)
		ra(stack, 0);
	else if (ft_strncmp(operation, "rb", 3) == 0)
		rb(stack, 0);
	else if (ft_strncmp(operation, "rr", 3) == 0)
		rr(stack, 0);
	else if (ft_strncmp(operation, "rra", 4) == 0)
		rra(stack, 0);
	else if (ft_strncmp(operation, "rrb", 4) == 0)
		rrb(stack, 0);
	else if (ft_strncmp(operation, "rrr", 4) == 0)
		rrr(stack, 0);
}

static int	ft_check_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (*(int *) lst->content > *(int *) lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
