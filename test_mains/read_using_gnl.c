/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_using_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:35:01 by wlwleong          #+#    #+#             */
/*   Updated: 2022/06/05 15:36:20 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*temp;
	int	i;

	temp = get_next_line(0);
	i = 0;
	while (temp)
	{
		printf("string %d = %s", i++, temp);
		free(temp);
		temp = get_next_line(0);
	}
	return (0);
}
