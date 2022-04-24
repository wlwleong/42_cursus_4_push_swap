/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:39:30 by wlwleong          #+#    #+#             */
/*   Updated: 2022/04/23 14:40:21 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

char    *ft_check_dup(int *arr, int size)
{
    unsigned int    *arr_table;
    unsigned int    i;

    arr_table = ft_calloc(UINT_MAX, sizeof(unsigned int));
    if (!arr_table)
    {
        perror("arr_table");
        exit(EXIT_FAILURE);
    }
    i = 0;
    while (i < (unsigned int) size)
    {
        printf("i = %u   arr[i] = %u   arr_table[0] = %u\n", i, (unsigned int) arr[i], arr_table[1]);
        if (arr_table[(unsigned int) arr[i] - 1] == 0)
        {
            printf("Assigning...\n");
            arr_table[(unsigned int) arr[i] - 1]++;
            printf("Assigned!\n");
        }
        else
            return ("duplicate");
        i++;
    }
    return (NULL);
}

int	main(int argc, char *argv[])
{
    int		*stack_a_array;
	int		i;

	if (argc < 2)
		exit(EXIT_FAILURE);
	stack_a_array = malloc (sizeof(int) * (argc - 1));
	if (!stack_a_array)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < argc - 1)
	{
		stack_a_array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
    printf("Works until here...\n");
    if (ft_check_dup(stack_a_array, argc - 1) != NULL)
    {
        printf("Duplicate detected!\n");
        exit(EXIT_FAILURE);
    }
	return (0);
}

