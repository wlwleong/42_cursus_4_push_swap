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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_info
{
	int		*array;
	int		size;
	int		largest_int;
	int		smallest_int;
	t_list	*sa_top;
	t_list	*sa;
	t_list	*sb_top;
	t_list	*sb;
}		t_stack_info;

/*
push_swap.c
*/
void	push_swap(t_stack_info sa_info);

/*
push_swap_utils.c
*/
int		ft_get_limits(t_stack_info *sa);
int		ft_check_sorted(t_stack_info *sa);
void	init_stack(t_stack_info *sa);
void	ft_print_lst(t_list *lst);

/*
operation_s_p.c
*/
void	sa(t_stack_info *stack, int display);
void	sb(t_stack_info *stack, int display);
void	ss(t_stack_info *stack);
void	pa(t_stack_info *stack);
void	pb(t_stack_info *stack);

#endif
