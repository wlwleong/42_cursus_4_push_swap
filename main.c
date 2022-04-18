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

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	i = 1;
	while (argc - i > 0)
	{
		printf("argv[%d] = ", i);
		if (!check_numeric_param(argv[i]))
			printf("Error\n");
		else if (ft_atoi(argv[i]) < INT_MIN || ft_atoi(argv[i]) > INT_MAX)
			printf("Error - argv[%d] = %ld\n", i, ft_atoi(argv[i]));
		else
			printf("%ld\n", ft_atoi(argv[i]));
		i++;
	}
	return (0);
}

static int	check_numeric_param(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}