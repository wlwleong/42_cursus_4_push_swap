/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:18:00 by wlow              #+#    #+#             */
/*   Updated: 2021/09/08 21:06:16 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_get_size(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_get_size(s, start, len);
	sub_s = (char *) malloc (sizeof(*sub_s) * (size + 1));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (i < size)
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

static unsigned int	ft_get_size(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	index;

	str_len = 0;
	index = 0;
	while (s[index++])
		str_len++;
	if (len > str_len)
		len = str_len;
	if (len == 0 || start > str_len)
		return (0);
	else if (start == str_len)
		return (1);
	else if (start + len > str_len)
		return (str_len - start);
	return (len);
}
