/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 23:22:23 by wlow              #+#    #+#             */
/*   Updated: 2021/08/05 09:22:54 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
