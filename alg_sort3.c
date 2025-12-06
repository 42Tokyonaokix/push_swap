/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_sort3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 21:22:38 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/07 20:18:24 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort3_module(t_node **sa, t_node **sb)
{
	int	loc;
	int	count;

	loc = find_chunk(*sa, 1, 1);
	count = 0;
	if (loc == 0)
	{
		count += rotate_rra(sa, sb);
		count += swap_sa(sa, sb);
	}
	else if (loc == 1)
		count += swap_sa(sa, sb);
	else
	{
		count += swap_sa(sa, sb);
		count += rotate_rra(sa, sb);
	}
	return (count);
}

bool	is_r_sorted(t_node *sa)
{
	t_node				*tmp;
	unsigned int		index;
	int					count;
	unsigned int		n;
	unsigned int		size;

	tmp = sa->n;
	index = sa->i;
	count = 0;
	n = 0;
	size = ft_listsize(sa);
	while (n < size)
	{
		if (tmp->i < index)
			count++;
		index = tmp->i;
		tmp = tmp->n;
		n++;
	}
	if (count <= 1)
		return (true);
	return (false);
}

int	mindex(t_node *sa)
{
	t_node				*tmp;
	unsigned int		min;

	tmp = sa->n;
	min = sa->i;
	while (tmp != sa)
	{
		if (min > tmp->i)
			min = tmp->i;
		tmp = tmp->n;
	}
	return ((int)min);
}

int	sort3(t_node **sa, t_node **sb)
{
	int		count;
	t_node	*sc;

	sc = NULL;
	if (is_r_sorted(*sa))
	{
		if (find_chunk(*sa, mindex(*sa), mindex(*sa)) == 1)
			count = rotate_ra(sa, sb);
		else if (find_chunk(*sa, mindex(*sa), mindex(*sa)) == 2)
			count = rotate_rra(sa, sb);
		else
			count = 0;
	}
	else
		count = sort3_module(sa, &sc);
	(void)sb;
	return (count);
}

int	sort5(t_node **sa, t_node **sb)
{
	int	count;

	count = 0;
	while (ft_listsize(*sa) > 3)
		push_b(sa, sb);
	count += sort3(sa, sb);
	count += whole_reverse(sa, sb);
	return (count);
}
