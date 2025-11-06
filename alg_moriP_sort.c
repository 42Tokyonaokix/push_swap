/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_moriP_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 07:42:46 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 17:11:42 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(int i1, int i2)
{
	if (i1 >= i2)
		return (i2);
	return (i1);
}

int	calc_cost(t_node *sa, t_node *sb, int na)
{
	int	rna;
	int	rnb;
	int	nb;

	nb = rotate_to_insert(sb, locate_to_index(sa, na));
	rna = ft_listsize(sa) - na;
	rnb = ft_listsize(sb) - nb;
	if (na == 0 && nb == 0)
		return (0);
	if (na <= rna)
	{
		if (na >= nb)
			return (na);
		else if (na < nb)
			return (min(nb, rnb + na));
	}
	else if (na > rna)
	{
		if (rna >= rnb)
			return (rna);
		else if (rna < rnb)
			return (min(rnb, nb + rna));
	}
	return (INT_MIN);
}

t_node	*node(t_node *stk, unsigned int index)
{
	t_node	*tmp;

	if (stk->i == index)
		return (stk);
	tmp = stk->n;
	while (tmp != stk)
	{
		if (tmp->i == index)
			return ((tmp));
		tmp = tmp->n;
	}
	return (NULL);
}

int	find_cheapest(t_node *sa, t_node *sb)
{
	int		na;
	int		la;
	int		tmp;
	int		cheap;
	int		cna;

	na = 0;
	la = ft_listsize(sa);
	cheap = INT_MAX;
	cna = INT_MAX;
	if (!sa)
		return (INT_MIN);
	while (na < la)
	{
		tmp = calc_cost(sa, sb, na);
		if (tmp < cheap && !node(sa, locate_to_index(sa, na))->lis)
		{
			cheap = tmp;
			cna = na;
		}
		na++;
	}
	return (cna);
}
