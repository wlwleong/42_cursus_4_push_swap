/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:06:44 by wlwleong          #+#    #+#             */
/*   Updated: 2022/04/20 22:21:15 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstclear_new(t_list **lst);

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_a_head;
	int		i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < argc)
	{
		if (i == 1)
		{
			stack_a = ft_lstnew(argv[i]);
			stack_a_head = stack_a;
		}
		else
			ft_lstadd_back(&stack_a, ft_lstnew(argv[i]));
		i++;
	}
	printf("stack_a size is %d\n", ft_lstsize(stack_a));
	i = 1;
	while (stack_a)
	{
		printf("Node %d = %s\n", i, (char *)stack_a->content);
		stack_a = stack_a->next;
		i++;
	}
	stack_a = stack_a_head;
	ft_lstclear_new(&stack_a);
	return (0);
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
