/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 21:11:03 by wlow              #+#    #+#             */
/*   Updated: 2021/08/05 09:23:29 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_trim(char const *s1, char const *set, int start, int increment);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_trim;
	size_t	s1_len;
	size_t	i_first;
	size_t	i_last;
	int		i;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	i_first = n_trim(s1, set, 0, 1);
	if (i_first == s1_len)
		return (ft_strdup(""));
	i_last = n_trim(s1, set, --s1_len, -1);
	s_trim = (char *) malloc(sizeof(*s_trim) * (++i_last - i_first + 1));
	if (!s_trim)
		return (NULL);
	i = 0;
	while (i_first < i_last)
		s_trim[i++] = s1[i_first++];
	s_trim[i] = '\0';
	return (s_trim);
}

static int	n_trim(char const *s1, char const *set, int start, int increment)
{
	size_t			set_len;
	int				i_s1;
	unsigned int	i_set;
	int				sign;

	set_len = ft_strlen(set);
	i_s1 = start;
	sign = 1;
	while (sign && set_len)
	{
		i_set = -1;
		while (++i_set < set_len)
		{
			if (s1[i_s1] == set[i_set])
			{
				sign = 1;
				i_s1 = i_s1 + increment;
				i_set = -1;
			}
			sign = 0;
		}
	}
	return (i_s1);
}
