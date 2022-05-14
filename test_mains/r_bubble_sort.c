/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_bubble_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:14:33 by wlwleong          #+#    #+#             */
/*   Updated: 2022/05/14 20:15:03 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_bubble_sort(int *array, int size);

int	main(int argc, char *argv[])
{
	t_stack_info	s;
	int				i;

	if (argc < 2)
		exit(-1);
	s.sa_size = argc - 1;
	s.array_input = malloc (sizeof(int) * (s.sa_size));
	s.array_sorted = malloc (sizeof(int) * (s.sa_size));
	if (!s.array_input || !s.array_sorted)
		exit(-2);
	i = 1;
	while (argc - i > 0)
	{
		s.array_input[i - 1] = ft_atoi(argv[i]);
		s.array_sorted[i - 1] = s.array_input[i - 1];
		i++;
	}
	if (!ft_bubble_sort(s.array_sorted, s.sa_size))
		printf("Array is already sorted!\n");
	i = 0;
	while (i < s.sa_size)
		printf("%d, ", s.array_sorted[i++]);
	printf("\n");
	free(s.array_input);
	free(s.array_sorted);
	return (0);
}

int	ft_bubble_sort(int *array, int size)
{
	int	swapped;
	int	i;
	int	temp;

	swapped = 0;
	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			swapped = 1;
		}
		i++;
	}
	if (swapped)
		ft_bubble_sort(array, size - 1);
	return (swapped);
}
