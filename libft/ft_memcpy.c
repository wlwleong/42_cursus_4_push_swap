/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 22:10:01 by wlow              #+#    #+#             */
/*   Updated: 2021/09/08 08:36:07 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (!dest || !src)
		return (dest);
	i = -1;
	while (++i < count)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}
