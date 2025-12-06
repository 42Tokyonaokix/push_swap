/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_perth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 05:48:08 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/05 21:08:31 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_number(char *str)
{
	int	n;

	n = 0;
	if (!str || !*str)
		return (false);
	while (*str)
	{
		while (*str == ' ' || (9 <= *str && *str <= 13))
			str++;
		if (*str == '+' || *str == '-')
			str++;
		if ('0' > *str || *str > '9')
			return (false);
		else
			n++;
		while ('0' <= *str && *str <= '9')
			str++;
		while (*str == ' ' || (9 <= *str && *str <= 13))
			str++;
	}
	return (n);
}

/* treat LONG_MIN as Errno*/

long long	ft_atol(char **str)
{
	long long		num;
	int				sign;

	if (!str || !*str || !**str)
		return (LONG_MIN);
	while (**str == ' ' || (9 <= **str && **str <= 13))
		(*str)++;
	sign = 1;
	if (**str == '+' || **str == '-' )
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	num = 0;
	while ('0' <= **str && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		if ((sign > 0 && INT_MAX < num) || (sign < 0 && INT_MAX < num - 1))
			return (LONG_MIN);
		(*str)++;
	}
	while (**str == ' ' || (9 <= **str && **str <= 13))
		(*str)++;
	return (num * sign);
}

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

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
		return (INT_MIN);
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
