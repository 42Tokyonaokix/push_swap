/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_info_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:07:32 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 17:15:18 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int	find_chunk_front(t_node *sa, unsigned int start, unsigned int end)
//{
//	t_node	*tmp;
//	int		count;

//	if (!sa)
//		return (INT_MIN);
//	if (start <= sa->i && sa->i <= end && !sa->lis)
//		return (0);
//	tmp = sa->n;
//	count = 1;
//	while (tmp != sa)
//	{
//		if (start <= tmp->i && tmp->i <= end && !tmp->lis)
//			return (count);
//		count++;
//		tmp = tmp->n;
//	}
//	return (INT_MIN);
//}

//int	find_chunk_back(t_node *sa, unsigned int start, unsigned int end)
//{
//	t_node	*tmp;
//	int		count;

//	if (!sa)
//		return (INT_MIN);
//	if (start <= sa->i && sa->i <= end && !sa->lis)
//		return (0);
//	tmp = sa->b;
//	count = 1;
//	while (tmp != sa)
//	{
//		if (start <= tmp->i && tmp->i <= end && !tmp->lis)
//			return (count);
//		count++;
//		tmp = tmp->b;
//	}
//	return (INT_MIN);
//}

//int	find_chunk(t_node *sa, unsigned int start, unsigned int end)
//{
//	int	f;
//	int	b;
//	int	size;

//	f = find_chunk_front(sa, start, end);
//	b = find_chunk_back(sa, start, end);
//	size = ft_listsize(sa);
//	if (f == 0 || b == 0)
//		return (0);
//	if (f == INT_MIN || b == INT_MIN)
//		return (INT_MIN);
//	if (f < b)
//		return (f);
//	return (size - b);
//}

/* non defined when locate is larger than listsize*/
static bool	insert_is_ok(t_node *stk, unsigned int ind)
{
	t_node			*back;

	back = stk->b;
	if (stk->i > back->i
		&& (ind > stk->i || back->i > ind))
		return (true);
	else if (back->i > ind && ind > stk->i)
		return (true);
	else
		return (false);
}

static bool	reverse_is_ok(t_node *stk, unsigned int ind)
{
	t_node			*back;

	back = stk->b;
	if (stk->i < back->i
		&& (ind < stk->i || back->i < ind))
		return (true);
	else if (back->i < ind && ind < stk->i)
		return (true);
	else
		return (false);
}

int	rotate_to_insert(t_node *stk, unsigned int ind)
{
	t_node	*tmp;
	int		i;

	if (ft_listsize(stk) < 2)
		return (0);
	if (insert_is_ok(stk, ind))
		return (0);
	tmp = stk->n;
	i = 1;
	while (tmp != stk)
	{
		if (insert_is_ok(tmp, ind))
			break ;
		tmp = tmp->n;
		i++;
	}
	return (i);
}

int	rotate_to_reverse(t_node *stk, unsigned int ind)
{
	t_node	*tmp;
	int		i;

	if (ft_listsize(stk) < 2)
		return (0);
	if (reverse_is_ok(stk, ind))
		return (0);
	tmp = stk->n;
	i = 1;
	while (tmp != stk)
	{
		if (reverse_is_ok(tmp, ind))
			break ;
		tmp = tmp->n;
		i++;
	}
	return (i);
}

unsigned int	find_largest(t_node *stk)
{
	t_node				*tmp;
	unsigned int		max;

	if (!stk)
		return (0);
	tmp = stk->n;
	max = stk->i;
	while (tmp != stk)
	{
		if (tmp->i > max)
			max = tmp->i;
		tmp = tmp->n;
	}
	return (max);
}
