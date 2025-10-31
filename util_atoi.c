/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:48:08 by natakaha          #+#    #+#             */
/*   Updated: 2025/10/31 12:50:52 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atol_check(char *nptr)
{
	int	count;

	count = 0;
	if (!nptr || !*nptr)
		return (false);
	while (*nptr)
	{
		while (*nptr == ' ' || (9 <= *nptr && *nptr <= 13))
			nptr++;
		if (*nptr == '+' || *nptr == '-')
			nptr++;
		if ('0' > *nptr || *nptr > '9')
			return (false);
		else
			count++;
		while ('0' <= *nptr && *nptr <= '9')
			nptr++;
		while (*nptr == ' ' || (9 <= *nptr && *nptr <= 13))
			nptr++;
	}
	return (count);
}

/* treat LONG_MIN as Errno*/

long long	ft_atol(char **str)
{
	long long		n;
	int				sign;

	sign = 1;
	if (!str || !*str || !**str)
		return (LONG_MIN);
	while (**str == ' ' || (9 <= **str && **str <= 13))
		(*str)++;
	if (**str == '+' || **str == '-' )
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	n = 0;
	while ('0' <= **str && **str <= '9')
	{
		n = n * 10 + (**str - '0');
		if (INT_MIN > n || INT_MAX < n)
			return (LONG_MIN);
		(*str)++;
	}
	while (**str == ' ' || (9 <= **str && **str <= 13))
		(*str)++;
	return (n * sign);
}

size_t	count_words(char const *s)
{
	size_t	i;
	size_t	count;
	char	c;

	count = 0;
	i = 0;
	c = ' ';
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			i++;
			count++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
