/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 19:46:38 by wlow              #+#    #+#             */
/*   Updated: 2021/08/05 09:23:13 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	new_s = (char *) malloc (sizeof(*new_s) * (len + 1));
	if (!new_s)
		return (NULL);
	i = -1;
	while (s[++i])
		new_s[i] = f(i, s[i]);
	new_s[i] = '\0';
	return (new_s);
}
