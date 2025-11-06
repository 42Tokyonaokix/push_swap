/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 07:29:53 by natakaha          #+#    #+#             */
/*   Updated: 2025/11/04 14:41:41 by natakaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*swap_ab_module(t_node *stk)
{
	t_node	*s0;
	t_node	*s2;
	t_node	*s3;

	if (!stk)
		return (NULL);
	if (ft_listsize(stk) <= 2)
		return (stk->n);
	s0 = stk->b;
	s2 = stk->n;
	s3 = s2->n;
	stk->b = s2;
	stk->n = s3;
	s2->b = s0;
	s2->n = stk;
	s0->n = s2;
	s3->b = stk;
	return (s2);
}

int	swap_sa(t_node **sa, t_node **sb)
{
	if (ft_listsize(*sa) < 2)
	{
		write(2, "opeError\n", 9);
		return (0);
	}
	*sa = swap_ab_module(*sa);
	(void)sa;
	(void)sb;
	write(1, "sa\n", 3);
	return (1);
}

int	swap_sb(t_node **sa, t_node **sb)
{
	if (ft_listsize(*sb) < 2)
	{
		write(2, "opeError\n", 9);
		return (0);
	}
	*sb = swap_ab_module(*sb);
	(void)sa;
	(void)sb;
	write(1, "sb\n", 3);
	return (1);
}

int	swap_ss(t_node **sa, t_node **sb)
{
	if (ft_listsize(*sa) < 2 && ft_listsize(*sb) < 2)
	{
		write(2, "opeError\n", 9);
		return (0);
	}
	if (ft_listsize(*sa) < 2)
		*sb = swap_ab_module(*sb);
	if (ft_listsize(*sb) < 2)
		*sb = swap_ab_module(*sa);
	else
	{
		*sa = swap_ab_module(*sa);
		*sb = swap_ab_module(*sb);
	}
	(void)sa;
	(void)sb;
	write(1, "ss\n", 3);
	return (1);
}
