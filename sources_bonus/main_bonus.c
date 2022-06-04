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

#include "../includes/checker_bonus.h"
#include <stdio.h>

static int	*init_array(int size);
static int	ft_isnumeric(char *str);
static int	ft_isdup(int *arr, int size);
static void	ft_error(int type, int *array_input);

int	main(int argc, char *argv[])
{
	t_stack_info	stack;
	int				i;

	if (argc < 2)
		ft_error(1, NULL);
	else if (argc < 3 && !ft_isnumeric(argv[1]))
		ft_error(0, NULL);
	stack.sa_size = argc - 1;
	stack.array_input = init_array(stack.sa_size);
	i = 1;
	while (argc - i > 0)
	{
		if (!ft_isnumeric(argv[i]))
			ft_error(-1, stack.array_input);
		else if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
			ft_error(-1, stack.array_input);
		else
			stack.array_input[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (!ft_isdup(stack.array_input, stack.sa_size))
		ft_error(-1, stack.array_input);
	checker(&stack);
	return (0);
}

static int	*init_array(int size)
{
	int	*array;
	int	i;

	array = malloc (sizeof(int *) * size);
	if (!array)
		ft_error(-2, NULL);
	i = 0;
	while (i < size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}

static void	ft_error(int type, int *array_input)
{
	if (type == 0)
		write(2, "Error\n", 6);
	else if (type == -1)
	{
		write(2, "Error\n", 6);
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
	if (str[i] == 0)
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_isdup(int *arr, int size)
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
