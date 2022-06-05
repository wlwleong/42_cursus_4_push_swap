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

static void	init_stack(t_stack_info *stack);
static int	ft_check_op(char *str);
static void	execute_op(t_stack_info *stack, char *operation);
static int	ft_check_sorted(t_list *lst);

void	checker(t_stack_info *stack)
{
	char	*temp;

	init_stack(stack);
	temp = get_next_line(STDIN_FILENO);
	while (temp)
	{
		if (!ft_check_op(temp))
			ft_error(-2, stack);
		ft_lstadd_back(&stack->op_lst, ft_lstnew(ft_strdup(temp)));
		if (stack->op_lst_top == NULL)
			stack->op_lst_top = stack->op_lst;
		free(temp);
		temp = get_next_line(STDIN_FILENO);
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
		&& ft_strncmp(str, "rra", 3) != 0 && ft_strncmp(str, "rrb", 3) != 0
		&& ft_strncmp(str, "rrr", 3) != 0 && ft_strncmp(str, "rr", 2) != 0)
		return (0);
	return (1);
}

static void	execute_op(t_stack_info *stack, char *operation)
{
	if (ft_strncmp(operation, "sa", 2) == 0)
		sa(stack, DISPLAY_OFF);
	else if (ft_strncmp(operation, "sb", 2) == 0)
		sb(stack, DISPLAY_OFF);
	else if (ft_strncmp(operation, "ss", 2) == 0)
		ss(stack, DISPLAY_OFF);
	else if (ft_strncmp(operation, "pa", 2) == 0)
		pa(stack, DISPLAY_OFF);
	else if (ft_strncmp(operation, "pb", 2) == 0)
		pb(stack, DISPLAY_OFF);
	else if (ft_strncmp(operation, "ra", 2) == 0)
		ra(stack, DISPLAY_OFF);
	else if (ft_strncmp(operation, "rb", 2) == 0)
		rb(stack, DISPLAY_OFF);
	else if (ft_strncmp(operation, "rra", 3) == 0)
		rra(stack, DISPLAY_OFF);
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		rrb(stack, DISPLAY_OFF);
	else if (ft_strncmp(operation, "rrr", 3) == 0)
		rrr(stack, DISPLAY_OFF);
	else if (ft_strncmp(operation, "rr", 2) == 0)
		rr(stack, DISPLAY_OFF);
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
