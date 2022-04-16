/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:50:55 by wlow              #+#    #+#             */
/*   Updated: 2021/08/05 09:23:24 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int c)
{
	int		i;

	i = 0;
	while (string[i])
		i++;
	if (string[i] == c)
		return ((char *)&string[i]);
	while (--i >= 0)
	{
		if (string[i] == (char)c)
			return ((char *)&string[i]);
	}
	return (NULL);
}
