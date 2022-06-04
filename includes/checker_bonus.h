/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:31:59 by wlwleong          #+#    #+#             */
/*   Updated: 2022/04/27 07:32:55 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# define BUFFER_SIZE 4

typedef struct s_stack_info
{
	int		*array_input;
	int		sa_size;
	t_list	*sa_top;
	t_list	*sa;
	int		sb_size;
	t_list	*sb_top;
	t_list	*sb;
	t_list	*op_lst_top;
	t_list	*op_lst;
	int		n_operations;
}				t_stack_info;

typedef struct s_gnl
{
	char	input[BUFFER_SIZE];
	int		n_read;
}				t_gnl;

/*
checker_bonus.c
*/
void	checker(t_stack_info *stack);

/*
checker_utils_bonus.c
*/
void	ft_error(int type, t_stack_info *stack);
void	free_stack_array(t_stack_info *stack);
void	ft_print_arr(int *array, int size);
void	ft_print_lst(t_list *lst);

/*
operation_s_p.c
*/
void	sa(t_stack_info *stack, int display);
void	sb(t_stack_info *stack, int display);
void	ss(t_stack_info *stack, int display);
void	pa(t_stack_info *stack, int display);
void	pb(t_stack_info *stack, int display);

/*
operation_r.c
*/
void	ra(t_stack_info *stack, int display);
void	rb(t_stack_info *stack, int display);
void	rr(t_stack_info *stack, int display);

/*
operation_rr.c
*/
void	rra(t_stack_info *stack, int display);
void	rrb(t_stack_info *stack, int display);
void	rrr(t_stack_info *stack, int display);

#endif
