/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 22:06:28 by wlow              #+#    #+#             */
/*   Updated: 2021/08/05 09:22:02 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(size * num);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (size * num))
		ptr[i++] = 0;
	return (ptr);
}
