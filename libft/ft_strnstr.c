/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:31:29 by wlow              #+#    #+#             */
/*   Updated: 2021/08/05 09:23:20 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_h;
	size_t	i_n;

	i_h = 0;
	while (i_h < len && haystack[i_h])
	{
		i_n = 0;
		while (needle[i_n] == haystack[i_h + i_n] && i_h + i_n < len
			&& needle[i_n])
			i_n++;
		if (needle[i_n] == '\0')
			return ((char *)&haystack[i_h]);
		i_h++;
	}
	if (needle[0] == '\0')
		return ((char *)&haystack[i_h]);
	return (NULL);
}
