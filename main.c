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
#include <stdio.h>

static int	check_numeric_param(char *str);
static int	check_duplicate(int *arr, int size);
static void	ft_error(void);

int	main(int argc, char *argv[])
{
	int		*stack_a_array;
	int		i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_a_array = malloc (sizeof(int) * (argc - 1));
	if (!stack_a_array)
	{
		perror("stack_a_array");
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (argc - i > 0)
	{
		if (!check_numeric_param(argv[i]))
			ft_error();
		else if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
			ft_error();
		else
			stack_a_array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (check_duplicate(stack_a_array, argc - 1))
		printf("All checks OK!\n");
	else
		ft_error();
	free(stack_a_array);
	return (0);
}

static void	ft_error(void)
{
	write(1, "Error\n", 6);
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