/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 20:27:44 by wlow              #+#    #+#             */
/*   Updated: 2021/08/05 09:23:00 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	len;
	int				i;

	if (!s1 || !s2)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	i = 0;
	while (s2[i++])
		len++;
	str = (char *) malloc (sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[i])
		str[len++] = s1[i++];
	i = 0;
	while (s2[i])
		str[len++] = s2[i++];
	str[len] = '\0';
	return (str);
}
