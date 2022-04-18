/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 21:28:00 by wlow              #+#    #+#             */
/*   Updated: 2022/04/19 03:05:12 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *str)
{
	long int	num;
	int			sign;
	int			i;

	i = 0;
	while (str[i] != '\0' && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}
