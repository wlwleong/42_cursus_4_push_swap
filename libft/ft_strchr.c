/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:50:55 by wlow              #+#    #+#             */
/*   Updated: 2021/08/05 09:22:50 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	int		i;

	i = -1;
	while (string[++i])
	{
		if (string[i] == (char)(c))
			return ((char *)(&string[i]));
	}
	if (string[i] == c)
		return ((char *)(&string[i]));
	return (NULL);
}
