/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:15:09 by wlow              #+#    #+#             */
/*   Updated: 2021/08/04 00:00:50 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_n_digit(int num);

char	*ft_itoa(int n)
{
	char			*str;
	int				n_digit;
	unsigned int	number;

	n_digit = get_n_digit(n);
	str = (char *) malloc (sizeof(*str) * (n_digit + 1));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		number = (unsigned int)(-n);
	}
	else
		number = (unsigned int)(n);
	str[n_digit] = '\0';
	while (number > 0)
	{
		str[--n_digit] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}

static int	get_n_digit(int num)
{
	int				n;
	unsigned int	number;

	n = 0;
	if (num <= 0)
		n = 1;
	if (num < 0)
		number = (unsigned int)(-num);
	else
		number = (unsigned int)(num);
	while (number > 0)
	{
		number /= 10;
		n++;
	}
	return (n);
}
