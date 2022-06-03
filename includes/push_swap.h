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

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# define TOP 0
# define LAST 1

typedef struct s_stack_info
{
	int		**array_input;
	int		*array_sorted;
	int		size;
	int		min_int;
	int		max_int;
	int		sa_size;
	t_list	*sa_top;
	t_list	*sa;
	int		*sa_last;
	int		sb_size;
	t_list	*sb_top;
	t_list	*sb;
	int		*sb_last;
	int		n_top_sorted;
	int		n_operations;
}				t_stack_info;

/*
push_swap.c
*/
void	push_swap(t_stack_info *sa_info);

/*
push_swap_utils.c
*/
void	free_stack_array(t_stack_info *stack);
void	ft_print_arr(int **array, int size);
void	ft_print_lst(t_list *lst);

/*
sort_small.c
*/
void	sort_small(t_stack_info *stack);

/*
sort_medium.c
*/
void	sort_medium(t_stack_info *stack);

/*
sort_medium_utils.c
*/
void	ft_push_median(t_stack_info *stack, int *pivot);
void	ft_push_sort(t_stack_info *stack);
int		ft_find_min_index_sb(t_stack_info *stack);
int		ft_find_max_index_sb(t_stack_info *stack);
void	ft_push_rest(t_stack_info *stack, int pivot);

/*
sort_big.c
*/
void	sort_big(t_stack_info *stack, int part);

/*
sort_big_utils.c
*/
int		ft_push_less(t_stack_info *stack, int pivot, int median);
int		ft_find_less_sa(t_stack_info *stack, int *index, int pivot);
int		ft_find_top_less(t_list *lst, int pivot);
int		ft_find_last_less(t_list *lst, int pivot);
void	ft_push_back(t_stack_info *stack);

/*
sort_utils_1.c
*/
void	sort_three_sa(t_stack_info *stack);
void	ft_push_b(t_stack_info *stack, int sorted_index);
void	ft_push_a(t_stack_info *stack, int sorted_index);
int		ft_get_index(t_list *lst, int num);

/*
sort_utils_2.c
*/
int		*ft_get_pivot(int stack_size, int part);
int		ft_find_min(t_list *lst, int stack_max);
int		ft_find_max(t_list *lst, int stack_min);
int		ft_smart_rotate(t_stack_info *stack, int *index1, int *index2);
void	ft_rb_rrb_pa(t_stack_info *stack, int index, int rotate);

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
