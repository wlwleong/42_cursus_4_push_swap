/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 19:56:36 by wlow              #+#    #+#             */
/*   Updated: 2021/08/05 09:22:19 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	size_t	i;
	char	*str;

	str = (char *)buf;
	i = -1;
	while (++i < count)
	{
		if (str[i] == (char)(c))
			return (&str[i]);
	}
	return (NULL);
}
