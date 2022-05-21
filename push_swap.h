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
# include <stdio.h>

typedef struct s_stack_info
{
	int		**array_input;
	int		*array_sorted;
	int		min_int;
	int		max_int;
	int		sa_size;
	t_list	*sa_top;
	t_list	*sa;
	int		sb_size;
	t_list	*sb_top;
	t_list	*sb;
	int		n_top_sorted;
}				t_stack_info;

/*
push_swap.c
*/
void	push_swap(t_stack_info sa_info);
void	ft_lstclear_new(t_list **lst);

/*
push_swap_utils.c
*/
int		ft_bubble_sort(int *array, int size);
void	free_stack_array(t_stack_info *stack);
void	ft_print_arr(int **array, int size);
void	ft_print_lst(t_list *lst, t_list *lst_top);

/*
operation_s_p.c
*/
void	sa(t_stack_info *stack, int display);
void	sb(t_stack_info *stack, int display);
void	ss(t_stack_info *stack);
void	pa(t_stack_info *stack);
void	pb(t_stack_info *stack);

/*
operation_r.c
*/
void	ra(t_stack_info *stack, int display);
void	rb(t_stack_info *stack, int display);
void	rr(t_stack_info *stack);

/*
operation_rr.c
*/
void	rra(t_stack_info *stack, int display);
void	rrb(t_stack_info *stack, int display);
void	rrr(t_stack_info *stack);

/*
sort_small.c
*/
void	sort_small(t_stack_info *stack);
int		ft_get_index(t_list *lst, t_list *lst_top, int num);

/*
sort_medium.c
*/
void	sort_medium(t_stack_info *stack);
int		ft_find_min_index(t_list *lst, t_list *lst_top, int stack_max);
int		ft_find_max_index(t_list *lst, t_list *lst_top, int stack_min);

/*
sort_big.c
*/
void	sort_big(t_stack_info *stack, int part);
int		ft_find_min(t_list *lst, t_list *lst_top, int stack_max);
int		ft_find_max(t_list *lst, t_list *lst_top, int stack_min);

/*
sort_utils_1.c
*/
void	sort_three_sa(t_stack_info *stack);
void	sort_three_sb(t_stack_info *stack);
void	ft_push_b(t_stack_info *stack, int sorted_index);
void	ft_push_a(t_stack_info *stack, int sorted_index);

/*
sort_utils_2.c
*/
int		*ft_get_pivot(int stack_size, int part);
void	ft_push_median(t_stack_info *stack, int *pivot);
void	ft_push_sort(t_stack_info *stack);
void	ft_rb_rrb_pa(t_stack_info *stack, int index, int rotate);
void	ft_push_rest(t_stack_info *stack, int pivot);

/*
sort_utils_3.c
*/
int		ft_push_less(t_stack_info *stack, int pivot);
int		ft_find_top_less(t_list *lst, t_list *lst_top, int pivot);
int		ft_find_last_less(t_list *lst, t_list *lst_top, int pivot);

#endif
