/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:07:00 by wlwleong          #+#    #+#             */
/*   Updated: 2022/06/04 23:11:00 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"
#include <stdio.h>

char	*ft_strdup(const char *string)
{
	char	*s_dup;
	int		i;

	i = 0;
	while (string[i])
		i++;
	s_dup = (char *) malloc (sizeof(*s_dup) * (i + 1));
	if (!s_dup)
		return (NULL);
	i = 0;
	while (string[i])
	{
		s_dup[i] = string[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}

int	main(void)
{
	char	input_str[4];
	char	*str_to_save;
	char	*total_str[10];
	int		n_read;
	int		i;
	int		j;

	printf("insert commands below\n");
	i = 0;
	n_read = read(0, input_str, 4);
	while (n_read > 0)
	{
		printf("n_read = %d\n", n_read);
		str_to_save = malloc (sizeof(char) * n_read);
		j = -1;
		while (++j < n_read - 1)
			str_to_save[j] = input_str[j];
		str_to_save[j] = '\0';
		total_str[i++] = ft_strdup(str_to_save);
		free(str_to_save);
		n_read = read(0, input_str, 4);
	}
	j = -1;
	while (++j < i)
	{
		printf("string %d = %s\n", j, total_str[j]);
		free(total_str[j]);
	}
	return (0);
}
