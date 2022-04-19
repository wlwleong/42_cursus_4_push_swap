/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:06:44 by wlwleong          #+#    #+#             */
/*   Updated: 2022/04/19 14:07:16 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content);

int	main(void)
{
	t_list	*stack_a;
	int		num;

	num = 42;
	stack_a = ft_lstnew(&num);
	printf("first node = %ld\n", (long int)stack_a->content);
	return (0);
}
