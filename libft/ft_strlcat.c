/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 22:54:05 by wlow              #+#    #+#             */
/*   Updated: 2021/08/05 09:23:03 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (dest[len])
		len++;
	i = 0;
	if (len < size)
	{
		while (i < size - len - 1 && src[i])
		{
			dest[len + i] = src[i];
			i++;
		}
		dest[len + i] = '\0';
	}
	while (src[i])
		i++;
	if (size < len)
		return (i + size);
	return (i + len);
}
