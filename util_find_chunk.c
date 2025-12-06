/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_find_chunk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:14:56 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/07 20:18:45 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_chunk_front(t_node *sa, unsigned int start, unsigned int end)
{
	t_node	*tmp;
	int		count;

	if (!sa)
		return (INT_MIN);
	if (start <= sa->i && sa->i <= end && !sa->lis)
		return (0);
	tmp = sa->n;
	count = 1;
	while (tmp != sa)
	{
		if (start <= tmp->i && tmp->i <= end && !tmp->lis)
			return (count);
		count++;
		tmp = tmp->n;
	}
	return (INT_MIN);
}

int	find_chunk_back(t_node *sa, unsigned int start, unsigned int end)
{
	t_node	*tmp;
	int		count;

	if (!sa)
		return (INT_MIN);
	if (start <= sa->i && sa->i <= end && !sa->lis)
		return (0);
	tmp = sa->b;
	count = 1;
	while (tmp != sa)
	{
		if (start <= tmp->i && tmp->i <= end && !tmp->lis)
			return (count);
		count++;
		tmp = tmp->b;
	}
	return (INT_MIN);
}

int	find_chunk(t_node *sa, unsigned int start, unsigned int end)
{
	int	f;
	int	b;
	int	size;

	f = find_chunk_front(sa, start, end);
	b = find_chunk_back(sa, start, end);
	size = ft_listsize(sa);
	if (f == 0 || b == 0)
		return (0);
	if (f == INT_MIN || b == INT_MIN)
		return (INT_MIN);
	if (f < b)
		return (f);
	return (size - b);
}
