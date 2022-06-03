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

static int	**init_array(int size);
static int	ft_isnumeric(char *str);
static int	ft_isdup(int **arr, int size);
static void	ft_error(int type, int **array_input, int size);

int	main(int argc, char *argv[])
{
	t_stack_info	stack;
	int				i;

	if (argc < 3)
		ft_error(0, NULL, 0);
	stack.sa_size = argc - 1;
	stack.array_input = init_array(stack.sa_size);
	i = 1;
	while (argc - i > 0)
	{
		if (!ft_isnumeric(argv[i]))
			ft_error(-1, stack.array_input, stack.sa_size);
		else if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
			ft_error(-1, stack.array_input, stack.sa_size);
		else
			stack.array_input[i - 1][0] = ft_atoi(argv[i]);
		i++;
	}
	if (!ft_isdup(stack.array_input, stack.sa_size))
		ft_error(-1, stack.array_input, stack.sa_size);
	push_swap(&stack);
	return (0);
}

static int	**init_array(int size)
{
	int	**array;
	int	i;

	array = malloc (sizeof(int *) * size);
	if (!array)
		ft_error(-2, NULL, 0);
	i = 0;
	while (i < size)
	{
		array[i] = malloc (sizeof(int) * 2);
		if (!array[i])
			ft_error(-2, NULL, 0);
		array[i][0] = 0;
		array[i][1] = 0;
		i++;
	}
	return (array);
}

static void	ft_error(int type, int **array_input, int size)
{
	int	i;

	if (type == -1)
	{
		write(2, "Error\n", 6);
		i = 0;
		while (i < size)
			free(array_input[i++]);
		free(array_input);
	}
	else if (type == -2)
		ft_putstr_fd("malloc Error\n", 1);
	exit(EXIT_FAILURE);
}

static int	ft_isnumeric(char *str)
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

static int	ft_isdup(int **arr, int size)
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
				if (arr[i][0] == arr[j][0])
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
