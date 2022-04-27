/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:39:26 by wlwleong          #+#    #+#             */
/*   Updated: 2022/04/15 03:40:19 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_numeric_param(char *str);
static int	check_duplicate(int *arr, int size);
static void	ft_error(int type, void *ptr);

int	main(int argc, char *argv[])
{
	t_stack_info	stack_a;
	int				i;

	if (argc < 2)
		ft_error(0, NULL);
	stack_a.size = argc - 1;
	stack_a.array = malloc (sizeof(int) * (stack_a.size));
	if (!stack_a.array)
		ft_error(-2, NULL);
	i = 1;
	while (argc - i > 0)
	{
		if (!check_numeric_param(argv[i]))
			ft_error(-1, stack_a.array);
		else if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
			ft_error(-1, stack_a.array);
		else
			stack_a.array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (!check_duplicate(stack_a.array, stack_a.size))
		ft_error(-1, stack_a.array);
	push_swap(stack_a);
	free(stack_a.array);
	return (0);
}

static void	ft_error(int type, void *ptr)
{
	if (type == -1)
	{
		write(1, "Error\n", 6);
		free(ptr);
	}
	else if (type == -2)
		write(1, "malloc Error\n", 13);
	exit(EXIT_FAILURE);
}

static int	check_numeric_param(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i != j)
			{
				if (arr[i] == arr[j])
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
